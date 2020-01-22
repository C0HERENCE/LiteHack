#include "Updates.h"
#include "Global.h"
uint64 Dec::ulevel(uint64 ptr)
{
	__int64 v20; // [rsp+40h] [rbp+18h]

	LODWORD(v20) = __ROR4__(~__ROR4__(ptr, 16) + 553745679, 16) ^ 0xDEFE82F0;
	HIDWORD(v20) = __ROR4__(~__ROR4__(HIDWORD(ptr), 8) - 1599168401, 8) ^ 0xA0AEA06E;
	return v20;
}
uint64 Dec::gameinstance(uint64 ptr)
{
	__int64 v3; // [rsp+30h] [rbp+8h]

	LODWORD(v3) = __ROL4__(__ROL4__(ptr + 511116221, 16) + 852523252, 16) ^ 0x79597537;
	HIDWORD(v3) = __ROR4__(__ROR4__(HIDWORD(ptr) - 2086222104, 8) + 394116991, 8) ^ 0x7290769;
	return v3;
}
// ULevel
uint64 Dec::actor(uint64 ptr)
{
	__int64 v3; // [rsp+30h] [rbp+8h]

	LODWORD(v3) = ((ptr ^ 0x6888FC42) + 1301108050) ^ 0x7FFA56EC;
	HIDWORD(v3) = ((HIDWORD(ptr) ^ 0x3593917) + 1309822610) ^ 0x264B7785;
	return v3;
}
// AActor
uint64 Dec::pawn(uint64 ptr)
{
	__int64 v20; // [rsp+28h] [rbp-30h]
	LODWORD(v20) = (ptr + 1273741253) ^ 0x4BEBBFC5;
	HIDWORD(v20) = (HIDWORD(ptr) - 895169819) ^ 0x355B351B;
	return v20;
}
// UGameInstance
uint64 Dec::localplayer(uint64 ptr)
{
	unsigned __int64 v7 = Global::GMemory->Read64(ptr); // rcx
	unsigned __int64 v8; // r9
	unsigned int v9; // er8
	__int64 v16; // [rsp+50h] [rbp+8h]

	v8 = v7 >> 32;
	v9 = (unsigned int)v7 >> 16;
	LODWORD(v16) = (((v9 ^ (unsigned __int16)v7 | ((unsigned __int16)__ROL2__(v9, 8) << 16)) + 869467997) & 0xFFFF0000 | (unsigned __int16)((v9 ^ v7) + 1885) ^ (((v9 ^ (unsigned __int16)v7 | ((unsigned __int16)__ROL2__(v9, 8) << 16)) + 869467997) >> 16)) ^ 0x33D3075D;
	LODWORD(v7) = (HIDWORD(v7) & 0xFFFF0000 | (unsigned __int16)__ROR2__(WORD2(v7) ^ WORD1(v8), 8)) - 1304644995;
	HIDWORD(v16) = (((unsigned __int16)__ROL2__(WORD1(v7), 8) << 16) | (unsigned __int16)__ROR2__(v7 ^ WORD1(v7), 8)) ^ 0x4DC34D83;
	return v16;
}
// ULocalPlayer
uint64 Dec::playercontroller(uint64 ptr)
{
	__int64 v8; // rcx

	LODWORD(v8) = __ROR4__(__ROR4__(ptr, 8) + 1736961001, 8) ^ 0x6787EBE9,
		HIDWORD(v8) = (HIDWORD(ptr) - 431430007) ^ 0x19B71977;
	return v8;
}
uint32 Dec::ObjID(uint32 v15)
{
	return __ROR4__(v15 ^ 0x7766ED5E, 14) ^ (__ROR4__(v15 ^ 0x7766ED5E, 14) << 16) ^ 0xF159012D;
}