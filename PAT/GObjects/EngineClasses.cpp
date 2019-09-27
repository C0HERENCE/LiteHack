#include "EngineClasses.h"

FORCEINLINE uint64 FName::GetComparisonIndex() const
{
	uint32_t v7 = ComparisonIndex;
	uint64 Result = __ROR4__(v7 ^ 0x26B4689, 7) ^ (__ROR4__(v7 ^ 0x26B4689, 7) << 16) ^ 0xD1BB2CBB;
	return Result;
}

FORCEINLINE uint64 FName::GetNumber() const
{
	uint32_t v11 = Number;
	uint64 Result = __ROR4__(v11 ^ 0xBAB0E9E0, 13) ^ (__ROR4__(v11 ^ 0xBAB0E9E0, 13) << 16) ^ 0x5350BAB0;
	return Result;
}


FORCEINLINE FName UObject::GetFName() const
{
	return NamePrivate;
}



UObject FUObjectItem::GetUObject()
{
	return GameMemory.Read<UObject>(Object);
}
uint64 FUObjectItem::GetBaseAddress()
{
	return Object;
}


uint32 TUObjectArray::GetNumElements()
{
	return this->NumElements;
}
uint64 TUObjectArray::GetBaseAddress()
{
	return this->Objects;
}

