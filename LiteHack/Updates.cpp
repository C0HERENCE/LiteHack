#include "Updates.h"
#include "Global.h"
uint64 Dec::ulevel(uint64 v25)
{
	unsigned __int64 v29;
	unsigned int v10;
	__int64 v23;

	v29 = v25 >> 32;
	v10 = (v25 & 0xFFFF0000 | (unsigned __int16)v25 ^ ((unsigned int)v25 >> 16)) + 509535874;
	LODWORD(v25) = v10 >> 16;
	LODWORD(v23) = (v25 ^ (unsigned __int16)v10 | ((unsigned __int16)__ROR2__(v25, 8) << 16)) ^ 0x1E5EE682;
	HIDWORD(v23) = ((((unsigned __int16)__ROR2__(v29 ^ WORD1(v29), 8) | ((unsigned __int16)__ROR2__(WORD1(v29), 8) << 16))
		+ 490806722) & 0xFFFF0000 | (unsigned __int16)__ROR2__(
		(__ROR2__(v29 ^ WORD1(v29), 8) + 7618) ^ ((((unsigned __int16)__ROR2__(v29 ^ WORD1(v29), 8) | ((unsigned int)(unsigned __int16)__ROR2__(WORD1(v29), 8) << 16)) + 490806722) >> 16),
			8)) ^ 0xE2BEE23E;

	return v23;
}
uint64 Dec::gameinstance(uint64 v1)
{
	__int64 v3;
	LODWORD(v3) = ((v1 ^ 0x48FBFC42) + 762164594) ^ 0x7F69B6CC;
	HIDWORD(v3) = ((HIDWORD(v1) ^ 0xE3CC3917) + 775040690) ^ 0x66FE17A5;
	return v3;
}
// ULevel
uint64 Dec::actor(uint64 v28)
{
	unsigned __int64 v55;
	unsigned int v56;
	__int64 a11;
	v55 = v28 >> 32;
	v56 = (HIDWORD(v28) & 0xFFFF0000 | (unsigned __int16)__ROL2__(WORD2(v28) ^ WORD1(v55), 8)) - 1746429976;
	LODWORD(a11) = ((((((unsigned int)v28 >> 16) ^ (unsigned __int16)v28 | ((unsigned __int16)__ROR2__(WORD1(v28), 8) << 16))
		- 1734854424) >> 16) ^ (unsigned __int16)((WORD1(v28) ^ v28) + 14568) | ((unsigned __int16)__ROR2__(((((unsigned int)v28 >> 16) ^ (unsigned __int16)v28 | ((unsigned __int16)__ROR2__(WORD1(v28), 8) << 16)) - 1734854424) >> 16, 8) << 16)) ^ 0x989838E8;
	HIDWORD(a11) = (v56 & 0xFFFF0000 | (unsigned __int16)__ROL2__(v56 ^ HIWORD(v56), 8)) ^ 0x68186818;
	return a11;
}
// AActor
uint64 Dec::pawn(uint64 v45)
{
	unsigned __int64 v51;
	LODWORD(v51) = (~(v45 - 1543561564) + 681478799) ^ 0xC26256CC;
	HIDWORD(v51) = (~(~HIDWORD(v45) + 171955576) + 588441243) ^ 0x43AD43ED;

	return v51;
}
// UGameInstance
uint64 Dec::localplayer(uint64 ENC)
{
	__int64 v6;
	__int64 v14;
	v6 = Global::GMemory->Read64(ENC);
	LODWORD(v14) = (v6 - 1806845819) ^ 0xE545B10B;
	HIDWORD(v14) = (HIDWORD(v6) - 577637701) ^ 0x9BD59B15;

	return v14;
}
// ULocalPlayer
uint64 Dec::playercontroller(uint64 v9)
{
	__int64 v6;
	unsigned int v10;
	unsigned __int64 v11;
	LODWORD(v11) = __ROL4__(__ROL4__(v9 - 1107033155, 16) + 1929222484, 16) ^ 0x19F99597;
	HIDWORD(v11) = __ROR4__(__ROR4__(HIDWORD(v9) + 590595816, 8) + 1449811935, 8) ^ 0x67C96709;

	return v11;
}
uint32 Dec::ObjID(uint32 ID)
{
	int v33;
	v33 = __ROL4__(ID ^ 0xE570B9D4, 16) ^ (__ROL4__(ID ^ 0xE570B9D4, 16) << 16) ^ 0xE06F4CF0;

	return v33;
}