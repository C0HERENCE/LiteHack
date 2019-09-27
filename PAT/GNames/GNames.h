#pragma once
#include <string>
#include "../Utils/MemoryHelper.h"

#define off_ChunkSize 0x3FD4

class GNames
{
public:
	GNames();
	GNames(uint64);
	uint64 DecryptGNames(uint64 a);
	std::string GetActorNameFromID(int ID);
private:
	uint64 DecryptedGNames;
};

uint64 Dec_GNames(uint64);