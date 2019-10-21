#pragma once
#include "AActor.h"

class ULevel : public Base
{
public:
	using Base::Base;

	TArray<AActor*> Actors()
	{
		return GameMemory.Read<TArray<AActor*>>(updates::dec::actor(GameMemory.Read64(base + updates::off::actor)));
	}
};