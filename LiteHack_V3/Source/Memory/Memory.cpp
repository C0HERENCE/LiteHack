#include "Memory.h"
#include "../Global.h"
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
	HWND hWnd = FindWindow(LiteHack.WindowsClass, LiteHack.WindowsCaption);
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
	byte* writeMe = new byte[w_readSize+1];
	*writeMe = 0;
	MEMORY_STRUCT rStruct
	{
		(BYTE)PROTO_MESSAGE::READ, UsermodePID, TargetPID, GameBase, (void*)w_read, w_readSize, writeMe
	};
	call_hook(&rStruct);
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
