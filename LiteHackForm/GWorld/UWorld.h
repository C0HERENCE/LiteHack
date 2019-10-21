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
		__int64 v14; // rdx@7
		int v15; // eax@7
		int v16; // eax@7
		__int64 v22; // [sp+40h] [bp+18h]@7

		v14 = GameMemory.Read64(base + 792);
		LODWORD(v22) = __ROL4__((__ROL4__(v14 ^ 0xD96203BD, 8) + 1962157132) ^ 0x746203BD, 8) ^ 0x74F4244C;
		HIDWORD(v22) = (_DWORD)(__ROR4__((__ROR4__(HIDWORD(v14) ^ 0x3E91C6E8, 16) + 1942713292) ^ 0xD991C6E8, 16) ^ 0x8C348C34);

		return ULevel(v22);
		//return ULevel(updates::dec::ulevel(GameMemory.Read64(base + updates::off::ulevel)));
	}

	UGameInstance OwningGameInstance()
	{
		return UGameInstance(updates::dec::gameinstance(GameMemory.Read64(base + updates::off::gameinstance)));
	}

	uint64 GameSate()
	{
		uint64 v1 = GameMemory.Read64(base + updates::off::game_state),v3;
		std::cout << std::hex << v1 << std::endl;
		LODWORD(v3) = __ROR4__(__ROR4__(v1, 8) - 671638663, 8) ^ 0xD7F79B79;
		HIDWORD(v3) = (HIDWORD(v1) + 1457018393) ^ 0xA927A9E7;
		std::cout << std::hex << v3 << std::dec << std::endl;
		return v3;
	}
};