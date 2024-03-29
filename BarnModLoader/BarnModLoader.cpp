// BarnModLoader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


int main()
{

	PROCESS_INFORMATION p;
	STARTUPINFO startupInfo;
	ZeroMemory(&startupInfo, sizeof(startupInfo));
	ZeroMemory(&p, sizeof(p));
	startupInfo.cb = sizeof(startupInfo);

	HMODULE kernel32 = LoadLibrary(TEXT("kernel32"));
	typedef DWORD(WINAPI *SUSPENDTHREAD)(HANDLE hthread);
	SUSPENDTHREAD suspendThread = (SUSPENDTHREAD)GetProcAddress(kernel32, "SuspendThread");

	typedef DWORD(WINAPI *RESUMETHREAD)(HANDLE hthread);
	RESUMETHREAD resumeThread = (RESUMETHREAD)GetProcAddress(kernel32, "ResumeThread");
	LPWSTR args = (LPWSTR)("lookforme");
	CreateProcess(TEXT("Barnyard.exe"), args, NULL, NULL, TRUE, 0, NULL, NULL, &startupInfo, &p);
	suspendThread(p.hThread);

	int dllSize = 7;
	LPVOID myAlloc = VirtualAllocEx(p.hProcess, NULL, dllSize, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (myAlloc == NULL)
	{
		printf("No mem alloc");
		return -1;
	}

	int writtenBytes = WriteProcessMemory(p.hProcess, myAlloc, "mod.dll", dllSize, 0);
	if (!writtenBytes)
	{
		return -2;
	}

	std::cout << "PRINT THIS" << std::endl;


	DWORD dword;
	LPTHREAD_START_ROUTINE addrLoadLibrary = (LPTHREAD_START_ROUTINE)GetProcAddress(kernel32, "LoadLibraryA");
	HANDLE ThreadReturn = CreateRemoteThread(p.hProcess, NULL, 0, addrLoadLibrary, myAlloc, 0, &dword);
	HANDLE token;
	std::cout << OpenProcessToken(p.hProcess, TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token) << "	   ";
	std::cout << GetLastError() << std::endl;
	//SetPrivilege(token, SE_DEBUG_NAME, TRUE);
	std::cout << GetLastError() << std::endl;;


	std::cout << "Thread return: " << (int)ThreadReturn << std::endl;
	WaitForSingleObject(ThreadReturn, 1000);

	Sleep(1000);
	resumeThread(p.hThread);
	WaitForSingleObject(p.hProcess, INFINITE);
	CloseHandle(p.hProcess);
	CloseHandle(p.hThread);
}
