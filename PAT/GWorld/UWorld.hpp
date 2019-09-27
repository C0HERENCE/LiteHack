#pragma once
#include "..//Utils/MemoryHelper.h"
#include "ULevel.hpp"
#include "UGameInstance.hpp"

extern Memory GameMemory;
class UWorld
{
public:
	UWorld();
	UWorld(uint64);
	ULevel GetLevel() const;
	UGameInstance GetGameInstance() const;
private:
	char __pad0x30[0x30];
	uint64 m_pULevel;
	char __pad0x108[0x108];
	uint64 m_pGameInstance;
};
