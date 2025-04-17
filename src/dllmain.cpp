#include "stdinclude.h"
#include "modules/init.h"

bool unload_plugin = false;
uint32_t MW2_TITLE_ID = 0x41560817;

void monitor_title_id()
{
	uint32_t current_title_id = 0;
	while (!unload_plugin)
	{
		uint32_t new_title_id = xbox::XamGetCurrentTitleId();
		if (new_title_id != current_title_id)
		{
			current_title_id = new_title_id;
			if (current_title_id == MW2_TITLE_ID && !strcmp(reinterpret_cast<char *>(0x82001F44), "multiplayer"))
			{
				Sleep(300);
				init::init();
			}
		}

		Sleep(100);
	}
}

int DllMain(HANDLE hModule, DWORD reason, void *pReserved)
{
	switch (reason)
	{
		case DLL_PROCESS_ATTACH:
			xbox::ExCreateThread(nullptr, 0, nullptr, nullptr, reinterpret_cast<PTHREAD_START_ROUTINE>(monitor_title_id), nullptr, 2);
		break;
		case DLL_PROCESS_DETACH:
			unload_plugin = true;
			init::unload();
			Sleep(250);
		break;
	}

	return TRUE;
}
