#pragma once
#include <string>

#include <Windows.h>
#include"../Utils/ida_defs.h"
class Memory
{
private:
	HANDLE hProcess;
public:
	Memory();
	Memory(HANDLE h);
	uint64 Read64(uint64 address);
	uint32 Read32(uint64 address);
	template<class T>
	T Read(uint64 address)
	{
		T buff;
		ReadProcessMemory(hProcess, (LPCVOID)address, &buff, sizeof(T), NULL);
		return buff;
	}
	BOOL ReadWString(SIZE_T address, wchar_t* buff, DWORD bufSize);
	BOOL ReadString(SIZE_T address, char* buff, DWORD bufSize);
};

