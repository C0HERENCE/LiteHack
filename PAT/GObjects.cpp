#include <string>
#include "GObjects.h"
#include <fstream>

void OffsetDumper::Dump()
{
	GNames g;
	g.DecryptGNames(Base + 0x46546C0);

	TUObjectArray  ObjObjects = mh.Read<TUObjectArray>(Base + off_GObjects);
	std::cout << "ObjObjects: 0x" << std::hex << ObjObjects.GetObjects().GetBaseAddress()<< std::endl;
	std::cout << "NumElements: " << std::dec << ObjObjects.GetNumElements() << std::endl;
	std::cout << g.GetActorNameFromID(ObjObjects.GetObjects(100).GetUObject().GetNameID()) << std::endl;

	std::ofstream o;
	SYSTEMTIME st = { 0 };
	GetLocalTime(&st);
	std::string path = "E:\\Desktop\\DUMP\\" + std::to_string(st.wHour) + "_" + std::to_string(st.wMinute) + "_"
		+ std::to_string(st.wSecond) + "_" + std::to_string(st.wMonth) + "_" + std::to_string(st.wDay) + ".txt";
	std::cout << "OutputPath: " << path << std::endl;
	o.open(path);
	for (int i = 0; i < /*500*/ObjObjects.GetNumElements(); i++)
	{
		auto obj = ObjObjects.GetObjects(i).GetUObject();
		o << "===============================" << std::endl;
		o << "Base: 0x" << std::hex << ObjObjects.GetObjects(i).GetBaseAddress() << std::endl;
		o << "ID: " << std::dec << obj.GetInternalIndex() << std::endl;
		o << "Name: " << g.GetActorNameFromID(obj.GetNameID()) << std::endl;
		o << "Class: " << obj.GetClass().GetInternalIndex() << " " << g.GetActorNameFromID(obj.GetClass().GetNameID()) << std::endl;
		o << "Outer: " << obj.GetOuter().GetInternalIndex() << " " << g.GetActorNameFromID(obj.GetOuter().GetNameID()) << std::endl;
	}
	o.close();
	system(path.data());
	return;
}

FORCEINLINE uint64 UObject::GetNameID() const
{
	uint64 v48 = NamePrivate.ComparisonIndex;
	uint64 v45 = NamePrivate.Number;
	uint64 a12;
	LODWORD(a12) = __ROR4__(v48 ^ 0xD0F31505, 12) ^ (__ROR4__(v48 ^ 0xD0F31505, 12) << 16) ^ 0x52070AF0;
	HIDWORD(a12) = __ROR4__(v45 ^ 0xAF058F7, 6) ^ (__ROR4__(v45 ^ 0xAF058F7, 6) << 16) ^ 0xC5F6D0F3;
	return a12;
}

FORCEINLINE uint64 FName::GetComparisonIndex() const
{
	uint32_t v7 = ComparisonIndex;
	uint64 Result = __ROR4__(v7 ^ 0x26B4689, 7) ^ (__ROR4__(v7 ^ 0x26B4689, 7) << 16) ^ 0xD1BB2CBB;
	//uint64 Result = __ROR4__(v7 ^ 0x26B4689, 7) ^ (__ROR4__(v7 ^ 0x26B4689, 7) << 16) ^ 0xD1BB2CBB;
	return Result;
}

FORCEINLINE uint64 FName::GetNumber() const
{
	uint32_t v11 = Number;
	uint64 Result = __ROR4__(v11 ^ 0xBAB0E9E0, 13) ^ (__ROR4__(v11 ^ 0xBAB0E9E0, 13) << 16) ^ 0x5350BAB0;
	return Result;
}

FORCEINLINE int32 UObject::GetInternalIndex() const
{
	uint32 v2 = InternalIndex;
	int32 v9 = __ROL4__(v2 ^ 0x45053BED, 3) ^ (__ROL4__(v2 ^ 0x45053BED, 3) << 16) ^ 0xE87EAEA0;
	return v9;
}

FORCEINLINE UClass UObject::GetClass() const
{
	uint64 v24 = ClassPrivate;
	return mh.Read<UClass>(__ROL8__(v24 ^ 0x665B98933272E58C, 21) ^ (__ROL8__(v24 ^ 0x665B98933272E58C, 21) << 32) ^ 0xBB57415CF335D646);
}

FORCEINLINE FName UObject::GetFName() const
{
	return NamePrivate;
}

FORCEINLINE UObject UObject::GetOuter() const
{
	uint64 v30 = OuterPrivate;
	return mh.Read<UObject>(__ROR8__(v30 ^ 0xE2FFCEA309ED3A2B, 30) ^ (__ROR8__(v30 ^ 0xE2FFCEA309ED3A2B, 30) << 32) ^ 0xD6AECB5A6D8252C0);
}


UObject FUObjectItem::GetUObject()
{
	return mh.Read<UObject>(Object);
}
uint64 FUObjectItem::GetBaseAddress()
{
	return Object;
}


int32_t TUObjectArray::GetNumElements()
{
	return this->NumElements;
}
uint64 TUObjectArray::GetBaseAddress()
{
	return this->Objects;
}

FUObjectItem TUObjectArray::GetObjects()
{
	uint64 v7 = Objects;
	uintptr_t v416;
	LODWORD(v416) = (v7 + 1988483301) ^ 0x85E5D16B;
	HIDWORD(v416) = (HIDWORD(v7) - 1081503205) ^ 0xFB75FBB5;
	return mh.Read<FUObjectItem>(v416);
}
FUObjectItem TUObjectArray::GetObjects(int i)
{
	uint64 v7 = Objects;
	uintptr_t v416;
	LODWORD(v416) = (v7 + 1988483301) ^ 0x85E5D16B;
	HIDWORD(v416) = (HIDWORD(v7) - 1081503205) ^ 0xFB75FBB5;
	return mh.Read<FUObjectItem>(v416 + 0x18 * i);
}