// mod.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

std::string testString = "SexyDog";


HANDLE H;


typedef void*(*GetCurPlayer)(void*, void*);
GetCurPlayer getCurPlayer = (GetCurPlayer)0x00621040;
typedef void(*VOIDFUNCTION)(void);
VOIDFUNCTION func = (VOIDFUNCTION)0x0059110A;
bool allocedConsole = false;

typedef std::vector<void*> CleanVector;
typedef int(*INTFUNCTION)(void);
typedef DWORD(*FUNCTIONCALL)();
FUNCTIONCALL fCall = (FUNCTIONCALL)0x00571D40;

INTFUNCTION getSomething = (INTFUNCTION)0x006B6240;

#pragma warning(disable:4996)
FUNCTIONCALL f = (FUNCTIONCALL)(0x006DF937);
FUNCTIONCALL com = (FUNCTIONCALL)0x006DF50C;

inline void __stdcall createVecItt(
	void *__t,
	unsigned __s,
	int __n,
	void * (__thiscall *__f) (void *))
{
	//	CapturedVector(__t, __s, __n, __f);
		/*__asm {
			call CapturedVector;
		}*/
	while (--__n >= 0) {
		(*(void(__thiscall *) (void *)) __f) (__t);
		__t = (char *)__t + __s;
	}

	//FUNCTIONCALL tempFunc0 = (FUNCTIONCALL)0x6DF8FC;
	//FUNCTIONCALL tempFunc1 = (FUNCTIONCALL)0x6DF472;
	//FUNCTIONCALL tempFunc2 = (FUNCTIONCALL)0x6DF937;

	//__asm 
	//{
	//	//push 12
	//	//push 0x741E38
	//	//call tempFunc0
	//	//and dword ptr ss : [ebp - 0x1C], 0
	//	//mov esi, dword ptr ss : [ebp + 0xC]
	//	//mov eax, esi
	//	//imul eax, dword ptr ss : [ebp + 10]
	//	//add dword ptr ss : [ebp + 8], eax
	//	//and dword ptr ss : [ebp - 4], 0
	//	//dec dword ptr ss : [ebp + 10]
	//	//js $+0xD0
	//	//sub dword ptr ss : [ebp + 8], esi
	//	//mov ecx, dword ptr ss : [ebp + 8]
	//	//call dword ptr ss : [ebp + 14]
	//	//jmp $-0x14
	//	//mov dword ptr ss : [ebp - 0x1C], 1
	//	//or dword ptr ss : [ebp - 4], 0xFFFFFFFF
	//	//call tempFunc1
	//	//call tempFunc2

	//	/*pop edi
	//	pop esi
	//	pop ebx
	//	pop ebp
	//	mov dword ptr ds : [0X007710E0 + 0x4], edi
	//	mov dword ptr ds : [0X007710E0 + 0x8], esi
	//	mov dword ptr ds : [0X007710E0 + 0xC], ebx
	//	mov dword ptr ds : [0X007710E0 + 0x10], ebp
	//	mov eax, dword ptr ss : [esp]
	//	mov dword ptr ds : [0X007710E0], eax
	//	add esp, 0x40;
	//	push dword ptr ds : [0X007710E0]
	//	push dword ptr ds : [0X007710E0 + 0x4]
	//	push dword ptr ds : [0X007710E0 + 0x8]
	//	push dword ptr ds : [0X007710E0 + 0xC]
	//	push dword ptr ds : [0X007710E0 + 0x10]
	//	call f
	//	call com*/
	//	
	//}
}


//__asm {
//	push eax
//	push ebx
//	push ecx
//	push edx
//	mov dword ptr ds : [0X00770000], dword ptr ss : [ebp]
//	push 0x10
//	push 0x741E48
//	call call0x6DF8FC
//	xor eax, eax
//	mov dword ptr ss : [ebp - 0x20], eax
//	mov dword ptr ss : [ebp - 0x4], eax
//	mov dword ptr ss : [ebp - 0x1C], eax
//	mov eax, dword ptr ss : ebp[ebp - 0x1C]
//	cmp eax, dword ptr ss : [ebp + 0x10]
//	jge 0x13
//	mov esi, dword ptr ss[ebp + 0x8]
//	mov ecx, esi
//	call dword ptr ss : [ebp + 0x14]
//	add esi, dword ptr ss : [ebp + 0xC]
//	mov dword ptr ss : [ebp + 0x8], esi
//	inc dword ptr ss : [ebp - 0x4]
//	jmp $ - 0xE5
//	mov dword ptr ss : [ebp - 0x20], 1
//	or dword ptr ss : [ebp - 0x4], 0xFFFFFFFF
//	call call0x6DF50C
//	call call0x6DF937
//	ret
//}

