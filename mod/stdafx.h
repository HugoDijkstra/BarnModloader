// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#include <string>

#include <stdio.h>


#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#include <io.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <tlhelp32.h>
#include <vector>
// reference additional headers your program requires here


#define BASE_ADDR 0x00400000
extern "C" __declspec(dllexport) void __cdecl update();
extern "C" __declspec(dllexport) void init();
extern "C" __declspec(dllexport) void SetStartPointer(int* pointer);
extern "C" __declspec(dllexport) void WriteByteInt(LPVOID pointer, int i);
extern "C" __declspec(dllexport) void SetHandle(HANDLE procHandle);
extern "C" __declspec(dllexport) DWORD GetMainThreadId();
extern "C" __declspec(dllexport) bool SetPrivilege(HANDLE hToken, LPCTSTR Privilege, BOOL bEnablePrivilege);
extern "C" __declspec(dllexport) void Hijack();
extern "C" __declspec(dllexport) inline void __stdcall CapturedVector(void* __t, unsigned __s, int __n, void* (__thiscall*) (void*));
//extern "C" __declspec(dllexport) void CapturedVector(void* __t, unsigned __s, int __n, void* (__thiscall*) (void*));
extern "C" __declspec(dllexport) void __stdcall createVecItt(void *__t, unsigned __s, int __n, void * (__thiscall *__f) (void *));
__declspec(dllexport) std::vector<unsigned char> intToBytes(int paramInt);
