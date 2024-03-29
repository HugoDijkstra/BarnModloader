// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"


DWORD WINAPI MainThread(LPVOID param)
{
	uintptr_t modbase = (uintptr_t)GetModuleHandle(NULL);
	init();
	while (true);

	FreeLibraryAndExitThread((HMODULE)param, 0);
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		init();
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}


	return TRUE;
}

