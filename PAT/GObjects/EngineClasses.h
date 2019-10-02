#pragma once
#include "../Utils/MemoryHelper.h"
#include "..//GWorld/TArray.hpp"
extern Memory GameMemory;

class UObject;

struct FPointer
{
	uintptr_t Dummy;
};

struct FQWord
{
	int A;
	int B;
};

class FName
{
public:
	int GetComparisonIndex() const;
	int GetNumber() const;
public:
	uint32_t Number = 0;
	uint32_t ComparisonIndex = 0;
};

template<typename KeyType, typename ValueType>
class TPair
{
public:
	KeyType   Key;
	ValueType Value;
};

struct FString : public TArray<wchar_t>
{
	std::string ToString() const
	{
		int size = WideCharToMultiByte(CP_UTF8, 0, (LPCWCH)m_Data, m_nCount, nullptr, 0, nullptr, nullptr);
		std::string str(size, 0);
		WideCharToMultiByte(CP_UTF8, 0, (LPCWCH)m_Data, m_nCount, &str[0], size, nullptr, nullptr);
		return str;
	}
};

struct FText
{
	char UnknownData[0x18];
};

class FScriptInterface
{
private:
	UObject* ObjectPointer;
	void* InterfacePointer;

public:
	UObject* GetObject() const
	{
		return ObjectPointer;
	}

	UObject*& GetObjectRef()
	{
		return ObjectPointer;
	}

	void* GetInterface() const
	{
		return ObjectPointer != nullptr ? InterfacePointer : nullptr;
	}
};

struct FWeakObjectPtr
{
	int32_t ObjectIndex;
	int32_t ObjectSerialNumber;
};


struct FStringAssetReference
{
	FString AssetLongPathname;
};

template<typename TObjectID>
class TPersistentObjectPtr
{
public:
	FWeakObjectPtr WeakPtr;
	int32_t TagAtLastTest;
	TObjectID ObjectID;
};

class FAssetPtr : public TPersistentObjectPtr<FStringAssetReference>
{

};

struct FGuid
{
	uint32_t A;
	uint32_t B;
	uint32_t C;
	uint32_t D;
};

struct FUniqueObjectGuid
{
	FGuid Guid;
};

class FLazyObjectPtr : public TPersistentObjectPtr<FUniqueObjectGuid>
{

};

struct FScriptDelegate
{
	unsigned char UnknownData[20];
};

struct FScriptMulticastDelegate
{
	unsigned char UnknownData[16];
};

class UClass;

class UObject
{
public:
	FPointer VTableObject;
	FName Name;
	int32_t InternalIndex;
	int32_t ObjectFlags;
	uint64 Outer;
	uint64 Class;
	uint64 unknown;
public:
	int32_t GetInternalIndex() const;
	uint64 GetClass() const;
	FName GetFName() const;
	uint64 GetOuter() const;
};

class UField : public UObject
{
public:
	uint64 Next;//UField
};

class UEnum : public UField
{
public:
	FString CppType;
	TArray<TPair<FName, uint64_t>> Names; 
	__int64 CppForm; 
	char unknown[2][8];
};

class UStruct : public UField
{
public:
	char unknown1[1][8]; //0x0038
	uint32_t MinAlignment; //0x0040
	int32_t unknown2[3]; //0x0044
	uint64_t Children; //0x0050
	char unknown3[4][8]; //0x0058
	uint64_t Children2; //0x0078ufield
	uint32_t PropertySize; //0x0080
	uint32_t unknown4; //0x0084
	uint64_t SuperField; //0x0088ustruct
	uint64_t unknown5; //0x0090
};

class UScriptStruct : public UStruct
{
public:
	char unknown[2][8]; //0x0098
};

class UFunction : public UStruct
{
public:
	__int32 FunctionFlags; //0x0088
	__int16 RepOffset; //0x008C
	__int8 NumParms; //0x008E
	char pad_0x008F[0x1]; //0x008F
	__int16 ParmsSize; //0x0090
	__int16 ReturnValueOffset; //0x0092
	__int16 RPCId; //0x0094
	__int16 RPCResponseId; //0x0096
	class UProperty* FirstPropertyToInit; //0x0098
	UFunction* EventGraphFunction; //0x00A0
	__int32 EventGraphCallOffset; //0x00A8
	char pad_0x00AC[0x4]; //0x00AC
	void* Func; //0x00B0
	uint64 pad;
};

class UClass : public UStruct
{
public:
	int8_t unknown[58]; //0x0098
};

class UProperty : public UField
{
public:
	uint32_t ArrayDim; //0x0038
	uint32_t ElementSize; //0x003C
	FQWord PropertyFlags; //0x0040
	uint32_t unknown1; //0x0048
	uint32_t Offset; //0x004C
	uint64_t FirstChildren; //0x0050
	uint64_t NextChildren; //0x0058
	uint32_t PropertySize; //0x0080
	uint32_t unknown3[5]; //0x0078
};


class UNumericProperty : public UProperty
{
public:

};

class UByteProperty : public UNumericProperty
{
public:
	uint64 Enum;
};

class UUInt16Property : public UNumericProperty
{
public:

};

class UUInt32Property : public UNumericProperty
{
public:

};

class UUInt64Property : public UNumericProperty
{
public:

};

class UInt8Property : public UNumericProperty
{
public:

};

class UInt16Property : public UNumericProperty
{
public:

};

class UIntProperty : public UNumericProperty
{
public:

};

class UInt64Property : public UNumericProperty
{
public:

};

class UFloatProperty : public UNumericProperty
{
public:

};

class UDoubleProperty : public UNumericProperty
{
public:

};

class UBoolProperty : public UProperty
{
public:
	uint8_t FieldSize;
	uint8_t ByteOffset;
	uint8_t ByteMask;
	uint8_t FieldMask;
};

class UObjectPropertyBase : public UProperty
{
public:
	uint64 PropertyClass;
};

class UObjectProperty : public UObjectPropertyBase
{
public:

};

class UClassProperty : public UObjectProperty
{
public:
	uint64 MetaClass;
};

class UInterfaceProperty : public UProperty
{
public:
	uint64 InterfaceClass;
};

class UWeakObjectProperty : public UObjectPropertyBase
{
public:

};

class ULazyObjectProperty : public UObjectPropertyBase
{
public:

};

class UAssetObjectProperty : public UObjectPropertyBase
{
public:

};

class UAssetClassProperty : public UAssetObjectProperty
{
public:
	uint64 MetaClass;
};

class UNameProperty : public UProperty
{
public:

};

class UStructProperty : public UProperty
{
public:
	uint64 Struct;
};

class UStrProperty : public UProperty
{
public:

};

class UTextProperty : public UProperty
{
public:

};

class UArrayProperty : public UProperty
{
public:
	uint64 Inner;
};

class UMapProperty : public UProperty
{
public:
	uint64 KeyProp;
	uint64 ValueProp;
};

class UDelegateProperty : public UProperty
{
public:
	uint64 SignatureFunction;
};

class UMulticastDelegateProperty : public UProperty
{
public:
	uint64 SignatureFunction;
};

class UEnumProperty : public UProperty
{
public:
	uint64 UnderlyingProp; //0x0070
	uint64 Enum; //0x0078
}; //Size: 0x008
