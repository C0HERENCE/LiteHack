#pragma once
#include "APlayerController.h"

class ULocalPlayer : public Base
{
public:
	using Base::Base;
	APlayerController PlayerController() const
	{
		return APlayerController(updates::dec::playercontroller(GameMemory.Read64(base + updates::off::playerconroller)));
	}
};
