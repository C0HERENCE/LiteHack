#pragma once
#include "APlayerController.hpp"
#include "UGameViewportClient.hpp"

class ULocalPlayer
{
public:
	uint64 GetPlayerControllerPtr() const;
	APlayerController GetPlayerController() const;
	UGameViewportClient GetViewportClient() const;
	Vector3 GetPosition() const;
	void SetRotation(const FRotator& rot) const;
private:
	char __pad0x30[0x30];
	uint64 m_pPlayerController;
	char __pad0x20[0x20];
	uint64 m_pViewportClient;
	char __pad0x10[0x10];
	Vector3 m_vecPosition;
};