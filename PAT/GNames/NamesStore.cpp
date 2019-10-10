#include <iostream>
#include "NamesStore.h"


extern Memory GameMemory;

NamesStore::NamesStore()
{

}

NamesStore::NamesStore(uint64 Base)
{
	Address = Initialize(Base);
}

uint64 NamesStore::Initialize(uint64 a)
{
	uint64 GName = GameMemory.Read64(a);
	__int64 v3 = GName;
	__int64 v20,v10,v17,v30,v42;
	unsigned __int64 v11,v12;
	int v13;
	LODWORD(v20) = (v3 - 1494856070) ^ 0xA6E64E7A;
	HIDWORD(v20) = (HIDWORD(v3) - 1522948678) ^ 0x5AC65A46;
	v10 = GameMemory.Read64(v20);
	LODWORD(v20) = (((v10 ^ (v10 >> 16) | (__ROL2__(WORD1(v10), 8) << 16)) + 1408476989) & 0xFFFF0000 | ((v10 ^ WORD1(v10)) - 22723) ^ (((v10 ^ (v10 >> 16) | (__ROL2__(WORD1(v10), 8) << 16)) + 1408476989) >> 16)) ^ 0x53F3A73D;
	HIDWORD(v20) = ((__ROL2__(((HIDWORD(v10) & 0xFFFF0000 | __ROR2__(WORD2(v10) ^ HIWORD(v10), 8)) - 769863075) >> 16, 8) << 16) | __ROR2__((__ROR2__(WORD2(v10) ^ HIWORD(v10), 8) - 11683) ^ (((HIDWORD(v10) & 0xFFFF0000 | __ROR2__(WORD2(v10) ^ HIWORD(v10), 8)) - 769863075) >> 16), 8)) ^ 0x2DE32DA3;
	v11 = __PAIR__(
		__ROR4__(__ROR4__(GameMemory.Read64(v20) >> 32, 8) + 1800629076, 8) ^ 0x94AC94AC,
		__ROL4__(__ROL4__(GameMemory.Read64(v20), 16) + 1827421396, 16) ^ 0x6CEC3CD4u);
	v12 = ((v11 ^ 0xB868) ^ ((v11 ^ 0x1818B868) >> 16) | (v11 ^ 0x1818B868) & 0xFFFF0000) - 404273256;
	LODWORD(v20) = v12 & 0xFFFF0000 | v12 ^ (v12 >> 16);
	LOWORD(v11) = __ROR2__(WORD2(v11) ^ 0xE898, 8);
	v13 = ((__ROL2__(HIWORD(v11) ^ 0xE898, 8) << 16) | __ROL2__(HIWORD(v11) ^ 0xE898, 8) ^ v11) - 392632168;
	HIDWORD(v20) = (__ROL2__(HIWORD(v13), 8) << 16) | __ROL2__(HIWORD(v13), 8) ^ __ROR2__(
		(__ROL2__(HIWORD(v11) ^ 0xE898, 8) ^ v11)
		- 5992,
		8);

	v10 = GameMemory.Read64(v20);
	std::cout << std::hex << v10 << std::dec << std::endl;
	unsigned int v5, v6, v7;
	v11 = 0;
	v5 = (v10 & 0xFFFF0000 | v10 ^ (v10 >> 16)) + 404273256;
	LODWORD(v11) = (v5 & 0xFFFF0000 | ((v10 ^ WORD1(v10)) - 18328) ^ (v5 >> 16)) ^ 0x1818B868;
	HIDWORD(v11) = (__ROL2__(
		(__ROL2__(WORD2(v10) ^ HIWORD(v10), 8) + 5992) ^ (((__ROL2__(WORD2(v10) ^ HIWORD(v10), 8) | (__ROR2__(HIWORD(v10), 8) << 16))
			+ 392632168) >> 16),
		8) | (__ROR2__(
		((__ROL2__(WORD2(v10) ^ HIWORD(v10), 8) | (__ROR2__(HIWORD(v10), 8) << 16)) + 392632168) >> 16,
			8) << 16)) ^ 0xE898E898;
	v6 = (GameMemory.Read64(v11) + 913743594) ^ 0x36769EEA;
	v7 = ((GameMemory.Read64(v11) >> 32) + 900281642) ^ 0xCA56CAD6;
	v11 = __PAIR__(v7, v6);
	return v11;
}

std::string NamesStore::GetById(int ID) const
{
	uint64 fNamePtr = GameMemory.Read64(Address + int(ID / off_ChunkSize) * 8);
	uint64 fName = GameMemory.Read64(fNamePtr + 8 * int(ID % off_ChunkSize));
	char name[100] = { NULL };
	if (GameMemory.ReadString(fName + 0x10, name, 100) != 0)
	{
		std::string string = std::string(name);
		return string;
	}
	return std::string("NULL");
}

uint64 NamesStore::GetAddress()
{
	return Address;
}