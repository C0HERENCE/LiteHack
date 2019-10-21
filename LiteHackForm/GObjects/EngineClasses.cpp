#include "EngineClasses.h"

int32 UObject::GetInternalIndex() const
{
	return updates::dec::internal_id(GameMemory.Read32(base + updates::off::internal_id));
}

uint64 UObject::GetClass() const
{
	uint64 v14 = GameMemory.Read64(base + updates::off::ulcass);
	uint64 v10 = __ROR8__(v14 ^ 0x3A828B4FDDDA8241, 8) ^ (__ROR8__(v14 ^ 0x3A828B4FDDDA8241, 8) << 32) ^ 0xDA1A7C370173FC15;
	return v10;
}

uint64 UObject::GetOuter() const
{
	uint64 v30 = GameMemory.Read64(base + updates::off::outer);
	uint64 v11 = __ROL8__(v30 ^ 0xA0F2E6BF79BE33CF, 15) ^ (__ROL8__(v30 ^ 0xA0F2E6BF79BE33CF, 15) << 32) ^ 0x5C38004A438F6AD6;
	return v11;
}

int FName::GetComparisonIndex() const
{
	uint32_t v18 = GameMemory.Read32(base + updates::off::comparison_id);
	int v23 = __ROR4__(v18 ^ 0xF528638A, 14) ^ (__ROR4__(v18 ^ 0xF528638A, 14) << 16) ^ 0x96A2F528;
	return v23;
}

int FName::GetNumber() const
{
	uint32_t v14 = GameMemory.Read32(base + updates::off::number);
	int v22 = __ROR4__(v14 ^ 0x9DDA8240, 8) ^ (__ROR4__(v14 ^ 0x9DDA8240, 8) << 16) ^ 0x3D65FC16;
	return v22;
}

FName UObject::GetFName() const
{
	return FName(base + updates::off::name);
}