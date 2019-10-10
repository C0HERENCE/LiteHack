#include "EngineClasses.h"
int32 UObject::GetInternalIndex() const
{
	uint32 v2 = InternalIndex;
	int32 v9 = __ROL4__(v2 ^ 0x36B3F56F, 8) ^ (__ROL4__(v2 ^ 0x36B3F56F, 8) << 16) ^ 0xDCC3C1DF;
	return v9;
}

uint64 UObject::GetClass() const
{
	uint64 v6 = Class;
	uint64 v10 = __ROR8__(v6 ^ 0x20C7F75F93A0C001, 2) ^ (__ROR8__(v6 ^ 0x20C7F75F93A0C001, 2) << 32) ^ 0x6AA2584BBC71DB5D;
	return v10;
}

uint64 UObject::GetOuter() const
{
	uint64 v18 = Outer;
	uint64 v11 = __ROL8__(v18 ^ 0x49163DE10DD4AC1B, 9) ^ (__ROL8__(v18 ^ 0x49163DE10DD4AC1B, 9) << 32) ^ 0xA879C16B49E8AB0E;
	return v11;
}

int FName::GetComparisonIndex() const
{
	uint32_t v10 = ComparisonIndex;
	int v23 = __ROR4__(v10 ^ 0xBC799C4A, 1) ^ (__ROR4__(v10 ^ 0xBC799C4A, 1) << 16) ^ 0x64C6297F;
	return v23;
}

int FName::GetNumber() const
{
	uint32_t v6 = Number;
	int v22 = __ROR4__(v6 ^ 0x273C2F05, 5) ^ (__ROR4__(v6 ^ 0x273C2F05, 5) << 16) ^ 0xA48E792F;
	return v22;
}

FName UObject::GetFName() const
{
	return Name;
}