#pragma once
//
// Made by iMoD1998
// V3.1
// https://gist.github.com/iMoD1998/4aa48d5c990535767a3fc3251efc0348
//

#pragma warning(push)
#pragma warning(disable : 4189)
#pragma warning(disable : 4701)

#include <xtl.h>
#include <stdint.h>

#define MASK_N_BITS(N) ((1 << (N)) - 1)

#define POWERPC_HI(X) ((X >> 16) & 0xFFFF)
#define POWERPC_LO(X) (X & 0xFFFF)

//
// PowerPC most significant bit is addressed as bit 0 in documentation.
//
#define POWERPC_BIT32(N) (31 - N)

//
// Opcode is bits 0-5.
// Allowing for op codes ranging from 0-63.
//
#define POWERPC_OPCODE(OP) (OP << 26)
#define POWERPC_OPCODE_ADDI POWERPC_OPCODE(14)
#define POWERPC_OPCODE_ADDIS POWERPC_OPCODE(15)
#define POWERPC_OPCODE_BC POWERPC_OPCODE(16)
#define POWERPC_OPCODE_B POWERPC_OPCODE(18)
#define POWERPC_OPCODE_BCCTR POWERPC_OPCODE(19)
#define POWERPC_OPCODE_ORI POWERPC_OPCODE(24)
#define POWERPC_OPCODE_EXTENDED POWERPC_OPCODE(31) // Use extended opcodes.
#define POWERPC_OPCODE_STW POWERPC_OPCODE(36)
#define POWERPC_OPCODE_LWZ POWERPC_OPCODE(32)
#define POWERPC_OPCODE_LD POWERPC_OPCODE(58)
#define POWERPC_OPCODE_STD POWERPC_OPCODE(62)
#define POWERPC_OPCODE_MASK POWERPC_OPCODE(63)

#define POWERPC_EXOPCODE(OP) (OP << 1)
#define POWERPC_EXOPCODE_BCCTR POWERPC_EXOPCODE(528)
#define POWERPC_EXOPCODE_MTSPR POWERPC_EXOPCODE(467)

//
// SPR field is encoded as two 5 bit bitfields.
//
#define POWERPC_SPR(SPR) (UINT32)(((SPR & 0x1F) << 5) | ((SPR >> 5) & 0x1F))

//
// instruction helpers.
//
// rD - destination register.
// rS - source register.
// rA/rB - Register inputs.
// SPR - Special purpose register.
// UIMM/SIMM - Unsigned/signed immediate.
//
#define POWERPC_ADDI(rD, rA, SIMM) (UINT32)(POWERPC_OPCODE_ADDI | (rD << POWERPC_BIT32(10)) | (rA << POWERPC_BIT32(15)) | SIMM)
#define POWERPC_ADDIS(rD, rA, SIMM) (UINT32)(POWERPC_OPCODE_ADDIS | (rD << POWERPC_BIT32(10)) | (rA << POWERPC_BIT32(15)) | SIMM)
#define POWERPC_LIS(rD, SIMM) POWERPC_ADDIS(rD, 0, SIMM) // Mnemonic for addis %rD, 0, SIMM
#define POWERPC_LI(rD, SIMM) POWERPC_ADDI(rD, 0, SIMM)   // Mnemonic for addi %rD, 0, SIMM
#define POWERPC_MTSPR(SPR, rS) (UINT32)(POWERPC_OPCODE_EXTENDED | (rS << POWERPC_BIT32(10)) | (POWERPC_SPR(SPR) << POWERPC_BIT32(20)) | POWERPC_EXOPCODE_MTSPR)
#define POWERPC_MTCTR(rS) POWERPC_MTSPR(9, rS) // Mnemonic for mtspr 9, rS
#define POWERPC_ORI(rS, rA, UIMM) (UINT32)(POWERPC_OPCODE_ORI | (rS << POWERPC_BIT32(10)) | (rA << POWERPC_BIT32(15)) | UIMM)
#define POWERPC_BCCTR(BO, BI, LK) (UINT32)(POWERPC_OPCODE_BCCTR | (BO << POWERPC_BIT32(10)) | (BI << POWERPC_BIT32(15)) | (LK & 1) | POWERPC_EXOPCODE_BCCTR)
#define POWERPC_STD(rS, DS, rA) (UINT32)(POWERPC_OPCODE_STD | (rS << POWERPC_BIT32(10)) | (rA << POWERPC_BIT32(15)) | ((INT16)DS & 0xFFFF))
#define POWERPC_LD(rS, DS, rA) (UINT32)(POWERPC_OPCODE_LD | (rS << POWERPC_BIT32(10)) | (rA << POWERPC_BIT32(15)) | ((INT16)DS & 0xFFFF))