void init()
{
	WriteByteInt((LPVOID)0x00663A8D, 1920);
	WriteByteInt((LPVOID)0x00663A95, 1080);
	WriteByteInt((LPVOID)0x0019F9FC, 1920);
	WriteByteInt((LPVOID)0x0019FA00, 1080);

	//std::string newValue = "hugo";
	char* str = (char*)0x00716A0C;


	HANDLE curHandle = GetCurrentProcess();

	void* addr = update;

	//std::vector<unsigned char> vecHijack = intToBytes(((int)(CapturedVector)));

	std::vector<unsigned char> addrVec = intToBytes(((int)(addr)-(5)) - 0x006BDAD8);

	typedef BYTE byteArray[97];

	//UPDATE INJECTION CODE
	BYTE bytes[] = { 0xE8,addrVec[3],addrVec[2],addrVec[1],addrVec[0],0x90,0x90,0xC3 };
	DWORD old;

	////0x00714E8E


	VirtualProtect((LPVOID)(0x006BDAD8), sizeof(bytes), PAGE_EXECUTE_READWRITE, &old);

	SIZE_T bytesWritten = 0;
	WriteProcessMemory(curHandle, (LPVOID)(0x006BDAD8), bytes, sizeof(bytes), &bytesWritten);
	int error = GetLastError();
	//VirtualProtect((LPVOID)(0x006BDAD8), sizeof(bytes), old, NULL);

	std::ofstream myfile;
	myfile.open("output.txt");
	myfile.close();

	//unsigned char* c = (unsigned char*)(0x006BDAD8);

	//byteArray* byteSave = (byteArray*)0x006DF4C2;

	//0078124C
	std::vector<unsigned char> highjackChar = intToBytes((((int)CapturedVector) - 9) - 0x006DF4EE);
	std::vector<unsigned char> vecMake = intToBytes((((int)createVecItt) - 5) - 0x006DF4F2);

	byteArray* byteArrayInst = (byteArray*)0x006DF4C2;

	BYTE byteSave[] = {
		0xE9, 0x93, 0x59, 0x03, 0x00,
		0x50, 0x52, 0x57,0x56,
		0xFF, 0x74, 0x24, 0x3C,
		0xFF, 0x74, 0x24, 0x3C,
		0xFF, 0x74, 0x24, 0x3C,
		0xFF, 0x74, 0x24, 0x3C,
		0xFF, 0x74, 0x24, 0x3C,
		0xFF, 0x74, 0x24, 0x3C,
		0xFF, 0x74, 0x24, 0x3C,
		0xFF, 0x74, 0x24, 0x3C,
		0xFF, 0x74, 0x24, 0x3C,
		0xFF, 0x74, 0x24, 0x3C,
		0xFF, 0x74, 0x24, 0x3C,
		0xFF, 0x74, 0x24, 0x14,
		0xFF, 0x74, 0x24, 0x1c,
		0xFF, 0x74, 0x24, 0x20,
		0xFF, 0x74, 0x24, 0x24,
		0xE8, highjackChar[3],highjackChar[2],highjackChar[1],highjackChar[0],
		0xE8, vecMake[3],vecMake[2],vecMake[1],vecMake[0],
		0x5D,//0x5E,0x5F,0x5A,0x58,
		0xC3 
	};


	FUNCTIONCALL call0x6DF8FC = (FUNCTIONCALL)0x6DF8FC;
	FUNCTIONCALL call0x6DF50C = (FUNCTIONCALL)0x6DF50C;
	FUNCTIONCALL call0x6DF937 = (FUNCTIONCALL)0x6DF937;

	std::vector<unsigned char>  call0 = intToBytes(((int)(call0x6DF8FC)-5) - 0x00714E8A);
	std::vector<unsigned char>  call1 = intToBytes(((int)(call0x6DF50C)-5) - 0x00714EC0);
	std::vector<unsigned char>  call2 = intToBytes(((int)(call0x6DF937)-5) - 0x00714EC5);
	std::vector<unsigned char>  call3 = intToBytes(((int)(CapturedVector)-5) - 0x00714E69);
	//0078125D
	BYTE fullFunction[] =
	{
		0xE9, 0x86, 0x00,0x00,0x00,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,
		0xE8,call3[3],call3[2],call3[1],call3[0],0xA1,0x60,0x12,0x77,0x00,0x8B,0x15,0x64,0x12,0x77,0x00,
		0x8B,0x3D,0x68,0x12,0x77,0x00,0x50,0x53,0x52,0x57,0x6A,0x10,0x68,0x48,0x1E,0x74,0x00,0xE8,
		call0[3],call0[2],call0[1],call0[0],0x33,0xC0,0x89,0x45,0xE0,0x89,0x45,0xFC,0x89,0x45,0xE4,0x8B,0x45,0xE4,
		0x3B,0x45,0x10,0x7D,0x13,0x8B,0x75,0x08,0x8B,0xCE,0xFF,0x55,0x14,0x03,0x75,0x0C,0x89,0x75,
		0x08,0xFF,0x45,0xE4,0xEB,0xE5,0xC7,0x45,0xE0,0x01,0x00,0x00,0x00,0x83,0x4D,0xFC,0xFF,0xE8,
		call1[3],call1[2],call1[1],call1[0],0xE8,call2[3],call2[2],call2[1],call2[0],0xC2,0x14,0x00,0x83,
		0x7D,0xE0,0x00,0x75,0x11,0xFF,0x75,0x18,0xFF,0x75,0xE4,0xFF,0x75,0x0C,0xFF,0x75,0x08,0xE8,0xA9,0xFE,0xFF,0xFF,0xC3,
		0xA3,0x60,0x12,0x77,0x00,0xA3,0x64,0x12,0x77,0x00,0xA3,0x68,0x12,0x77,0x00,0xE9,0x70, 0xFF,0xFF,0xFF
	};
	VirtualProtect((LPVOID)(0x00714E5A - 5), 3000, PAGE_EXECUTE_READWRITE, NULL);
	//WriteProcessMemory(curHandle, (LPVOID)(0x00714E5A), fullFunction, sizeof(fullFunction), &bytesWritten);

	//00714E5A
	//VirtualProtect((LPVOID)(0x00714E8E), sizeof(BYTE) * 97, PAGE_EXECUTE_READWRITE, NULL);
	//WriteProcessMemory(curHandle, (LPVOID)(0x006DF4C2), byteSave, sizeof(byteSave), &bytesWritten);
	//memcpy((void*)0x00714E8E,(void*)0x006DF4C2, 97);
	int err = GetLastError();
	myfile.open("fhweuihf.txt");
	myfile << err;
	myfile.close();

	char* c = (char*)&error;
	VirtualProtect(update, 3000, PAGE_EXECUTE_READWRITE, NULL);
	VirtualProtect(str, 4, PAGE_EXECUTE_READWRITE, &old);
	char buffer[] = "M o d L o a d  ";
	for (int i = 1; i < 15; i += 2)
		buffer[i] = 0;
	memcpy(str, buffer, 16);
	VirtualProtect(str, 4, old, NULL);

	while (!GetAsyncKeyState(VK_LSHIFT));

}

