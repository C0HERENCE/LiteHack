#pragma once
#include "GenericTypes.h"
#include "NameValidator.h"

int UEObject::GetIndex() const
{
	return uobject.GetInternalIndex();
}

UEClass UEObject::GetClass() const
{
	return UEClass(uobject.GetClass());
}

UEObject UEObject::GetOuter() const
{
	return UEObject(uobject.GetOuter());
}

std::string UEObject::GetName() const
{
	UObject uobj = uobject;
	auto name = GlobalNames.GetById(uobj.GetFName().GetComparisonIndex());
	if (uobj.GetFName().GetNumber()>0)
	{
		name += '_' + std::to_string(uobj.GetFName().GetNumber());
	}

	auto pos = name.rfind('/');
	if (pos == std::string::npos)
	{
		return name;
	}

	return name.substr(pos + 1);
}

uint64 UEObject::GetAddress() const
{
	return object;
}

UEObject UEObject::GetPackageObject() const
{
	UEObject package(0);

	for (auto outer = GetOuter(); outer.IsValid(); outer = outer.GetOuter())
	{
		package = outer;
	}

	return package;
}

std::string UEObject::GetFullName() const
{
	if (GetClass().IsValid())
	{
		std::string temp;

		for (auto outer = GetOuter(); outer.IsValid(); outer = outer.GetOuter())
		{
			temp = outer.GetName() + "." + temp;
		}

		std::string name = GetClass().GetName();
		name += " ";
		name += temp;
		name += GetName();

		return name;
	}

	return std::string("(null)");
}

std::string UEObject::GetNameCPP() const
{
	std::string name;

	if (IsA<UEClass>())
	{
		auto c = Cast<UEClass>();
		while (c.IsValid())
		{
			const auto className = c.GetName();
			if (className == "Actor")
			{
				name += "A";
				break;
			}
			if (className == "Object")
			{
				name += "U";
				break;
			}

			c = c.GetSuper().Cast<UEClass>();
		}
	}
	else
	{
		name += "F";
	}

	name += GetName();

	return name;
}

UEClass UEObject::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.Object");
	return c;
}

UEField UEField::GetNext() const
{
	return UEField(GameMemory.Read<UField>(object).Next);
}

UEClass UEField::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.Field");
	return c;
}

std::vector<std::string> UEEnum::GetNames() const
{
	std::vector<std::string> buffer;
	auto names = GameMemory.Read<UEnum>(object).Names;

	for (auto i = 0; i < names.Length(); ++i)
	{
		buffer.push_back(GlobalNames.GetById(names[i].Key.ComparisonIndex));
	}

	return buffer;
}

UEClass UEEnum::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.Enum");
	return c;
}

std::string UEConst::GetValue() const
{
	throw;
}

UEClass UEConst::StaticClass()
{
	return 0;
}

UEStruct UEStruct::GetSuper() const
{
	return UEStruct(GameMemory.Read<UStruct>(object).SuperField);
}

UEField UEStruct::GetChildren() const
{
	return UEField(GameMemory.Read<UStruct>(object).Children);
}

size_t UEStruct::GetPropertySize() const
{
	return GameMemory.Read<UStruct>(object).PropertySize;
}

UEClass UEStruct::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.Struct");
	return c;
}

UEClass UEScriptStruct::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.ScriptStruct");
	return c;
}

//---------------------------------------------------------------------------
//UEFunction
//---------------------------------------------------------------------------
UEFunctionFlags UEFunction::GetFunctionFlags() const
{
	return static_cast<UEFunctionFlags>(GameMemory.Read<UFunction>(object).FunctionFlags);
}
//---------------------------------------------------------------------------
UEClass UEFunction::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.Function");
	return c;
}

UEClass UEClass::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.Class");
	return c;
}
//---------------------------------------------------------------------------
//UEProperty
//---------------------------------------------------------------------------
size_t UEProperty::GetArrayDim() const
{
	return GameMemory.Read<UProperty>(object).ArrayDim;
}

size_t UEProperty::GetElementSize() const
{
	return GameMemory.Read<UProperty>(object).ElementSize;
}

size_t UEProperty::GetOffset() const
{
	return GameMemory.Read<UProperty>(object).Offset;
}

UEClass UEProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.Property");
	return c;
}