//
// Branch related fields.
//
#define POWERPC_BRANCH_LINKED 1
#define POWERPC_BRANCH_ABSOLUTE 2
#define POWERPC_BRANCH_TYPE_MASK (POWERPC_BRANCH_LINKED | POWERPC_BRANCH_ABSOLUTE)

#define POWERPC_BRANCH_OPTIONS_ALWAYS (20)

class memory
{
public:
    template<typename T>
    static void write(void *p_destination, T data) 
    {
        if (!xbox::MmIsAddressValid(p_destination))
        {
            return;
        }
        
        *static_cast<T *>(p_destination) = data;
    }

    template<typename T>
    inline static void write(uintptr_t address, T data)
    {
        write<T>(reinterpret_cast<void *>(address), data);
    }

    template<typename T>
    static T read(void *p_source)
    {
        if (!xbox::MmIsAddressValid(p_source))
        {
            return 0;
        }

        return *static_cast<T *>(p_source);
    }

    template<typename T>
    inline static T read(uintptr_t address)
    {
        return read<T>(reinterpret_cast<void *>(address));
    }
};

class detour
{
public:
    detour() {}

    //
    // hook_source - The function that will be hooked.
    // hook_target - The function that the hook will be redirected to.
    //
    detour(
        _Inout_ void *hook_source,
        _In_ const void *hook_target)
        : hook_source(hook_source),
          hook_target(hook_target),
          trampoline_address(NULL),
          original_length(0)
    {
    }

    detour(
        uintptr_t hook_source,
        _In_ const void *hook_target)
        : hook_source(reinterpret_cast<void *>(hook_source)),
          hook_target(hook_target),
          trampoline_address(NULL),
          original_length(0)
    {
    }

    ~detour()
    {
        this->remove();
    }

    void create(_Inout_ void *hook_source, _In_ const void *hook_target)
    {
        this->hook_source = hook_source;
        this->hook_target = hook_target;
        this->trampoline_address = NULL;
        this->original_length = 0;
        this->install();
    }

    void create(uintptr_t hook_source, _In_ const void *hook_target)
    {
        this->create(reinterpret_cast<void *>(hook_source), hook_target);
    }

    //
    // Writes an unconditional branch to the destination address that will branch to the target address.
    //
    // destination - Where the branch will be written to.
    // branch_target - The address the branch will jump to.
    // linked - Branch is a call or a jump? aka bl or b
    // preserve_register - Preserve the register clobbered after loading the branch address.
    //
    static SIZE_T write_far_branch(
        _Out_ void *destination,
        _In_ const void *branch_target,
        _In_ bool linked = true,
        _In_ bool preserve_register = false)
    {
        return detour::write_far_branch_ex(destination, branch_target, linked, preserve_register);
    }

