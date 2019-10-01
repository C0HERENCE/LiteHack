#pragma once
#include "ObjectsStore.h"

ObjectsStore::ObjectsStore()
{

}

ObjectsStore::ObjectsStore(uint64 address)
{
	Initialize(address);
}

bool ObjectsStore::Initialize(uint64 address)
{
	privateGO = GameMemory.Read<FUObjectArray>(address);
	uint64 v7 = privateGO.ObjObjects.Objects;
	uint64 v417;
	LODWORD(v417) = (~(~(_DWORD)v7 ^ 0x37FF03BD) + 1376963086) ^ 0x80EDC9B3;
	HIDWORD(v417) = (~(~HIDWORD(v7) ^ 0x9C2EC6E8) + 1364021710) ^ 0x999C68DA;
	privateGO.ObjObjects.Objects = v417;
	return true;
}

UEObject ObjectsStore::GetById(size_t id) const
{
	return UEObject(privateGO.ObjObjects.GetById(id).Object);
}

UEClass ObjectsStore::FindClass(const std::string& name) const
{
	for (int i=0;i< GetObjectsNum();i++)
	{
		UEObject obj = UEObject(privateGO.ObjObjects.GetById(i).Object);
		if (obj.GetFullName() == name)
		{
			return obj.Cast<UEClass>();
		}
	}
	return UEClass(0);
}

int ObjectsStore::GetObjectsNum() const
{
	return privateGO.ObjObjects.NumElements;
}
