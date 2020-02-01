#include "Global.h"
#include <Psapi.h>
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "Advapi32.lib")

Memory::Memory()
{
	LoadLibrary("user32.dll");
	auto hMod = LoadLibrary("win32u.dll");
	control_function = GetProcAddress(hMod, "NtSetCompositionSurfaceAnalogExclusive");
	GameBase = 0;
	TargetPID = 0;
	UsermodePID = 0;
}

Memory::~Memory()
{

}

int Memory::Init()
{
	if (!control_function)
		return FALSE;
	MEMORY_STRUCT mem;
	mem.type = (BYTE)PROTO_MESSAGE::TEST;
	if (call_hook(&mem) != 9999)
		return FALSE;
	UsermodePID = GetCurrentProcessId();
	if (!UsermodePID)
		return FALSE;
	HWND hWnd = FindWindow(Settings::WindowsClass.c_str(), Settings::WindowsCaption.c_str());
	DWORD Pid = 0;
	GetWindowThreadProcessId(hWnd, &Pid);
	TargetPID = Pid;
	if (!TargetPID)
		return FALSE;
	mem.type = (BYTE)PROTO_MESSAGE::GETBASE_PUBGLITE;
	mem.target_pid = TargetPID;
	call_hook(&mem);
	GameBase = mem.base_address;
	if (!GameBase)
		return FALSE;
	mem.type = (BYTE)PROTO_MESSAGE::CLEAN1;
	call_hook(&mem);
	mem.type = (BYTE)PROTO_MESSAGE::CLEAN2;
	call_hook(&mem);
	mem.type = (BYTE)PROTO_MESSAGE::CLEAN3;
	call_hook(&mem);
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
	*writeMe = 0;
	MEMORY_STRUCT rStruct
	{
		(BYTE)PROTO_MESSAGE::READ, UsermodePID, TargetPID, GameBase, (void*)w_read, w_readSize, writeMe
	};
	call_hook(&rStruct);
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


/*
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
}*/