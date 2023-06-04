#include "DllMain.h"

DWORD WINAPI MyThread(HINSTANCE hinstDLL)
{
	FILE* fConsole = nullptr;
	BOOL consoleAllocated = AllocConsole();

	if (consoleAllocated)
	{
		fConsole = freopen("CONOUT$", "w", stdout);
	}

	DWORD handle = (DWORD)GetModuleHandleA("Borderlands2.exe");
	DWORD addr1 = *(DWORD*)(handle + 0x015E94AC);
	CPlayer* player = (CPlayer*)(addr1);
	printf("%p\n", player);


	while (!GetAsyncKeyState(VK_DELETE))
	{
		if (GetAsyncKeyState(VK_INSERT))
		{
			printf("%f\n", player->fHealth);
		}

		Sleep(1);
	}

	if (consoleAllocated)
	{
		if (fConsole)
		{
			fclose(fConsole);
		}

		FreeConsole();
	}

	FreeLibraryAndExitThread(hinstDLL, 1);

	return 1;

}

BOOL WINAPI DllMain(HINSTANCE hInstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		HANDLE handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MyThread, hInstDLL, 0, 0);
		if (handle)
		{
			CloseHandle(handle);
		}
		break;
	}
	return true;
}