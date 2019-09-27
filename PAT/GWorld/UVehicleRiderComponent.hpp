#pragma once
#include "AActor.hpp"

class AActor;

class UVehicleRiderComponent
{
public:
	int GetSeatIndex() const;
	AActor GetLastVehiclePawn() const;
private:
	char __pad0x100[0x100];
	int m_nSeatIndex;
	char __pad0x3C[0x3C];
	uint64 m_pLastVehiclePawn;
};
