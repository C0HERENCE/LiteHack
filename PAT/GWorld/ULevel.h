#pragma once
#include "AActor.h"

#define off_Actors 0xA8
class ULevel
{
public:
	TArray<AActor*> GetActors() const
	{
		__int64 v57;
		__int64 v11 = m_Actors.GetAddress();
		LODWORD(v57) = __ROR4__(~__ROR4__(v11, 16) + 301051167, 16) ^ 3993916128;
		HIDWORD(v57) = __ROR4__(~__ROR4__(HIDWORD(v11), 8) - 0x6F416F81, 8) ^ 2428407934;
		return GameMemory.Read<TArray<AActor*>>(v57);
	}
private:
	char __pad0xA0[off_Actors];
	TArray<AActor*> m_Actors;
};