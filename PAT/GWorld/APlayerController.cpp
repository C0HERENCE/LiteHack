#include "..//Utils/MemoryHelper.h"
#include "APlayerController.hpp"

FRotator APlayerController::GetControlRotation() const
{
	return this->m_ControlRotation;
}

AActor APlayerController::GetLocalPlayer() const
{
	return GameMemory.Read<AActor>(this->m_pLocalPlayer);
}

uintptr_t APlayerController::GetLocalPlayerPtr() const
{
	return this->m_pLocalPlayer;
}

APlayerCameraManager APlayerController::GetPlayerCameraManager() const
{
	return GameMemory.Read<APlayerCameraManager>(this->m_pPlayerCameraManager);
}