UEProperty::Info UEProperty::GetInfo() const
{
	if (IsValid())
	{
		if (IsA<UEByteProperty>())
		{
			return Cast<UEByteProperty>().GetInfo();
		}
		if (IsA<UEUInt16Property>())
		{
			return Cast<UEUInt16Property>().GetInfo();
		}
		if (IsA<UEUInt32Property>())
		{
			return Cast<UEUInt32Property>().GetInfo();
		}
		if (IsA<UEUInt64Property>())
		{
			return Cast<UEUInt64Property>().GetInfo();
		}
		if (IsA<UEInt8Property>())
		{
			return Cast<UEInt8Property>().GetInfo();
		}
		if (IsA<UEInt16Property>())
		{
			return Cast<UEInt16Property>().GetInfo();
		}
		if (IsA<UEIntProperty>())
		{
			return Cast<UEIntProperty>().GetInfo();
		}
		if (IsA<UEInt64Property>())
		{
			return Cast<UEInt64Property>().GetInfo();
		}
		if (IsA<UEFloatProperty>())
		{
			return Cast<UEFloatProperty>().GetInfo();
		}
		if (IsA<UEDoubleProperty>())
		{
			return Cast<UEDoubleProperty>().GetInfo();
		}
		if (IsA<UEBoolProperty>())
		{
			return Cast<UEBoolProperty>().GetInfo();
		}
		if (IsA<UEObjectProperty>())
		{
			return Cast<UEObjectProperty>().GetInfo();
		}
		if (IsA<UEClassProperty>())
		{
			return Cast<UEClassProperty>().GetInfo();
		}
		if (IsA<UEInterfaceProperty>())
		{
			return Cast<UEInterfaceProperty>().GetInfo();
		}
		if (IsA<UEWeakObjectProperty>())
		{
			return Cast<UEWeakObjectProperty>().GetInfo();
		}
		if (IsA<UELazyObjectProperty>())
		{
			return Cast<UELazyObjectProperty>().GetInfo();
		}
		if (IsA<UEEncryptedObjectProperty>())
		{
			return Cast<UEEncryptedObjectProperty>().GetInfo();
		}/*
		if (IsA<UEAssetClassProperty>())
		{
			return Cast<UEAssetClassProperty>().GetInfo();
		}*/
		
		if (IsA<UENameProperty>())
		{
			return Cast<UENameProperty>().GetInfo();
		}
		if (IsA<UEStructProperty>())
		{
			return Cast<UEStructProperty>().GetInfo();
		}
		if (IsA<UEStrProperty>())
		{
			return Cast<UEStrProperty>().GetInfo();
		}
		if (IsA<UETextProperty>())
		{
			return Cast<UETextProperty>().GetInfo();
		}
		if (IsA<UEArrayProperty>())
		{
			return Cast<UEArrayProperty>().GetInfo();
		}
		if (IsA<UEMapProperty>())
		{
			return Cast<UEMapProperty>().GetInfo();
		}
		if (IsA<UEDelegateProperty>())
		{
			return Cast<UEDelegateProperty>().GetInfo();
		}
		if (IsA<UEMulticastDelegateProperty>())
		{
			return Cast<UEMulticastDelegateProperty>().GetInfo();
		}
		if (IsA<UEEnumProperty>())
		{
			return Cast<UEEnumProperty>().GetInfo();
		}
	}
	return { PropertyType::Unknown };
}
//---------------------------------------------------------------------------
//UENumericProperty
//---------------------------------------------------------------------------
UEClass UENumericProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.NumericProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEByteProperty
//---------------------------------------------------------------------------
bool UEByteProperty::IsEnum() const
{
	return GetEnum().IsValid();
}
UEEnum UEByteProperty::GetEnum() const
{
	UEObject(object).GetAddress();
	return UEEnum(GameMemory.Read<UByteProperty>(object).Enum);
}
//---------------------------------------------------------------------------
UEProperty::Info UEByteProperty::GetInfo() const
{
	if (IsEnum())
	{
		return Info::Create(PropertyType::Primitive, sizeof(uint8_t), false, "TEnumAsByte<" + MakeUniqueCppName(GetEnum()) + ">");
	}
	return Info::Create(PropertyType::Primitive, sizeof(uint8_t), false, "unsigned char");
}
//---------------------------------------------------------------------------
UEClass UEByteProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.ByteProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEUInt16Property
//---------------------------------------------------------------------------
UEProperty::Info UEUInt16Property::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(uint16_t), false, "uint16_t");
}
//---------------------------------------------------------------------------
UEClass UEUInt16Property::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.UInt16Property");
	return c;
}
//---------------------------------------------------------------------------
//UEUInt32Property
//---------------------------------------------------------------------------
UEProperty::Info UEUInt32Property::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(uint32_t), false, "uint32_t");
}
//---------------------------------------------------------------------------
UEClass UEUInt32Property::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.UInt32Property");
	return c;
}

