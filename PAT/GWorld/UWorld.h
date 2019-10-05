#pragma once
#include "ULevel.h"
#include "UGameInstance.h"

extern Memory GameMemory;

class UWorld
{
public:
	UWorld(): base(0) {}

	UWorld(uint64 _base)
	{
		base = GameMemory.Read64(_base);
	}

	ULevel GetLevel() const
	{
		__int64 v5 = GameMemory.Read64(base+off_ULevel);
		__int64 v40;
		LODWORD(v40) = __ROL4__(__ROL4__(v5 + 1325335485, 16) - 1819744060, 16) ^ 0xA989E507;
		HIDWORD(v40) = __ROR4__(__ROR4__(HIDWORD(v5) - 1288780056, 8) + 1993666383, 8) ^ 0xD759D799;
		return ULevel(v40);
	}

	UGameInstance GetGameInstance() const
	{
		__int64 v5 = GameMemory.Read64(base + off_GameInstance);
		__int64 v40;
		LODWORD(v40) = __ROL4__(~__ROL4__(v5, 8) + 1631698383, 8) ^ 0x9EBE4230;
		HIDWORD(v40) = __ROR4__(~__ROR4__(HIDWORD(v5), 16) - 529604561, 16) ^ 0xE06EE02E;
		return UGameInstance(v40);
	}

	uint64 GetAddress() const
	{
		return base;
	}
private:
	uint64 base;

	uint64 off_ULevel = 0xA08;

	uint64 off_GameInstance = 0xBA0;
};

