#pragma once
#include "Utils/ida_defs.h"
#include "Utils/MemoryHelper.h"
#include "LiteSDK/AActor.hpp"

extern MemoryHelper mem;
template<typename T>
uint64 GetUInt64(T x)
{
	return HIDWORD(x);
}
uint64 ULevelDec(INT64 v5)
{
	uint64 v8; 
	v8 = __PAIR__(HIDWORD(v5) + 1391176432, (signed int)v5 + 1873351966);
	return v8;
}
INT64 GameInstanceDec(INT64 v1)
{
	int v2;
	int v3;
	__int64 v5; 
	v2 = __ROR4__(v1, 16);
	LODWORD(v1) = __ROR4__(HIDWORD(v1), 8);
	v3 = __ROR4__(~v2 + 1901170111, 16);
	LODWORD(v1) = __ROR4__(~(DWORD)v1 - 262213601, 8);
	LODWORD(v5) = v3 ^ 0x8EAE7240;
	HIDWORD(v5) = v1 ^ 0xF05EF01E;
	return v5;
}
INT64 ActorDec(INT64 v8)
{
	int v9;
	int v10; 
	__int64 v14; 
	v9 = __ROL4__(v8 - 480998769, 8);
	LODWORD(v8) = __ROR4__(HIDWORD(v8) + 1425397112, 16);
	v10 = __ROR4__(v9 - 2122023344, 16);
	LODWORD(v8) = __ROR4__(v8 + 1914069977, 8);
	LODWORD(v14) = v10 ^ 0xF2FF3C1;
	HIDWORD(v14) = v8 ^ 0x71DF719F;

	return v14;
}

class ULevel
{
public:
	TArray<AActor*> GetActors() const
	{
		return mem.Read<TArray<AActor*>>(ActorDec(m_Actors.GetAddress()));
	}
private:
	char __pad0xA0[0x190];
	TArray<AActor*> m_Actors;
};


class UWorld
{
public:
	ULevel GetLevel() const
	{
		return mem.Read<ULevel>(ULevelDec((this->m_pULevel)));
	}
	uint64 GetGameInstance() const
	{
		return GameInstanceDec(this->m_pGameInstance);
	}
private:
	char __pad0x30[0x548];
	uintptr_t m_pULevel;
	char __pad0x108[0xA78- 0x548-0x8];
	uintptr_t m_pGameInstance;
};
