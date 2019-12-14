#include "Updates.h"
#include "Global.h"
uint64 Dec::ulevel(uint64 v25)
{
	unsigned __int64 v29;
	unsigned int v10;
	__int64 v23;

	LODWORD(v23) = __ROR4__(__ROR4__(v25, 8) + 389536569, 8) ^ 0x1737DB39;
	HIDWORD(v23) = (HIDWORD(v25) - 1768384807) ^ 0x69676927;

	return v23;
}
uint64 Dec::gameinstance(uint64 v1)
{
	unsigned __int64 v2; // r10
	unsigned int v3; // edx
	unsigned int v4; // er9
	unsigned int v5; // edx
	__int64 v7; // [rsp+58h] [rbp+30h]

	v2 = v1 >> 32;
	v3 = (((unsigned int)v1 >> 16) ^ (unsigned __int16)v1 | ((unsigned __int16)__ROR2__(WORD1(v1), 8) << 16)) - 926373704;
	v4 = ((v3 >> 16) ^ (unsigned __int16)v3 | ((unsigned __int16)__ROR2__(HIWORD(v3), 8) << 16)) ^ 0xC8C8A8B8;
	v5 = (HIDWORD(v1) & 0xFFFF0000 | (unsigned __int16)__ROL2__(WORD2(v1) ^ WORD1(v2), 8)) - 944257096;
	LODWORD(v7) = v4;
	HIDWORD(v7) = (v5 & 0xFFFF0000 | (unsigned __int16)__ROL2__(v5 ^ HIWORD(v5), 8)) ^ 0x38483848;
	return v7;
}
// ULevel
uint64 Dec::actor(uint64 v28)
{
	unsigned __int64 v55;
	unsigned int v56;
	__int64 a11;

	LODWORD(a11) = (1752795790 - (v28 - 1536925852)) ^ 0x8222160C;
	HIDWORD(a11) = (586688346 - (1243272567 - HIDWORD(v28))) ^ 0x3ED032D;
	return a11;

}
// AActor
uint64 Dec::pawn(uint64 v3)
{
	__int64 v27;
	LODWORD(v27) = __ROL4__(__ROL4__(v3, 16) + 1019005956, 16) ^ 0x3CBCCC04;
	HIDWORD(v27) = __ROR4__(__ROR4__(HIDWORD(v3), 8) + 998456196, 8) ^ 0xC47CC47C;
	return v27;

}
// UGameInstance
uint64 Dec::localplayer(uint64 v20)
{
	__int64 v6;
	__int64 v14;

	v6 = Global::GMemory->Read64(v20);
	LODWORD(v14) = __ROL4__((__ROL4__(v6 ^ 0x89A603BD, 8) + 614732956) ^ 0x24A603BD, 8) ^ 0x24A4149C;
	HIDWORD(v14) = __ROR4__((__ROR4__(HIDWORD(v6) ^ 0xEED5C6E8, 16) + 588981020) ^ 0x89D5C6E8, 16) ^ 0xDCE4DCE4;

	return v14;
}
// ULocalPlayer
uint64 Dec::playercontroller(uint64 v7)
{
	auto v8 = v7 >> 32;
	auto v9 = (((unsigned int)v7 >> 16) ^ (unsigned __int16)v7 | ((unsigned __int16)__ROR2__(WORD1(v7), 8) << 16)) + 1482225704;
	auto v10 = (v9 >> 16) ^ (unsigned __int16)((WORD1(v7) ^ v7) - 2008) | ((unsigned __int16)__ROR2__(HIWORD(v9), 8) << 16);
	auto v11 = (HIDWORD(v7) & 0xFFFF0000 | (unsigned __int16)__ROL2__(WORD2(v7) ^ WORD1(v8), 8)) + 1462196008;
	uint64 v12;
	LODWORD(v12) = v10 ^ 0x5858F828;
	HIDWORD(v12) = (v11 & 0xFFFF0000 | (unsigned __int16)__ROL2__(v11 ^ HIWORD(v11), 8)) ^ 0xA8D8A8D8;
	return v12;
}
uint32 Dec::ObjID(uint32 v17)
{
	int v78;
	LODWORD(v78) = __ROR4__(v17 ^ 0x5B827462, 4) ^ (__ROR4__(v17 ^ 0x5B827462, 4) << 16) ^ 0x68B90FAD;

	return v78;
}