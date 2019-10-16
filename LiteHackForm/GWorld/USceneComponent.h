#pragma once
#include "Base.h"
#include "./Core/FVector.h"

class USceneComponent : public Base
{
public:
	using Base::Base;

	FVector ComponentVelocity()
	{
		return GameMemory.Read<FVector>(base+off_Velocity);
	}

	FVector Location()
	{
		return  GameMemory.Read<FVector>(base + off_Location);
	}

	bool Visible()
	{
		return  GameMemory.Read<bool>(base + off_Visible);
	}
private:
	uint64 off_ComponentToWorld = 0x110;
	uint64 off_Location = 0x120;
	uint64 off_Velocity = 0x238;
	uint64 off_Visible = 0x1f1;
};