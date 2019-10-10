#pragma once
#include <string>
#include "../Utils/MemoryHelper.h"

#define off_ChunkSize 0x3E14

class NamesStore
{
public:
	NamesStore();
	NamesStore(uint64);
	uint64 Initialize(uint64 a);
	uint64 GetAddress();
	std::string GetById(int id) const;
private:
	uint64 Address;
};