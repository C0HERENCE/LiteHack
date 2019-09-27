#include "..//Utils/MemoryHelper.h"
#include "UVehicleRiderComponent.hpp"

int UVehicleRiderComponent::GetSeatIndex() const
{
	return this->m_nSeatIndex;
}

AActor UVehicleRiderComponent::GetLastVehiclePawn() const
{
	return GameMemory.Read<AActor>(this->m_pLastVehiclePawn);
}
