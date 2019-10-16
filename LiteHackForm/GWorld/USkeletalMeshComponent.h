#pragma once
#include "../Utils/MemoryHelper.h"
#include "Base.h"
#include "Core/FTransform.h"

class USkeletalMeshComponent : public Base
{
public:
	using Base::Base;

	bool RecentlyRendered()
	{
		return GameMemory.Read<bool>(base + off_bRecentlyRendered);
	}

	uint64 BoneArray()
	{
		return GameMemory.Read64(base + off_BoneArray);
	}

	FTransform ComponentToWorld()
	{
		return GameMemory.Read<FTransform>(base + off_ComponentToWorld);
	}
private:
	uint64 off_bRecentlyRendered = 0x7d8;
	uint64 off_BoneArray = 0x708;
	uint64 off_ComponentToWorld = 0x110;
};