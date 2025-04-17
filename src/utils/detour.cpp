#include "stdinclude.h"
#include "detour.h"

#pragma section(".text")
__declspec(allocate(".text")) BYTE detour::trampoline_buffer[200 * 20] = {};
SIZE_T detour::trampoline_size = 0;
