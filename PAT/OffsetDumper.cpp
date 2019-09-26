#include <string>
#include "GObjects.h"


void OffsetDumper::Dump()
{
	GNames g;
	g.dec(Base + 0x4414608);

	TUObjectArray  ObjObjects = mh.Read<TUObjectArray>(Base + off_GObjects);
	std::cout << ObjObjects.GetNumElements() << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << ObjObjects.GetObjects(i).GetUObject().GetInternalIndex() << std::endl;
		std::cout << ObjObjects.GetObjects(i).GetUObject().GetOuter()..GetInternalIndex() << std::endl;
	}
}

FORCEINLINE int32 FName::GetComparisonIndex() const
{

}

FORCEINLINE uint32 FName::GetNumber() const
{
	uint64 v11 = Number;
	const auto Result = __ROR4__(v11 ^ 0xBAB0E9E0, 13) ^ (__ROR4__(v11 ^ 0xBAB0E9E0, 13) << 16) ^ 0x5350BAB0;
	return Result;
}

FORCEINLINE int32 UObject::GetInternalIndex() const
{
	uint64 v2 = InternalIndex;
	const auto Result = __ROL4__(v2 ^ 0x94FD461F, 15) ^ (__ROL4__(v2 ^ 0x94FD461F, 15) << 16) ^ 0xE2D20468;
	return Result;
}

FORCEINLINE UClass UObject::GetClass() const
{
	uint64 v7 = ClassPrivate;
	const auto Result = __ROR8__(v7 ^ 0x5B1BB84A026B468B, 7) ^ (__ROR8__(v7 ^ 0x5B1BB84A026B468B, 7) << 32) ^ 0x3BEA36863D002CBA;
	return mh.Read<UClass>(Result);
}

FORCEINLINE FName UObject::GetFName() const
{
	return NamePrivate;
}

FORCEINLINE UObject UObject::GetOuter() const
{
	uint64 v18 = OuterPrivate;
	const auto Result = __ROL8__(v18 ^ 0xD2963CAE2C53FB47, 14) ^ (__ROL8__(v18 ^ 0xD2963CAE2C53FB47, 14) << 32) ^ 0xCA20019DE5A9C103;
	return mh.Read<UObject>(Result);
}
int32_t TUObjectArray::GetNumElements()
{
	return this->NumElements;
}
FUObjectItem TUObjectArray::GetObjects()
{
	uint64 v7 = Objects;
	uint64 v17;
	LODWORD(v17) = (v7 - 433362667) ^ 0x55B5619B; // ObjObjects dec
	HIDWORD(v17) = (HIDWORD(v7) + 797991499) ^ 0x2B452B85;
	return mh.Read<FUObjectItem>(v17);
}
FUObjectItem TUObjectArray::GetObjects(int i)
{
	uint64 v7 = Objects;
	uint64 v17;
	LODWORD(v17) = (v7 - 433362667) ^ 0x55B5619B; // ObjObjects dec
	HIDWORD(v17) = (HIDWORD(v7) + 797991499) ^ 0x2B452B85;
	return mh.Read<FUObjectItem>(v17+0x18*i);
}
UObject FUObjectItem::GetUObject()
{
	return mh.Read<UObject>(Object);
}