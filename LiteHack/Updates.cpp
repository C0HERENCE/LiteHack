#include "Updates.h"
#include "Global.h"
uint64 Dec::ulevel(uint64 v5)
{
	uint64 v11;
	LODWORD(v11) = __ROR4__(__ROL4__(v5 + 1939245711, 8) - 493482368, 16) ^ 0xDFFF83F1;
	HIDWORD(v11) = __ROR4__(__ROR4__(HIDWORD(v5) - 466102920, 16) - 779602935, 8) ^ 0xA1AFA16F;
	return v11;
}
uint64 Dec::gameinstance(uint64 ptr)
{
	__int64 v3; // [rsp+30h] [rbp+8h]
	LODWORD(v3) = __ROL4__(__ROL4__(ptr, 16) - 58946492, 16) ^ 0xFC7C8C44;
	HIDWORD(v3) = __ROR4__(__ROR4__(HIDWORD(ptr), 8) - 71042108, 8) ^ 0x43C043C;
	return v3;
}
// ULevel
uint64 Dec::actor(uint64 v24)
{
	signed __int64 v7;
	__int64 v9;
	__int64 v38;

	v7 = Global::GWorld->GetAddress();

	v9 = v24;
	LODWORD(v7) = __ROL4__(v9 + 1670810255, 8);
	LODWORD(v9) = __ROR4__(HIDWORD(v9) - 734538376, 16);
	LODWORD(v7) = __ROR4__(v7 - 2109342256, 16);
	LODWORD(v9) = __ROR4__(v9 + 1909974105, 8);
	LODWORD(v38) = v7 ^ 0x8FAF7341;
	HIDWORD(v38) = v9 ^ 0xF15FF11F;

	return  v38;
}
// AActor
uint64 Dec::pawn(uint64 v3)
{
	uint64 v5;
	LODWORD(v5) = (v3 - 454596331) ^ 0x55B5619B;
	HIDWORD(v5) = (HIDWORD(v3) + 776757835) ^ 0x2B452B85;
	return v5;
}
// UGameInstance
uint64 Dec::localplayer(uint64 v20)
{
	signed __int64 v1;
	__int64 v3;

	v1 = Global::GMemory->Read64(v20);
	LODWORD(v3) = (~(v1 - 1543037276) + 680954511) ^ 0xC26256CC;
	HIDWORD(v3) = (~(~HIDWORD(v1) + 171431288) + 588965531) ^ 0x43AD43ED;
	return v3;
}
// ULocalPlayer
uint64 Dec::playercontroller(uint64 v7)
{
	uint64 v8;
	LODWORD(v8) = (~(_DWORD)v7 + 1901170111) ^ 0x8EAE7240,
	HIDWORD(v8) = __ROL4__(~__ROL4__(HIDWORD(v7), 8) - 262213601, 8) ^ 0xF05EF01E;
	return v8;
}
uint32 Dec::ObjID(uint32 v15)
{
	return __ROL4__(v15 ^ 0x6F08BDBC, 12) ^ (__ROL4__(v15 ^ 0x6F08BDBC, 12) << 16) ^ 0x5EA13260;
}