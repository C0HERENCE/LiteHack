#pragma once
#include "MemoryHelper.h"
class GNames
{
public:
	uint64 DecryptGNames(uint64 a);
	std::string GetActorNameFromID(int ID);
private:
	uint64 DecryptedGNames;
};

uint64 Dec_GNames(uint64);