#pragma once
#include <string>
#include <vector>
#include "EngineClasses.h"
#include "..//GNames/NamesStore.h"
#include "..//GObjects/ObjectsStore.h"

extern NamesStore GlobalNames;

class UEClass;
class UEObject
{
public:
	UEObject()
		: object(0)
	{
	}
	UEObject(uint64 _object)
		: object(_object)
	{
	}

	bool IsValid() const
	{
		return object != 0;
	}

	int GetIndex() const;

	UEClass GetClass() const;

	UEObject GetOuter() const;

	std::string GetName() const;

	std::string GetFullName() const;

	std::string GetNameCPP() const;

	UEObject GetPackageObject() const;

	uint64 GetAddress() const;

	template<typename Base>
	Base Cast() const
	{
		return Base(object);
	}

	template<typename T>
	bool IsA() const;

	static UEClass StaticClass();

protected:
	uint64 object;
};

class UEField : public UEObject
{
public:
	using UEObject::UEObject;

	UEField GetNext() const;

	static UEClass StaticClass();
};

/*
UEField: 
		UEEnum
		UEConst
		UEStruct
		UEProperty
*/
class UEEnum : public UEField
{
public:
	using UEField::UEField;

	std::vector<std::string> GetNames() const;
	static UEClass StaticClass();
};

class UEConst : public UEField
{
public:
	using UEField::UEField;

	std::string GetValue() const;

	static UEClass StaticClass();
};

class UEStruct : public UEField
{
public:
	using UEField::UEField;

	UEStruct GetSuper() const;

	UEField GetChildren() const;

	size_t GetPropertySize() const;

	static UEClass StaticClass();
};

class UEProperty : public UEField
{
public:
	using UEField::UEField;

	size_t GetArrayDim() const;

	size_t GetElementSize() const;

	size_t GetOffset() const;
	
	static UEClass StaticClass();
};

/*
UEStruct:
		UEScriptStruct
		UEClass
*/
class UEScriptStruct : public UEStruct
{
public:
	using UEStruct::UEStruct;

	static UEClass StaticClass();
};

class UEClass : public UEStruct
{
public:
	using UEStruct::UEStruct;

	static UEClass StaticClass();
};

template<typename T>
bool UEObject::IsA() const
{
	auto cmp = T::StaticClass();
	if (!cmp.IsValid())
	{
		return false;
	}

	for (auto super = GetClass(); super.IsValid(); super = super.GetSuper().Cast<UEClass>())
	{
		if (super.object == cmp.object)
		{
			return true;
		}
	}

	return false;
}