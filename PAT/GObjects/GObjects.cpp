#include <iostream>
#include "GObjects.h"

FUObjectItem TUObjectArray::GetObjects()
{
	uint64 v7 = Objects;
	uint64 v417;
	LODWORD(v417) = (~(~(_DWORD)v7 ^ 0x37FF03BD) + 1376963086) ^ 0x80EDC9B3;
	HIDWORD(v417) = (~(~HIDWORD(v7) ^ 0x9C2EC6E8) + 1364021710) ^ 0x999C68DA;
	return GameMemory.Read<FUObjectItem>(v417);
}

FUObjectItem TUObjectArray::GetObjects(int i)
{
	uint64 v7 = Objects;
	uint64 v417;
	LODWORD(v417) = (~(~(_DWORD)v7 ^ 0x37FF03BD) + 1376963086) ^ 0x80EDC9B3;
	HIDWORD(v417) = (~(~HIDWORD(v7) ^ 0x9C2EC6E8) + 1364021710) ^ 0x999C68DA;
	return GameMemory.Read<FUObjectItem>(v417 + 0x18 * i);
}

FORCEINLINE int32 UObject::GetInternalIndex() const
{
	uint32 v2 = InternalIndex;
	int32 v9 = v2 ^ (v2 << 16) ^ 0x8B8B1C3D;
	return v9;
}

FORCEINLINE UClass UObject::GetClass() const
{
	uint64 v6 = ClassPrivate;
	uint64 v10 = __ROR8__(v6 ^ 0xE8749E34FEC7EAD7, 10) ^ (__ROR8__(v6 ^ 0xE8749E34FEC7EAD7, 10) << 32) ^ 0xE928C4267DFB45C9;
	return GameMemory.Read<UClass>(v10);
}

FORCEINLINE UObject UObject::GetOuter() const
{
	uint64 v6 = OuterPrivate;
	uint64 v10 = __ROL8__(v6 ^ 0x9259C8617E58D9CF, 1);
	uint64 v11 = v10 ^ (v10 << 32) ^ 0xA91E9E71974BCD96;
	return GameMemory.Read<UObject>(v11);
}

FORCEINLINE uint64 UObject::GetNameID() const
{
	int32 v6 = NamePrivate.ComparisonIndex;
	int32 v10 = NamePrivate.Number;
	int v22, v23;
	v22 = __ROR4__(v6 ^ 0x8104231E, 4) ^ (__ROR4__(v6 ^ 0x8104231E, 4) << 16) ^ 0xA21A8104;
	v23 = __ROR4__(v10 ^ 0x45CB3DFB, 6) ^ (__ROR4__(v10 ^ 0x45CB3DFB, 6) << 16) ^ 0x94107EC7;
	return v23;
}

GObjects::GObjects()
{

}
GObjects::GObjects(uint64 a)
{
	ObjObjects = GameMemory.Read<TUObjectArray>(a);
}

void GObjects::Dump()
{
	
	std::cout << "ObjObjects: 0x" << std::hex << ObjObjects.GetObjects().GetBaseAddress()<< std::endl;
	std::cout << "NumElements: " << std::dec << ObjObjects.GetNumElements() << std::endl;
	std::cout << NameStore.GetActorNameFromID(ObjObjects.GetObjects(100).GetUObject().GetNameID()) << std::endl;

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
		int id = obj.GetInternalIndex();
		std::string name = NameStore.GetActorNameFromID(obj.GetNameID());
		std::string outername = NameStore.GetActorNameFromID(obj.GetOuter().GetNameID());
		std::string classname = "("+ NameStore.GetActorNameFromID(obj.GetClass().GetNameID())+")";
		std::string pathname = outername == "NULL" ? name : outername + " -> " + name;
		int off = obj.offset;
		o << tfm::format("[0x%010X]\t%6d\t[0x%05X]\t%30s\t%s\n", ObjObjects.GetObjects(i).GetBaseAddress(), id,off, classname, pathname);
	}
	o.close();
	system(path.data());
	return;
}
