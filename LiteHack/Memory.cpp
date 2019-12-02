#include "Global.h"
#define USEDRIVER
#ifdef USEDRIVER
Memory::Memory()
{
	hDriver = 0;
	GameBase = 0;
}

Memory::~Memory()
{
	CloseHandle(hDriver);
}

int Memory::Init()
{
	hDriver = CreateFileA("\\\\.\\CcDrv", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);
	if (hDriver == INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}
	GameBase = KernelRead<int64_t>(0, PROTO_MESSAGE::PROTO_GET_BASEADDR);
	if (GameBase == 0)
	{
		return FALSE;
	}
	System::Console::WriteLine(System::String::Format("{0:x}", GameBase));
	return TRUE;
}

uint32_t Memory::Read32(const uint64_t& w_read)
{
	return Read<uint32_t>(w_read);
}

uint64_t Memory::Read64(const uint64_t& w_read)
{
	return Read<uint64_t>(w_read);
}

byte* Memory::ReadSize(const int64_t& w_read, const int32_t& w_readSize)
{
	byte* writeMe = new byte[w_readSize];
	readStruct rStruct{ (uint64_t)writeMe, (uint64_t)w_read, (ULONGLONG)w_readSize - 2, (uint32_t)GetCurrentProcessId(), 0, TRUE, 0 };
	WriteFile(hDriver, (LPCVOID)&rStruct, sizeof(ReadStruct), NULL, NULL);
	if (*writeMe == 0)
	{
		delete writeMe;
		return NULL;
	}
	return writeMe;
}


int64_t Memory::GetBase()
{
	return GameBase;
}
#endif

#ifndef USEDRIVER
#include <Psapi.h>
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "Advapi32.lib")
Memory::Memory()
{
	hProcess = 0;
	GameBase = 0;
}

Memory::~Memory()
{
	CloseHandle(hProcess);
}
int Memory::Init(HANDLE handle)
{
	hProcess = handle;
	HMODULE hMods[512];
	DWORD cb;
	if (EnumProcessModulesEx(hProcess, hMods, sizeof(hMods), &cb, LIST_MODULES_ALL))
	{
		char szModName[MAX_PATH] = { NULL };
		for (int i = 0; i < cb / sizeof(HMODULE); i++)
		{
			GetModuleBaseNameA(hProcess, hMods[i], szModName, MAX_PATH);
			if (!strcmp(szModName, Settings::MoudleName.c_str()))
			{
				GameBase = (uint64_t)hMods[i];
				return TRUE;
			}
		}
	}
	return FALSE;
}

uint32_t Memory::Read32(const uint64_t& w_read)
{
	return Read<uint32_t>(w_read);
}

uint64_t Memory::Read64(const uint64_t& w_read)
{
	return Read<uint64_t>(w_read);
}

byte* Memory::ReadSize(const int64_t& w_read, const int32_t& w_readSize)
{
	byte* buff = new byte[w_readSize];
	ReadProcessMemory(hProcess, (LPCVOID)w_read, buff, w_readSize, NULL);
	if (*buff == 0)
	{
		delete buff;
		return NULL;
	}
	return buff;
}

int64_t Memory::GetBase()
{
	return GameBase;
}
#endif
