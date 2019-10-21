#pragma once
#include "../Utils/MemoryHelper.h"
#include "Core/FTransform.h"
#include "Base.h"

class USkeletalMeshComponent : public Base
{
public:
	using Base::Base;

	bool RecentlyRendered()
	{
		return GameMemory.Read<bool>(base + updates::off::bRecentlyRendered);
	}

	uint64 BoneArray()
	{
		return GameMemory.Read64(base + updates::off::BoneArray);
	}

	FTransform ComponentToWorld()
	{
		return GameMemory.Read<FTransform>(base + updates::off::ComponentToWorld);
	}
};