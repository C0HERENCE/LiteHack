#include <iostream>
#include "..//offsets_decryptions.h"
#include "NamesStore.h"


extern Memory GameMemory;

NamesStore::NamesStore()
{

}

NamesStore::NamesStore(uint64 address)
{
	Address = Initialize(address);
}

uint64 NamesStore::Initialize(uint64 address)
{
	uint64 GName = GameMemory.Read64(address);
	return GName + updates::off::static_gnames;
}

std::string NamesStore::GetById(int ID) const
{
	uint64 fNamePtr = GameMemory.Read64(Address + int(ID / updates::off::chunksize) * 8);
	uint64 fName = GameMemory.Read64(fNamePtr + 8 * int(ID % updates::off::chunksize));
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