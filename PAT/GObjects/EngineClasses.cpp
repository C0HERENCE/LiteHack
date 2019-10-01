#include "EngineClasses.h"
int32 UObject::GetInternalIndex() const
{
	uint32 v2 = InternalIndex;
	int32 v9 = v2 ^ (v2 << 16) ^ 0x8B8B1C3D;
	return v9;
}

uint64 UObject::GetClass() const
{
	uint64 v6 = Class;
	uint64 v10 = __ROR8__(v6 ^ 0xE8749E34FEC7EAD7, 10) ^ (__ROR8__(v6 ^ 0xE8749E34FEC7EAD7, 10) << 32) ^ 0xE928C4267DFB45C9;
	return v10;
}

uint64 UObject::GetOuter() const
{
	uint64 v6 = Outer;
	uint64 v10 = __ROL8__(v6 ^ 0x9259C8617E58D9CF, 1);
	uint64 v11 = v10 ^ (v10 << 32) ^ 0xA91E9E71974BCD96;
	return v11;
}

int FName::GetComparisonIndex() const
{
	uint32_t v10 = ComparisonIndex;
	int v23 = __ROR4__(v10 ^ 0x45CB3DFB, 6) ^ (__ROR4__(v10 ^ 0x45CB3DFB, 6) << 16) ^ 0x94107EC7;
	return v23;
}

int FName::GetNumber() const
{
	uint32_t v6 = Number;
	int v22 = __ROR4__(v6 ^ 0x8104231E, 4) ^ (__ROR4__(v6 ^ 0x8104231E, 4) << 16) ^ 0xA21A8104;
	return v22;
}

FName UObject::GetFName() const
{
	return Name;
}