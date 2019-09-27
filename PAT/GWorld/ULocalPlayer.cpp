#include "../Utils/MemoryHelper.h"
#include "ULocalPlayer.hpp"
extern Memory GameMemory;
uintptr_t ULocalPlayer::GetPlayerControllerPtr() const
{
	return this->m_pPlayerController;
}

APlayerController ULocalPlayer::GetPlayerController() const
{
	return GameMemory.Read<APlayerController>(this->m_pPlayerController);
}

UGameViewportClient ULocalPlayer::GetViewportClient() const
{
	return GameMemory.Read<UGameViewportClient>(this->m_pViewportClient);
}

Vector3 ULocalPlayer::GetPosition() const
{
	return this->m_vecPosition;
}

void ULocalPlayer::SetRotation(const FRotator& rot) const
{
	//memory->write(this->m_pPlayerController + 0x03D0, rot);
}