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
	uint64 v1 = (GName + 0x20070);
	return v1;
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