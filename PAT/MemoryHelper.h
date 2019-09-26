#pragma once
#include<Windows.h>
#include"idah.h"

class MemoryHelper
{
private:
	HANDLE hProcess;
public:
	MemoryHelper();
	MemoryHelper(HANDLE h);
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