    //
    // Writes both conditional and unconditional branches using the count register to the destination address that will branch to the target address.
    //
    // destination - Where the branch will be written to.
    // branch_target - The address the branch will jump to.
    // linked - Branch is a call or a jump? aka bl or b
    // preserve_register - Preserve the register clobbered after loading the branch address.
    // branch_options - Options for determining when a branch to be followed.
    // condition_register_bit - The bit of the condition register to compare.
    // register_index - Register to use when loading the destination address into the count register.
    //
    static SIZE_T write_far_branch_ex(
        _Out_ void *destination,
        _In_ const void *branch_target,
        _In_ bool linked = false,
        _In_ bool preserve_register = false,
        _In_ UINT32 branch_options = POWERPC_BRANCH_OPTIONS_ALWAYS,
        _In_ BYTE condition_register_bit = 0,
        _In_ BYTE register_index = 0)
    {
        const UINT32 branch_far_asm[] = {
            POWERPC_LIS(register_index, POWERPC_HI((UINT32)branch_target)),                // lis   %rX, branch_target@hi
            POWERPC_ORI(register_index, register_index, POWERPC_LO((UINT32)branch_target)), // ori   %rX, %rX, branch_target@lo
            POWERPC_MTCTR(register_index),                                                // mtctr %rX
            POWERPC_BCCTR(branch_options, condition_register_bit, linked)                   // bcctr (bcctr 20, 0 == bctr)
        };

        const UINT32 branch_far_asm_preserve[] = {
            POWERPC_STD(register_index, -0x30, 1),                                        // std   %rX, -0x30(%r1)
            POWERPC_LIS(register_index, POWERPC_HI((UINT32)branch_target)),                // lis   %rX, branch_target@hi
            POWERPC_ORI(register_index, register_index, POWERPC_LO((UINT32)branch_target)), // ori   %rX, %rX, branch_target@lo
            POWERPC_MTCTR(register_index),                                                // mtctr %rX
            POWERPC_LD(register_index, -0x30, 1),                                         // lwz   %rX, -0x30(%r1)
            POWERPC_BCCTR(branch_options, condition_register_bit, linked)                   // bcctr (bcctr 20, 0 == bctr)
        };

        const auto branch_asm = preserve_register ? branch_far_asm_preserve : branch_far_asm;
        const auto branch_asm_size = preserve_register ? sizeof(branch_far_asm_preserve) : sizeof(branch_far_asm);

        if (destination)
            memcpy(destination, branch_asm, branch_asm_size);

        return branch_asm_size;
    }

    //
    // Copies and fixes relative branch instructions to a new location.
    //
    // destination - Where to write the new branch.
    // source - Address to the instruction that is being relocated.
    //
    static SIZE_T relocate_branch(
        _Out_ UINT32 *destination,
        _In_ const UINT32 *source)
    {
        const auto instruction = *source;
        const auto instruction_address = (UINT32)source;

        //
        // Absolute branches dont need to be handled.
        //
        if (instruction & POWERPC_BRANCH_ABSOLUTE)
        {
            *destination = instruction;

            return 4;
        }

        INT32 branch_offset_bit_size;
        INT32 branch_offset_bit_base;
        UINT32 branch_options;
        BYTE condition_register_bit;

        switch (instruction & POWERPC_OPCODE_MASK)
        {
        //
        // B - Branch
        // [Opcode]            [Address]           [Absolute] [linked]
        //   0-5                 6-29                  30        31
        //
        // Example
        //  010010   0000 0000 0000 0000 0000 0001      0         0
        //
        case POWERPC_OPCODE_B:
            branch_offset_bit_size = 24;
            branch_offset_bit_base = 2;
            branch_options = POWERPC_BRANCH_OPTIONS_ALWAYS;
            condition_register_bit = 0;
            break;

        //
        // BC - Branch Conditional
        // [Opcode]   [Branch Options]     [Condition Register]         [Address]      [Absolute] [linked]
        //   0-5           6-10                    11-15                  16-29            30        31
        //
        // Example
        //  010000        00100                    00001             00 0000 0000 0001      0         0
        //
        case POWERPC_OPCODE_BC:
            branch_offset_bit_size = 14;
            branch_offset_bit_base = 2;
            branch_options = (instruction >> POWERPC_BIT32(10)) & MASK_N_BITS(5);
            condition_register_bit = (instruction >> POWERPC_BIT32(15)) & MASK_N_BITS(5);
            break;
        }

        //
        // Even though the address part of the instruction begins from bit 29 in the case of bc and b.
        // The value of the first bit is 4 as all addresses are aligned to for 4 for code therefore,
        // the branch offset can be caluclated by anding in place and removing any suffix bits such as the
        // link register or absolute flags.
        //
        INT32 branch_offset = instruction & (MASK_N_BITS(branch_offset_bit_size) << branch_offset_bit_base);

        //
        // Check if the MSB of the offset is set.
        //
        if (branch_offset >> ((branch_offset_bit_size + branch_offset_bit_base) - 1))
        {
            //
            // Add the nessasary bits to our integer to make it negative.
            //
            branch_offset |= ~MASK_N_BITS(branch_offset_bit_size + branch_offset_bit_base);
        }

        const auto branch_address = (void *)(INT32)(instruction_address + branch_offset);

        return detour::write_far_branch_ex(destination, branch_address, instruction & POWERPC_BRANCH_LINKED, true, branch_options, condition_register_bit);
    }

