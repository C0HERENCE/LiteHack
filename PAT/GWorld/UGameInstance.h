#pragma once
#include "ULocalPlayer.h"

class UGameInstance : public Base
{
public:
	using Base::Base;

	ULocalPlayer LocalPlayer()
	{
		uint64 v8 = GameMemory.Read64(base + off_ULocalPlayer), v14;
		v8 = GameMemory.Read64(v8);
		LODWORD(v14) = ((v8 ^ 0x17CA73EB) - 88419610) ^ 0x3070A10D;
		HIDWORD(v14) = ((HIDWORD(v8) ^ 0x6449A658) - 114951770) ^ 0x1193A002;
		return ULocalPlayer(v14);
	}
private:
	uint64 off_ULocalPlayer = 0xE0;
};