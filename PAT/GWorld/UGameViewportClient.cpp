#include "..//Utils/MemoryHelper.h"
#include "UGameViewportClient.hpp"
#include "UWorld.hpp"

UWorld UGameViewportClient::GetWorld() const
{
	return GameMemory.Read<UWorld>(this->m_pUWorld);
}
