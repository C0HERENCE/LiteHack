#pragma once
#include "ULocalPlayer.hpp"

class UGameInstance
{
public:
	ULocalPlayer GetLocalPlayer() const;
private:
	char __pad0x38[0x38];
	uint64 m_pULocalPlayer;
};