//---------------------------------------------------------------------------
//UEUInt64Property
//---------------------------------------------------------------------------
UEProperty::Info UEUInt64Property::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(uint64_t), false, "uint64_t");
}
//---------------------------------------------------------------------------
UEClass UEUInt64Property::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.UInt64Property");
	return c;
}
//---------------------------------------------------------------------------
//UEInt8Property
//---------------------------------------------------------------------------
UEProperty::Info UEInt8Property::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(int8_t), false, "int8_t");
}
//---------------------------------------------------------------------------
UEClass UEInt8Property::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.Int8Property");
	return c;
}
//---------------------------------------------------------------------------
//UEInt16Property
//---------------------------------------------------------------------------
UEProperty::Info UEInt16Property::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(int16_t), false, "int16_t");
}
//---------------------------------------------------------------------------
UEClass UEInt16Property::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.Int16Property");
	return c;
}
//---------------------------------------------------------------------------
//UEIntProperty
//---------------------------------------------------------------------------
UEProperty::Info UEIntProperty::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(int), false, "int");
}
//---------------------------------------------------------------------------
UEClass UEIntProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.IntProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEInt64Property
//---------------------------------------------------------------------------
UEProperty::Info UEInt64Property::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(int64_t), false, "int64_t");
}
//---------------------------------------------------------------------------
UEClass UEInt64Property::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.Int64Property");
	return c;
}
//---------------------------------------------------------------------------
//UEFloatProperty
//---------------------------------------------------------------------------
UEProperty::Info UEFloatProperty::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(float), false, "float");
}
//---------------------------------------------------------------------------
UEClass UEFloatProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.FloatProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEDoubleProperty
//---------------------------------------------------------------------------
UEProperty::Info UEDoubleProperty::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(double), false, "double");
}
//---------------------------------------------------------------------------
UEClass UEDoubleProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.DoubleProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEBoolProperty
//---------------------------------------------------------------------------
uint8_t UEBoolProperty::GetFieldSize() const
{
	return GameMemory.Read<UBoolProperty>(object).FieldSize;
}
//---------------------------------------------------------------------------
uint8_t UEBoolProperty::GetByteOffset() const
{
	return GameMemory.Read<UBoolProperty>(object).ByteOffset;
}
//---------------------------------------------------------------------------
uint8_t UEBoolProperty::GetByteMask() const
{
	return GameMemory.Read<UBoolProperty>(object).ByteMask;
}
//---------------------------------------------------------------------------
uint8_t UEBoolProperty::GetFieldMask() const
{
	return GameMemory.Read<UBoolProperty>(object).FieldMask;
}
//---------------------------------------------------------------------------
UEProperty::Info UEBoolProperty::GetInfo() const
{
	if (IsNativeBool())
	{
		return Info::Create(PropertyType::Primitive, sizeof(bool), false, "bool");
	}
	return Info::Create(PropertyType::Primitive, sizeof(unsigned char), false, "unsigned char");
}
//---------------------------------------------------------------------------
UEClass UEBoolProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.BoolProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEObjectPropertyBase
//---------------------------------------------------------------------------
UEClass UEObjectPropertyBase::GetPropertyClass() const
{
	return UEClass(GameMemory.Read<UObjectPropertyBase>(object).PropertyClass);
}
//---------------------------------------------------------------------------
UEClass UEObjectPropertyBase::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.ObjectPropertyBase");
	return c;
}

