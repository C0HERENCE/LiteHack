#pragma once
#include "./Core/FVector.h"
#include "Base.h"

class USceneComponent : public Base
{
public:
	using Base::Base;

	FVector ComponentVelocity()
	{
		return GameMemory.Read<FVector>(base+updates::off::Velocity);
	}

	FVector Location()
	{
		return  GameMemory.Read<FVector>(base + updates::off::Location);
	}

	bool Visible()
	{
		return  GameMemory.Read<bool>(base + updates::off::Visible);
	}
};