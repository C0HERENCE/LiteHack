#include "..//Utils/MemoryHelper.h"
#include "UGameInstance.hpp"

ULocalPlayer UGameInstance::GetLocalPlayer() const
{
	auto pLocalPlayer = GameMemory.Read<uintptr_t>(this->m_pULocalPlayer);
	return GameMemory.Read<ULocalPlayer>(pLocalPlayer);
}