//typedef  void(* __vec_ctor_vb)(void * __t, unsigned __s, int __n, void *(__thiscall *)(void *));

//__vec_ctor_vb vecDef = (__vec_ctor_vb)0x006DF4C2;

void WriteByteInt(LPVOID pointer, int i)
{
	DWORD old;
	int* loc = &i;
	VirtualProtect(pointer, 4, PAGE_EXECUTE_READWRITE, &old);
	memcpy(pointer, loc, 4);
	VirtualProtect((LPVOID)0x77810F34, 4, old, NULL);
}


extern "C" void __cdecl  update()
{
	std::cout << "HELP" << std::endl;
	if (GetAsyncKeyState(0x45))
	{
		void* p = getCurPlayer((void*)0x03BE1D01, (void*)0x03CA0348);

		//	int* p = (int*)getSomething();
		std::ofstream myfile;
		myfile.open("playerlocationpls.txt");
		//myfile <<  p;
		myfile.close();
	}
	if (GetAsyncKeyState(0x43))
	{
		CleanVector* cv = (CleanVector*)0x0077DEC4;
		std::ofstream myfile;
		myfile.open("objectDump.txt");
		myfile << cv->size();
		myfile.close();
	}

}

void SetStartPointer(int* pointer)
{
	DWORD old;

	VirtualProtect((void*)0x00714EE0, 4, PAGE_EXECUTE_READWRITE, &old);
	memcpy(pointer, pointer, 4);
}


std::vector<unsigned char> intToBytes(int paramInt)
{
	std::vector<unsigned char> arrayOfByte(4);
	for (int i = 0; i < 4; i++)
		arrayOfByte[3 - i] = (paramInt >> (i * 8));
	return arrayOfByte;
}

void __stdcall CapturedVector(void * __t, unsigned __s, int __n, void *(__thiscall *__f)(void *))
{
	void* stackPointer = NULL;
	std::ofstream myfile;
	myfile.open("vectors.txt");
	myfile << "Address: " << __t << " | " << " Size of objects: " << __s << " | Number of objects: " << __n << std::endl;
	myfile.close();

}