//---------------------------------------------------------------------------
//UEObjectProperty
//---------------------------------------------------------------------------
UEProperty::Info UEObjectProperty::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(void*), false, "class " + MakeValidName(GetPropertyClass().GetNameCPP()) + "*");
}
//---------------------------------------------------------------------------
UEClass UEObjectProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.ObjectProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEEncryptedObjectProperty
//---------------------------------------------------------------------------
UEProperty::Info UEEncryptedObjectProperty::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(void*), false, "class " + MakeValidName(GetPropertyClass().GetNameCPP()) + "*");
}
//---------------------------------------------------------------------------
UEClass UEEncryptedObjectProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.EncryptedObjectProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEClassProperty
//---------------------------------------------------------------------------
UEClass UEClassProperty::GetMetaClass() const
{
	return UEClass(GameMemory.Read<UClassProperty>(object).MetaClass);
}
//---------------------------------------------------------------------------
UEProperty::Info UEClassProperty::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(void*), false, "class " + MakeValidName(GetMetaClass().GetNameCPP()) + "*");
}
//---------------------------------------------------------------------------
UEClass UEClassProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.ClassProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEInterfaceProperty
//---------------------------------------------------------------------------
UEClass UEInterfaceProperty::GetInterfaceClass() const
{
	return UEClass(GameMemory.Read<UInterfaceProperty>(object).InterfaceClass);
}
//---------------------------------------------------------------------------
UEProperty::Info UEInterfaceProperty::GetInfo() const
{
	return Info::Create(PropertyType::PredefinedStruct, sizeof(FScriptInterface), true, "TScriptInterface<class " + MakeValidName(GetInterfaceClass().GetNameCPP()) + ">");
}
//---------------------------------------------------------------------------
UEClass UEInterfaceProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.InterfaceProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEWeakObjectProperty
//---------------------------------------------------------------------------
UEProperty::Info UEWeakObjectProperty::GetInfo() const
{
	return Info::Create(PropertyType::Container, sizeof(FWeakObjectPtr), false, "TWeakObjectPtr<class " + MakeValidName(GetPropertyClass().GetNameCPP()) + ">");
}
//---------------------------------------------------------------------------
UEClass UEWeakObjectProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.WeakObjectProperty");
	return c;
}
//---------------------------------------------------------------------------
//UELazyObjectProperty
//---------------------------------------------------------------------------
UEProperty::Info UELazyObjectProperty::GetInfo() const
{
	return Info::Create(PropertyType::Container, sizeof(FLazyObjectPtr), false, "TLazyObjectPtr<class " + MakeValidName(GetPropertyClass().GetNameCPP()) + ">");
}
//---------------------------------------------------------------------------
UEClass UELazyObjectProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.LazyObjectProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEAssetObjectProperty
//---------------------------------------------------------------------------
UEProperty::Info UEAssetObjectProperty::GetInfo() const
{
	return Info::Create(PropertyType::Container, sizeof(FAssetPtr), false, "TAssetPtr<class >");
}
//---------------------------------------------------------------------------
UEClass UEAssetObjectProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.AssetObjectProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEAssetClassProperty
//---------------------------------------------------------------------------
UEClass UEAssetClassProperty::GetMetaClass() const
{
	return UEClass(GameMemory.Read<UAssetClassProperty>(object).MetaClass);
}
//---------------------------------------------------------------------------
UEProperty::Info UEAssetClassProperty::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(uint8_t), false, "");
}
//---------------------------------------------------------------------------
UEClass UEAssetClassProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.AssetClassProperty");
	return c;
}
//---------------------------------------------------------------------------
//UENameProperty
//---------------------------------------------------------------------------
UEProperty::Info UENameProperty::GetInfo() const
{
	return Info::Create(PropertyType::PredefinedStruct, sizeof(FName), true, "struct FName");
}
//---------------------------------------------------------------------------
UEClass UENameProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.NameProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEStructProperty
//---------------------------------------------------------------------------
UEScriptStruct UEStructProperty::GetStruct() const
{
	return UEScriptStruct(GameMemory.Read<UStructProperty>(object).Struct);
}
//---------------------------------------------------------------------------
UEProperty::Info UEStructProperty::GetInfo() const
{
	return Info::Create(PropertyType::CustomStruct, GetElementSize(), true, "struct " + MakeUniqueCppName(GetStruct()));
}
//---------------------------------------------------------------------------
UEClass UEStructProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.StructProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEStrProperty
//---------------------------------------------------------------------------
UEProperty::Info UEStrProperty::GetInfo() const
{
	return Info::Create(PropertyType::PredefinedStruct, sizeof(FString), true, "struct FString");
}
//---------------------------------------------------------------------------
UEClass UEStrProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.StrProperty");
	return c;
}
//---------------------------------------------------------------------------
//UETextProperty
//---------------------------------------------------------------------------
UEProperty::Info UETextProperty::GetInfo() const
{
	return Info::Create(PropertyType::PredefinedStruct, sizeof(FText), true, "struct FText");
}
//---------------------------------------------------------------------------
UEClass UETextProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.TextProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEArrayProperty
//---------------------------------------------------------------------------
UEProperty UEArrayProperty::GetInner() const
{
	return UEProperty(GameMemory.Read<UArrayProperty>(object).Inner);
}
//---------------------------------------------------------------------------
UEProperty::Info UEArrayProperty::GetInfo() const
{
	auto inner = GetInner().GetInfo();
	if (inner.Type != PropertyType::Unknown)
	{
		return Info::Create(PropertyType::Container, sizeof(TArray<void*>), false, "TArray<" + inner.CppType + ">");
	}

	return { PropertyType::Unknown };
}
//---------------------------------------------------------------------------
UEClass UEArrayProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.ArrayProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEMapProperty
//---------------------------------------------------------------------------
UEProperty UEMapProperty::GetKeyProperty() const
{
	return UEProperty(GameMemory.Read<UMapProperty>(object).KeyProp);
}
//---------------------------------------------------------------------------
UEProperty UEMapProperty::GetValueProperty() const
{
	return UEProperty(GameMemory.Read<UMapProperty>(object).ValueProp);
}
//---------------------------------------------------------------------------
UEProperty::Info UEMapProperty::GetInfo() const
{
	auto key = GetKeyProperty().GetInfo();
	auto value = GetValueProperty().GetInfo();
	if (key.Type != PropertyType::Unknown && value.Type != PropertyType::Unknown)
	{
		return Info::Create(PropertyType::Container, 0x50, false, "TMap<" + key.CppType + ", " + value.CppType + ">");
	}

	return { PropertyType::Unknown };
}
//---------------------------------------------------------------------------
UEClass UEMapProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.MapProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEDelegateProperty
//---------------------------------------------------------------------------
UEFunction UEDelegateProperty::GetSignatureFunction() const
{
	return UEFunction(GameMemory.Read<UDelegateProperty>(object).SignatureFunction);
}
//---------------------------------------------------------------------------
UEProperty::Info UEDelegateProperty::GetInfo() const
{
	return Info::Create(PropertyType::PredefinedStruct, sizeof(FScriptDelegate), true, "struct FScriptDelegate");
}
//---------------------------------------------------------------------------
UEClass UEDelegateProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.DelegateProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEMulticastDelegateProperty
//---------------------------------------------------------------------------
UEFunction UEMulticastDelegateProperty::GetSignatureFunction() const
{
	return UEFunction(GameMemory.Read<UDelegateProperty>(object).SignatureFunction);
}
//---------------------------------------------------------------------------
UEProperty::Info UEMulticastDelegateProperty::GetInfo() const
{
	return Info::Create(PropertyType::PredefinedStruct, sizeof(FScriptMulticastDelegate), true, "struct FScriptMulticastDelegate");
}
//---------------------------------------------------------------------------
UEClass UEMulticastDelegateProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.MulticastDelegateProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEEnumProperty
//---------------------------------------------------------------------------
UENumericProperty UEEnumProperty::GetUnderlyingProperty() const
{
	return UENumericProperty(GameMemory.Read<UEnumProperty>(object).UnderlyingProp);
}
//---------------------------------------------------------------------------
UEEnum UEEnumProperty::GetEnum() const
{
	return UEEnum(GameMemory.Read<UEnumProperty>(object).Enum);
}
//---------------------------------------------------------------------------
UEProperty::Info UEEnumProperty::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(uint8_t), false, MakeUniqueCppName(GetEnum()));
}
//---------------------------------------------------------------------------
UEClass UEEnumProperty::StaticClass()
{
	static auto c = GlobalObjects.FindClass("Class CoreUObject.EnumProperty");
	return c;
}
//------------------------


int GetBitPosition(uint8_t value)
{
	int i4 = !(value & 0xf) << 2;
	value >>= i4;

	int i2 = !(value & 0x3) << 1;
	value >>= i2;

	int i1 = !(value & 0x1);

	int i0 = (value >> i1) & 1 ? 0 : -8;

	return i4 + i2 + i1 + i0;
}

std::array<int, 2> UEBoolProperty::GetMissingBitsCount(const UEBoolProperty & other) const
{
	// If there is no previous bitfield member, just calculate the missing bits.
	if (!other.IsValid())
	{
		return { GetBitPosition(GetByteMask()), -1 };
	}

	// If both bitfield member belong to the same byte, calculate the bit position difference.
	if (GetOffset() == other.GetOffset())
	{
		return { GetBitPosition(GetByteMask()) - GetBitPosition(other.GetByteMask()) - 1, -1 };
	}

	// If they have different offsets, we need two distances
	// |00001000|00100000|
	// 1.   ^---^
	// 2.       ^--^

	return { std::numeric_limits<uint8_t>::digits - GetBitPosition(other.GetByteMask()) - 1, GetBitPosition(GetByteMask()) };
}