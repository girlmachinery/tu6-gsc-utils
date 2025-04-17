#pragma once
#include "stdinclude.h"

namespace game
{
	static auto Cbuf_AddText = reinterpret_cast<void(*)(int clientNum, const char* command)>(0x82275C60);
	static auto Scr_AddSourceBuffer = reinterpret_cast<const char*(*)(const char* filename, const char* ext_filename)>(0x8229F2C8);
	static auto Scr_RegisterFunction = reinterpret_cast<void(*)(void* func, const char* name)>(0x822963C0);
	static auto Common_GetFunction = reinterpret_cast<void(*)(const char** pName, int* type)>(0x8224D450);
	static auto Player_GetMethod = reinterpret_cast<void(*)(const char** pName)>(0x82224B30);
	static auto GetEntity = reinterpret_cast<gentity_s*(*)(scr_entref_t entref)>(0x8223F4D0);
	static auto GetClientState = reinterpret_cast<clientState_s*(*)(int entNum)>(0x82231F40);
	static auto Scr_GetNumParam = reinterpret_cast<unsigned int(*)()>(0x822ADC88);
	static auto Scr_GetType = reinterpret_cast<int(*)(unsigned int index)>(0x822B39F0);
	static auto Scr_GetInt = reinterpret_cast<int(*)(unsigned int index)>(0x822B2D70);
	static auto Scr_GetString = reinterpret_cast<char*(*)(unsigned int index)>(0x822B33A8);
	static auto Scr_GetFloat = reinterpret_cast<float(*)(unsigned int index)>(0x822B30D0);
	static auto Scr_GetVector = reinterpret_cast<void(*)(unsigned int index, float* value)>(0x822B35B8);
	static auto Scr_AddInt = reinterpret_cast<void(*)(int value)>(0x822ADD18);
	static auto Scr_AddString = reinterpret_cast<void(*)(const char* value)>(0x822ADFF0);
	static auto Scr_AddFloat = reinterpret_cast<void(*)(float value)>(0x822ADD98);
	static auto Scr_AddVector = reinterpret_cast<void(*)(float* value)>(0x822AE198);
	static auto Scr_NotifyNum = reinterpret_cast<void(*)(int entnum, unsigned int classnum, unsigned int stringValue, unsigned int paramcount)>(0x822AD550);
	static auto SL_GetString = reinterpret_cast<unsigned int(*)(const char *str, unsigned int user)>(0x822A2E18);

	static void set_gamertag(int index, std::string input)
    {
		auto ent = GetClientState(index);
		strcpy(ent->name, input.c_str());
    }

	static void set_clantag(int index, std::string input)
    {
		auto ent = GetClientState(index);
		strcpy(ent->clanAbbrev, input.c_str());

		if(input.empty())
		{
			Cbuf_AddText(index,"reset clanname");
			return;
		}

		std::string dvarString = "clanname " + input;
		Cbuf_AddText(index, dvarString.c_str());
    }

	static DWORD WINAPI XShowKeyboard(LPVOID sProp)
	{
		XKeyboardProperties *props = (XKeyboardProperties*)sProp;
		delete sProp;

		wchar_t wResultText[512];
		char buffer[512];

		wchar_t wDesc [20];
		mbstowcs(wDesc, props->desc, strlen(props->desc)+1);

		XOVERLAPPED Overlapped;
		ZeroMemory(&Overlapped, sizeof(Overlapped));
		XShowKeyboardUI(0, VKBD_DEFAULT, L"", L"Keyboard", wDesc, wResultText, props->lenght, &Overlapped);

		while (!XHasOverlappedIoCompleted(&Overlapped))
			Sleep(100);

		uint32_t overlappedResult = XGetOverlappedResult(&Overlapped, nullptr, TRUE);

		if (overlappedResult == ERROR_SUCCESS) 
		{ 
			wcstombs(buffer, wResultText, props->lenght);
			Scr_AddString(buffer);
			Scr_AddString(props->noti);
			Scr_NotifyNum(props->entity.entnum, props->entity.classnum, SL_GetString("keyboard_result", 0), 2);
		}

		return 0;
	}
}