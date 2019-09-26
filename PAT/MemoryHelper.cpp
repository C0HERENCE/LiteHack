#include "MemoryHelper.h"
MemoryHelper::MemoryHelper()
{
	
}
MemoryHelper::MemoryHelper(HANDLE h)
{
	this->hProcess = h;
}
uint64 MemoryHelper::Read64(uint64 address)
{
	uint64 buff;
	ReadProcessMemory(hProcess, (LPCVOID)address, &buff, sizeof(uint64), NULL);
	return buff;
}
uint32 MemoryHelper::Read32(uint64 address)
{
	uint32 buff;
	ReadProcessMemory(hProcess, (LPCVOID)address, &buff, sizeof(uint32), NULL);
	return buff;
}

BOOL MemoryHelper::ReadWString(SIZE_T address, wchar_t* buff, DWORD bufSize)
{
	return ReadProcessMemory(hProcess, (LPCVOID)address, buff, bufSize, NULL);
}

BOOL MemoryHelper::ReadString(SIZE_T address, char* buff, DWORD bufSize)
{
	return ReadProcessMemory(hProcess, (LPCVOID)address, buff, bufSize, NULL);
}