#pragma once
#include "AActor.h"

class ULevel
{
public:
	ULevel() :base(0) {}
	ULevel(uint64 _base) :base(_base) {}

	TArray<AActor*> GetActors() const
	{
		__int64 v57;
		__int64 v11 = GameMemory.Read64(base + off_AActor);
		LODWORD(v57) = __ROR4__(~__ROR4__(v11, 16) + 301051167, 16) ^ 3993916128;
		HIDWORD(v57) = __ROR4__(~__ROR4__(HIDWORD(v11), 8) - 0x6F416F81, 8) ^ 2428407934;
		return GameMemory.Read<TArray<AActor*>>(v57);
	}

	uint64 GetAddress() const
	{
		return base;
	}
private:
	uint64 base;

	uint64 off_AActor = 0xA8;
};