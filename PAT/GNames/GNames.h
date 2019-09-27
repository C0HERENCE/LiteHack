#pragma once
#include "../Utils/MemoryHelper.h"
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