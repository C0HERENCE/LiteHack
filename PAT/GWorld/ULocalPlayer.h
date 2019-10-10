#pragma once
#include "APlayerController.h"

class ULocalPlayer : public Base
{
public:
	using Base::Base;
	APlayerController PlayerController() const
	{
		unsigned __int64 v7 = GameMemory.Read64(base + off_PlayerController);
		unsigned __int64 v8;
		unsigned int v9;
		__int64 v10;
		v8 = v7 >> 32,
			v9 = (v7 & 0xFFFF0000 | (unsigned __int16)v7 ^ ((unsigned int)v7 >> 16)) + 779007602,
			LODWORD(v10) = ((v9 >> 16) ^ (unsigned __int16)v9 | ((unsigned __int16)__ROR2__(HIWORD(v9), 8) << 16)) ^ 0x2E6EB672,
			HIDWORD(v10) = ((((unsigned __int16)__ROR2__(WORD2(v7) ^ WORD1(v8), 8) | ((unsigned __int16)__ROR2__(WORD1(v8), 8) << 16)) + 758197682) & 0xFFFF0000 | (unsigned __int16)__ROR2__(
			(__ROR2__(WORD2(v7) ^ WORD1(v8), 8) + 11698) ^ ((((unsigned __int16)__ROR2__(WORD2(v7) ^ WORD1(v8), 8) | ((unsigned int)(unsigned __int16)__ROR2__(WORD1(v8), 8) << 16)) + 758197682) >> 16),
				8)) ^ 0xD2CED24E;
		return APlayerController(v10);
	}

private:
	uint64 off_PlayerController = 0x38;
};
