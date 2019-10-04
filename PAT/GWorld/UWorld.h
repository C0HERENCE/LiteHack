#pragma once
#include "..//Utils/MemoryHelper.h"
#include "ULevel.h"
extern Memory GameMemory;

#define off_ULevel 0xA08
#define off_GameInstance 0xBA0

class UWorld
{
public:
	UWorld();
	UWorld(uint64);
	ULevel GetLevel() const
	{
		__int64 v5 = pULevel;
		__int64 v40;
		LODWORD(v40) = __ROL4__(__ROL4__(v5 + 1325335485, 16) - 1819744060, 16) ^ 0xA989E507;
		HIDWORD(v40) = __ROR4__(__ROR4__(HIDWORD(v5) - 1288780056, 8) + 1993666383, 8) ^ 0xD759D799;

		return GameMemory.Read<ULevel>(v40);
	}
private:
	uint64 pULevel;
	uint64 pGameInstance;
};

