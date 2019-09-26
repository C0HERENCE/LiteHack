#include <string>
#include <iostream>
#include "GNames.h"


extern MemoryHelper mh;
#define off_GNames 0x46546C0
#define off_ChunkSize 0x4178

uint64  Dec_GNames(uint64  GName)
{
	uint64 v3, v24, v12, v14, a6,v13;
	v3 = GName;
	LODWORD(v24) = (v3 + 638921045) ^ 0x157521DB;
	HIDWORD(v24) = (HIDWORD(v3) + 1878663819) ^ 0x6B056B45;
	v12 = mh.Read64(v24) >> 32;
	v13 = ((unsigned __int16) mh.Read64(v24) ^ ((unsigned int)mh.Read64(v24) >> 16) | mh.Read64(v24) & 0xFFFF0000) + 779007602;
	LODWORD(v24) = ((unsigned __int16)v13 ^ (v13 >> 16) | ((unsigned __int16)__ROR2__(HIWORD(v13), 8) << 16)) ^ 0x2E6EB672;
	HIDWORD(v24) = ((((unsigned __int16)__ROR2__(v12 ^ WORD1(v12), 8) | ((unsigned __int16)__ROR2__(WORD1(v12), 8) << 16))
		+ 758197682) & 0xFFFF0000 | (unsigned __int16)__ROR2__(
		(__ROR2__(v12 ^ WORD1(v12), 8) + 11698) ^ ((((unsigned __int16)__ROR2__(v12 ^ WORD1(v12), 8) | ((unsigned int)(unsigned __int16)__ROR2__(WORD1(v12), 8) << 16)) + 758197682) >> 16),
			8)) ^ 0xD2CED24E;
	v14 = ((mh.Read64(v24) >> 32) + 1511283285) ^ 0xA5EBA5AB;
	LODWORD(v24) = __ROL4__(__ROL4__((mh.Read64(v24) - 612692171) ^ 0x5CDC84FC, 8) + 2019062839, 8);
	HIDWORD(v24) = (v14 ^ 0xF9D7F997) - 103286377;
	a6 = mh.Read64(v24);

	uint64 v7, a7, v10;
	unsigned int v11;
	LODWORD(a7) = __ROR4__(__ROR4__(a6, 8) - 2019062839, 8) ^ 0x87A78BC9;
	HIDWORD(a7) = (HIDWORD(a6) + 103286377) ^ 0xF9D7F997;
	v10 = (mh.Read64(a7) + 375732485) ^ 0x65C5318B;
	v11 = ((mh.Read64(a7) >> 32) + 1605005883) ^ 0x1B551B95;
	a7 = __PAIR__(v11, v10);
	return a7;
}
uint64_t Decrypt_GNames(uint64_t GName)
{
	uint64 v24;
	__int64 v12; // r9
	unsigned int v13; // edx
	int v14; // ch^3
	int64 v3 = GName;
	LODWORD(v24) = (v3 + 638921045) ^ 0x157521DB;
	HIDWORD(v24) = (HIDWORD(v3) + 1878663819) ^ 0x6B056B45;
	v12 = mh.Read64(v24) >> 32;
	v13 = ((unsigned __int16) mh.Read64(v24) ^ ((unsigned int)mh.Read64(v24) >> 16) | mh.Read64(v24) & 0xFFFF0000) + 779007602;
	LODWORD(v24) = ((unsigned __int16)v13 ^ (v13 >> 16) | ((unsigned __int16)__ROR2__(HIWORD(v13), 8) << 16)) ^ 0x2E6EB672;
	HIDWORD(v24) = ((((unsigned __int16)__ROR2__(v12 ^ WORD1(v12), 8) | ((unsigned __int16)__ROR2__(WORD1(v12), 8) << 16))
		+ 758197682) & 0xFFFF0000 | (unsigned __int16)__ROR2__(
		(__ROR2__(v12 ^ WORD1(v12), 8) + 11698) ^ ((((unsigned __int16)__ROR2__(v12 ^ WORD1(v12), 8) | ((unsigned int)(unsigned __int16)__ROR2__(WORD1(v12), 8) << 16)) + 758197682) >> 16),
			8)) ^ 0xD2CED24E;
	v14 = ((mh.Read64(v24) >> 32) + 1511283285) ^ 0xA5EBA5AB;
	LODWORD(v24) = __ROL4__(__ROL4__((mh.Read64(v24) - 612692171) ^ 0x5CDC84FC, 8) + 2019062839, 8);
	HIDWORD(v24) = (v14 ^ 0xF9D7F997) - 103286377;
	
	uint64 v46;
	__int64 v17 = v24;
	LODWORD(v46) = __ROR4__(__ROR4__(v17, 8) - 2019062839, 8) ^ 0x87A78BC9;
	HIDWORD(v46) = (HIDWORD(v17) + 103286377) ^ 0xF9D7F997;
	__int64 v30; // ST68_8
	LODWORD(v30) = (mh.Read64(v46) + 0x16653905) ^ 0x65C5318B;
	HIDWORD(v30) = ((mh.Read64(v46) >> 32) + 0x5FAA723B) ^ 0x1B551B95;
	return v30;
}
uint64 GNames::DecryptGNames(uint64 a)
{
	uint64 v4=mh.Read64(a);
	uint64 d = Decrypt_GNames(v4);
	DecryptedGNames = d;
	return d;
}

std::string GNames::GetActorNameFromID(int ID)
{
	uint64 fNamePtr = mh.Read64(DecryptedGNames + int(ID / off_ChunkSize) * 8);
	uint64 fName = mh.Read64(fNamePtr + 8 * int(ID % off_ChunkSize));
	char name[100] = { NULL };
	if (mh.ReadString(fName + 0x10, name, 100) != 0)
	{
		std::string string = std::string(name);
		return string;
	}
	return std::string("NULL");
}