    //
    // Copies an instruction enusuring things such as PC relative offsets are fixed.
    //
    // destination - Where to write the new instruction(s).
    // source - Address to the instruction that is being copied.
    //
    static SIZE_T copy_instruction(
        _Out_ UINT32 *destination,
        _In_ const UINT32 *source)
    {
        const auto instruction = *source;
        const auto instruction_address = (UINT32)source;

        switch (instruction & POWERPC_OPCODE_MASK)
        {
        case POWERPC_OPCODE_B:  // B BL BA BLA
        case POWERPC_OPCODE_BC: // BEQ BNE BLT BGE
            return detour::relocate_branch(destination, source);
        default:
            *destination = instruction;
            return 4;
        }
    }

    bool install()
    {
        //
        // Check if we are already hooked.
        //
        if (this->original_length != 0)
            return false;

        const auto hook_size = detour::write_far_branch(NULL, this->hook_target, false, false);

        //
        // Save the original instructions for unhooking later on.
        //
        memcpy(this->original_instructions, this->hook_source, hook_size);

        this->original_length = hook_size;

        //
        // Create trampoline and copy and fix instructions to the trampoline.
        //
        this->trampoline_address = &detour::trampoline_buffer[detour::trampoline_size];

        for (SIZE_T i = 0; i < (hook_size / 4); i++)
        {
            const auto instruction_ptr = (UINT32 *)((UINT32)this->hook_source + (i * 4));

            detour::trampoline_size += detour::copy_instruction((UINT32 *)&detour::trampoline_buffer[detour::trampoline_size], instruction_ptr);
        }

        //
        // Trampoline branches back to the original function after the branch we used to hook.
        //
        const auto after_branch_address = (void *)((UINT32)this->hook_source + hook_size);

        detour::trampoline_size += detour::write_far_branch(&detour::trampoline_buffer[detour::trampoline_size], after_branch_address, false, true);

        //
        // Finally write the branch to the function that we are hooking.
        //
        detour::write_far_branch(this->hook_source, this->hook_target, false, false);

        return true;
    }

    bool remove()
    {
        if (this->hook_source && this->original_length)
        {
            memcpy(this->hook_source, this->original_instructions, this->original_length);

            this->original_length = 0;
            this->hook_source = NULL;

            return true;
        }

        return false;
    }

    template <typename T>
    T get_original() const
    {
        return T(this->trampoline_address);
    }

private:
    const void *hook_target;        // The funtion we are pointing the hook to.
    void *hook_source;              // The function we are hooking.
    BYTE *trampoline_address;       // Pointer to the trampoline for ttrampoline_bufferhis detour.
    BYTE original_instructions[30]; // Any bytes overwritten by the hook.
    SIZE_T original_length;         // The amount of bytes overwritten by the hook.

    //
    // Shared
    //
    static BYTE trampoline_buffer[200 * 20];
    static SIZE_T trampoline_size;
};

#pragma warning(pop)
