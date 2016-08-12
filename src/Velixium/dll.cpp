#include "dll.h"

Process engine;

void WINAPI Main(LPVOID)
{
	proxy = new Proxy();
	while (!proxy->GetModule(L"x3.xem"))
		Sleep(250);

	logger.log("Velixium ready");

	while (1)
	{

		Sleep(50);
	}
}

bool WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		if (NT_ERROR(engine.Attach(GetCurrentProcessId())))
		{
			MessageBoxA(NULL, "Unable to attach to Engine.exe!", "Error", MB_OK);
			exit(0);
		}
		else engine.threads().CreateNew((ptr_t)Main, NULL);
	}

	return true;
}