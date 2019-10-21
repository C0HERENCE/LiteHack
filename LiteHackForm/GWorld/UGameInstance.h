#pragma once
#include "ULocalPlayer.h"

class UGameInstance : public Base
{
public:
	using Base::Base;

	ULocalPlayer LocalPlayer()
	{
		return ULocalPlayer(updates::dec::localplayer(GameMemory.Read64(GameMemory.Read64(base + updates::off::localplayer))));
	}
};