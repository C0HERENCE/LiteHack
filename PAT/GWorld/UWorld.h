#pragma once
#include "ULevel.h"
#include "UGameInstance.h"

extern Memory GameMemory;

class UWorld : public Base
{
public:
	UWorld()
	{
		base = 0;
	}

	UWorld(uint64 _base)
	{
		base = GameMemory.Read64(_base);
	}

	ULevel CurrentLevel()
	{
		__int64 v5 = GameMemory.Read64(base+off_ULevel);
		__int64 v40;
		LODWORD(v40) = __ROL4__(__ROL4__(v5 + 1325335485, 16) - 1819744060, 16) ^ 0xA989E507;
		HIDWORD(v40) = __ROR4__(__ROR4__(HIDWORD(v5) - 1288780056, 8) + 1993666383, 8) ^ 0xD759D799;
		return ULevel(v40);
	}

	UGameInstance OwningGameInstance()
	{
		__int64 v5 = GameMemory.Read64(base + off_GameInstance);
		__int64 v40;
		LODWORD(v40) = __ROL4__(~__ROL4__(v5, 8) + 1631698383, 8) ^ 0x9EBE4230;
		HIDWORD(v40) = __ROR4__(~__ROR4__(HIDWORD(v5), 16) - 529604561, 16) ^ 0xE06EE02E;
		return UGameInstance(v40);
	}

	uint64 GameSate()
	{
		uint64 v1 = GameMemory.Read64(base + off_GameState),v3;
		std::cout << std::hex << v1 << std::endl;
		LODWORD(v3) = __ROR4__(__ROR4__(v1, 8) - 671638663, 8) ^ 0xD7F79B79;
		HIDWORD(v3) = (HIDWORD(v1) + 1457018393) ^ 0xA927A9E7;
		std::cout << std::hex << v3 << std::dec << std::endl;
		return v3;
	}
private:
	uint64 off_ULevel = 280;

	uint64 off_GameInstance = 984;

	uint64 off_GameState = 0x130;
};