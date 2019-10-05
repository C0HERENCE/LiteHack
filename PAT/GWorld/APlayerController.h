#pragma once
#include "../Utils/MemoryHelper.h"

class APlayerController
{
public:
	APlayerController() :base(0) {}

	APlayerController(uint64 _base) :base(_base) {}

	AActor GetLocalPawn() const
	{
		return AActor(GameMemory.Read64(base + off_LocalPawn));
	}

	uint64 GetAddress() const
	{
		return base;
	}

private:
	uint64 base;

	uint64 off_LocalPawn = 0x1050;
};