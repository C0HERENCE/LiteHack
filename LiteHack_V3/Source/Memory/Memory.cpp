#include "Memory.h"
#include "../Global.h"
#include <Psapi.h>
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "Advapi32.lib")

Memory::Memory()
{
	// LoadLibrary("user32.dll");
	// auto hMod = LoadLibrary("win32u.dll");
	// control_function = GetProcAddress(hMod, "NtSetCompositionSurfaceAnalogExclusive");
	// GameBase = 0;
	// TargetPID = 0;
	// UsermodePID = 0;
}

Memory::~Memory()
{

}

int Memory::Init()
{
	HWND hWnd = FindWindow("UnrealWindow", "PUBG LITE ");
	DWORD Pid = 0;
	GetWindowThreadProcessId(hWnd, &Pid);
	if (Pid == 0)
	{
		printf("GetWindowThreadProcessId Error: %d\n", GetLastError());
	}
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, Pid);
	GameBase = 0;
	if (hProcess == 0)
	{
		printf("OpenProcess Error\n");
	}
	printf("Enuming\n");
	HMODULE hMods[512];
	DWORD cb;
	if (EnumProcessModulesEx(hProcess, hMods, sizeof(hMods), &cb, LIST_MODULES_ALL))
	{
		char szModName[MAX_PATH] = { NULL };
		for (int i = 0; i < cb / sizeof(HMODULE); i++)
		{
			GetModuleBaseNameA(hProcess, hMods[i], szModName, MAX_PATH);
			if (!std::string("PUBGLite-Win64-Shipping.exe").compare(szModName))
			{
				printf("PID\n");
				printf("Base: %p\n", (uint64_t)hMods[i]);
				GameBase = (uint64_t)hMods[i];
				return TRUE;
			}
		}
	}
	else
	{
		printf("EnumProcessModulesEx Error: %d\n", GetLastError());
	}
	printf("Module not found\n");
	return FALSE;
	// if (!control_function)
	// 	return FALSE;
	// MEMORY_STRUCT mem;
	// mem.type = (BYTE)PROTO_MESSAGE::TEST;
	// if (call_hook(&mem) != 9999)
	// 	return FALSE;
	// UsermodePID = GetCurrentProcessId();
	// if (!UsermodePID)
	// 	return FALSE;
	// HWND hWnd = FindWindow(LiteHack.WindowsClass, LiteHack.WindowsCaption);
	// DWORD Pid = 0;
	// GetWindowThreadProcessId(hWnd, &Pid);
	// TargetPID = Pid;
	// if (!TargetPID)
	// 	return FALSE;
	// mem.type = (BYTE)PROTO_MESSAGE::GETBASE_PUBGLITE;
	// mem.target_pid = TargetPID;
	// call_hook(&mem);
	// GameBase = mem.base_address;
	// if (!GameBase)
	// 	return FALSE;
	// mem.type = (BYTE)PROTO_MESSAGE::CLEAN1;
	// call_hook(&mem);
	// mem.type = (BYTE)PROTO_MESSAGE::CLEAN2;
	// call_hook(&mem);
	// mem.type = (BYTE)PROTO_MESSAGE::CLEAN3;
	// call_hook(&mem);
	// return TRUE;
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
	byte* writeMe = new byte[w_readSize+1];
	*writeMe = 0;
	ReadProcessMemory(hProcess, (LPCVOID)w_read, writeMe, w_readSize, NULL);
	if (*writeMe == 0)
	{
		delete[] writeMe;
		return NULL;
	}
	writeMe[w_readSize] = '\0';
	return writeMe;
}


int64_t Memory::GetBase()
{
	return GameBase;
}
