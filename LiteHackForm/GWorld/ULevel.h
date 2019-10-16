#pragma once
#include "AActor.h"

class ULevel : public Base
{
public:
	using Base::Base;

	TArray<AActor*> Actors()
	{
		__int64 v57;
		__int64 v11 = GameMemory.Read64(base + off_AActor);
		LODWORD(v57) = __ROR4__(~__ROR4__(v11, 16) + 301051167, 16) ^ 3993916128;
		HIDWORD(v57) = __ROR4__(~__ROR4__(HIDWORD(v11), 8) - 0x6F416F81, 8) ^ 2428407934;
		return GameMemory.Read<TArray<AActor*>>(v57);
	}

private:
	uint64 off_AActor = 0xA8;
};