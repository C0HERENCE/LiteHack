#include "Updates.h"
#include "Global.h"
uint64 Dec::ulevel(uint64 v18)
{
	__int64 v261;
	LODWORD(v261) = (v18 - 1042594514) ^ 0xF0F03010;
	HIDWORD(v261) = (HIDWORD(v18) - 1589798400) ^ 0x10F010F0;
	return v261;
}
uint64 Dec::gameinstance(uint64 v4)
{
	__int64 v1; // rdx@1
	int v2; // eax@1
	int v3; // eax@1
	__int64 v5; // [sp+8h] [bp+8h]@1
	v1 = v4;
	LODWORD(v5) = (~(_DWORD)v1 + 1425890107) ^ 0x7212461C;
	HIDWORD(v5) = (~(~HIDWORD(v1) + 446092664) + 1651193675) ^ 0xF3FDF33D;
	return v5;
}
// ULevel
uint64 Dec::actor(uint64 v5)
{
	int v6;
	int v7;
	unsigned __int16 v8;
	int v9;
	unsigned __int16 v10;
	int v11;
	unsigned __int16 v12;
	__int64 v31;
	v6 = ((v5 & 0xFFFF0000 | (unsigned __int16)v5 ^ ((unsigned int)v5 >> 16)) - 1629592062) >> 16;
	v7 = v6 ^ (unsigned __int16)((v5 ^ WORD1(v5)) + 26114);
	v8 = __ROR2__(v6, 8);
	v9 = v8;
	v10 = __ROR2__(WORD3(v5), 8);
	LODWORD(v6) = __ROR2__((v5 >> 32) ^ WORD3(v5), 8);
	LODWORD(v31) = (v7 | (v9 << 16)) ^ 0x9EDE6602;
	v11 = ((v10 << 16) | (unsigned __int16)v6) - 1648255678;
	v12 = __ROR2__(v11 ^ HIWORD(v11), 8);
	HIDWORD(v31) = (v11 & 0xFFFF0000 | v12) ^ 0x623E62BE;
	return v31;
}
// AActor
uint64 Dec::pawn(uint64 v1)
{
	int v2;
	int v3;
	__int64 v5;
	v2 = __ROL4__(v1, 16);
	LODWORD(v1) = __ROR4__(HIDWORD(v1), 8);
	v3 = __ROL4__(v2 - 1675842396, 16);
	LODWORD(v1) = __ROR4__(v1 - 1692165340, 8);
	LODWORD(v5) = v3 ^ 0x9C1CACA4;
	HIDWORD(v5) = v1 ^ 0x64DC64DC;
	return v5;
}
// UGameInstance
uint64 Dec::localplayer(uint64 inst)
{
	int v2;
	int v3;
	__int64 v5;
	__int64 v6;
	__int64 v1;
	v6 = inst;
	v1 = LiteHack.GMemory->Read64(v6);
	v2 = __ROL4__(v1 ^ 0xE9EA03BD, 8);
	LODWORD(v1) = __ROR4__(HIDWORD(v1) ^ 0x4E19C6E8, 16);
	v3 = __ROL4__((v2 - 2080050116) ^ 0x84EA03BD, 8);
	LODWORD(v1) = __ROR4__((v1 - 2084863044) ^ 0xE919C6E8, 16);
	LODWORD(v5) = v3 ^ 0x8404F43C;
	HIDWORD(v5) = v1 ^ 0x7C447C44;
	return v5;
}
// ULocalPlayer
uint64 Dec::playercontroller(uint64 inst)
{
	__int64 v15;
	unsigned __int64 v16;
	unsigned __int16 v17;
	unsigned int v18;
	unsigned __int16 v19;
	unsigned __int16 v20;
	unsigned int v21;
	unsigned __int16 v22;
	__int64 v96;
	v15 = inst;
	v16 = v15 >> 32;
	v17 = __ROR2__(WORD1(v15), 8);
	v18 = ((unsigned __int16)v15 ^ ((unsigned int)v15 >> 16) | (v17 << 16)) - 1195845432;
	v19 = __ROR2__(HIWORD(v18), 8);
	LODWORD(v96) = ((unsigned __int16)v18 ^ (v18 >> 16) | (v19 << 16)) ^ 0xB8B8D8C8;
	v20 = __ROL2__((v15 >> 32) ^ WORD1(v16), 8);
	v21 = (HIDWORD(v15) & 0xFFFF0000 | v20) - 1211648056;
	v22 = __ROL2__((v20 - 18488) ^ HIWORD(v21), 8);
	HIDWORD(v96) = (v21 & 0xFFFF0000 | v22) ^ 0x48384838;
	return v96;
}
int Dec::ObjID(uint32 v11)
{
	return __ROL4__(v11 ^ 0xF7B20EA6, 14) ^ (__ROL4__(v11 ^ 0xF7B20EA6, 14) << 16) ^ 0xF914F7B2;
}
