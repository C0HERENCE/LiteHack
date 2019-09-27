#include <iostream>
#include "GNames.h"


extern Memory GameMemory;

GNames::GNames()
{

}

GNames::GNames(uint64 Base)
{
	DecryptGNames(Base);
}

uint64 GNames::DecryptGNames(uint64 a)
{
	uint64 GName =GameMemory.Read64(a);
	uint64 v3 = GName;
	uint64 v19, v14, v15;
	LODWORD(v19) = ((v3 ^ 0x3815FC42) + 492692866) ^ 0x7FB7E63C;
	HIDWORD(v19) = ((HIDWORD(v3) ^ 0xD3E63917) + 507649730) ^ 0x26A427D5;
	v14 = GameMemory.Read64(v19);
	LODWORD(v19) = __ROR4__(__ROL4__(GameMemory.Read64(v19) + 600869519, 8) + 37731856, 16) ^ 0x4F6F3381;
	HIDWORD(v19) = __ROR4__(__ROR4__(HIDWORD(v14) - 1804479112, 16) - 229465191, 8) ^ 0x311F31DF;
	v15 = GameMemory.Read64(v19);
	LODWORD(v19) = (((v15 & 0xFFFF0000 | (unsigned __int16)v15 ^ ((unsigned int)v15 >> 16)) + 1751697432) & 0xFFFF0000 | (unsigned __int16)((v15 ^ WORD1(v15)) - 14312) ^ ((unsigned __int64)((v15 & 0xFFFF0000 | (unsigned __int16)v15 ^ ((unsigned int)v15 >> 16)) + 1751697432) >> 16)) ^ 0x6868C818;
	LODWORD(v15) = ((((unsigned __int16)__ROR2__(HIWORD(v15), 8) << 16) | (unsigned int)(unsigned __int16)__ROL2__(WORD2(v15) ^ HIWORD(v15), 8))
		+ 1729586968) >> 16;
	LODWORD(v19) = __ROR4__((__ROR4__((unsigned int)v19 ^ 0x149444AC, 8) ^ 0x14EA03BD) - 345261228, 8) ^ 0x79EA03BD;
	HIDWORD(v19) = __ROL4__(		(__ROL4__(		(((unsigned __int16)__ROR2__(v15, 8) << 16) | (unsigned __int16)__ROL2__(			(__ROL2__(				WORD2(v15) ^ HIWORD(v15),				8)				+ 26392) ^ v15,			8)) ^ 0x743C743C,			16) ^ 0x7919C6E8)		- 321590060,		16) ^ 0xDE19C6E8;
	uint64 v17 = v19;
	uint64 v47, v31, v30;
	LODWORD(v47) = __ROL4__((__ROL4__(v17 ^ 0x79EA03BD, 8) + 345261228) ^ 0x14EA03BD, 8) ^ 0x149444AC;
	HIDWORD(v47) = __ROR4__((__ROR4__(HIDWORD(v17) ^ 0xDE19C6E8, 16) + 321590060) ^ 0x7919C6E8, 16) ^ 0xECD4ECD4;
	v30 = GameMemory.Read64(v47 + 0x10);
	LODWORD(v31) = __ROR4__(~__ROR4__(v30, 16) - 2124325457, 16) ^ 0x7E9EA250;
	HIDWORD(v31) = __ROR4__(~__ROR4__(HIDWORD(v30), 8) + 5111823, 8) ^ 0x4E000E;
	DecryptedGNames = v31;
	return DecryptedGNames;
}

std::string GNames::GetActorNameFromID(int ID)
{
	uint64 fNamePtr = GameMemory.Read64(DecryptedGNames + int(ID / off_ChunkSize) * 8);
	uint64 fName = GameMemory.Read64(fNamePtr + 8 * int(ID % off_ChunkSize));
	char name[100] = { NULL };
	if (GameMemory.ReadString(fName + 0x10, name, 100) != 0)
	{
		std::string string = std::string(name);
		return string;
	}
	return std::string("NULL");
}