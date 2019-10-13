#pragma once
#include "EngineTypes.h"

class UObject
{
protected:
	uint64 base;
	uint64 off_Name = 0xc;
	uint64 off_Outer = 0x18;
	uint64 off_Class = 0x20;
	uint64 off_InternalIndex = 0x28;
public:
	UObject(uint64 _base)
	{
		base = _base;
	}
	UObject()
	{

	}
	int32_t GetInternalIndex() const;
	uint64 GetClass() const;
	FName GetFName() const;
	uint64 GetOuter() const;
};

class UField : public UObject
{
	using UObject::UObject;
public:
	uint64 Next() const
	{
		return GameMemory.Read64(UObject::base + 0x30);
	}
};

class UEnum : public UField, public UObject
{
	using UObject::UObject;
public:
	TArray<TPair<FName, uint64_t>> Names()
	{
		return GameMemory.Read<TArray<TPair<FName, uint64_t>>>(UObject::base + 0x48);
	}
};

class UStruct : public UField , public UObject
{
	using UObject::UObject;
public:
	uint64_t SuperField()
	{
		return GameMemory.Read64(UObject::base + 0x38);
	}
	uint32_t PropertySize()
	{
		return GameMemory.Read32(UObject::base + 0x68);
	}
	uint64_t Children()
	{
		return GameMemory.Read64(UObject::base + 0x80);
	}
};

class UScriptStruct : public UStruct
{
public:
};

class UFunction : public UStruct
{
public:
	__int32 FunctionFlags;
};

class UClass : public UStruct
{
public:
};

class UProperty : public UField, public UObject
{
	using UObject::UObject;
public:
	uint32_t ArrayDim()
	{
		return GameMemory.Read32(UObject::base + 0x38);
	}
	uint32_t ElementSize()
	{
		return GameMemory.Read32(UObject::base + 0x3c);
	}
	uint32_t Offset()
	{
		return GameMemory.Read32(UObject::base + 0x4c);
	}
	uint64_t FirstChildren()
	{
		return GameMemory.Read64(UObject::base + 0x50);
	}
	uint64_t NextChildren()
	{
		return GameMemory.Read64(UObject::base + 0x58);
	}
	uint32_t PropertySize()
	{
		return GameMemory.Read32(UObject::base + 0x80);
	}
};


class UNumericProperty : public UProperty
{
public:

};

class UByteProperty : public UNumericProperty ,public UObject
{
	using UObject::UObject;
public:
	uint64 Enum()
	{
		return GameMemory.Read64(UObject::base + 120);
	}
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

class UBoolProperty : public UProperty, public UObject
{
	using UObject::UObject;
public:
	uint8_t FieldSize()
	{
		return GameMemory.Read<uint8_t>(UObject::base + 0x78);
	}
	uint8_t ByteOffset()
	{
		return GameMemory.Read<uint8_t>(UObject::base + 0x7a);
	}
	uint8_t ByteMask()
	{
		return GameMemory.Read<uint8_t>(UObject::base + 0x7c);
	}
	uint8_t FieldMask()
	{
		return GameMemory.Read<uint8_t>(UObject::base + 0x7e);
	}
};

class UObjectPropertyBase : public UProperty, public UObject
{
	using UObject::UObject;
public:
	uint64 PropertyClass()
	{
		return GameMemory.Read64(UObject::base + 0x78);
	}
};

class UObjectProperty : public UObjectPropertyBase
{
public:

};

class UClassProperty : public UObjectProperty, public UObject
{
	using UObject::UObject;
public:
	uint64 MetaClass()
	{
		return GameMemory.Read64(UObject::base + 0x80);
	}
};

class UInterfaceProperty : public UProperty, public UObject
{
	using UObject::UObject;
public:
	uint64 InterfaceClass()
	{
		return GameMemory.Read64(UObject::base + 0x78);
	}
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

class UAssetClassProperty : public UAssetObjectProperty, public UObject
{
	using UObject::UObject;
public:
	uint64 MetaClass()
	{
		return GameMemory.Read64(UObject::base + 0x80);
	}
};

class UNameProperty : public UProperty
{
public:

};

class UStructProperty : public UProperty, public UObject
{
	using UObject::UObject;
public:
	uint64 Struct()
	{
		return GameMemory.Read64(UObject::base + 0x78);
	}
};

class UStrProperty : public UProperty
{
public:

};

class UTextProperty : public UProperty
{
public:

};

class UArrayProperty : public UProperty, public UObject
{
	using UObject::UObject;
public:
	uint64 Inner()
	{
		return GameMemory.Read64(UObject::base + 0x78);
	}
};

class UMapProperty : public UProperty, public UObject
{
	using UObject::UObject;
public:
	uint64 KeyProp()
	{
		return GameMemory.Read64(UObject::base + 0x78);
	}
	uint64 ValueProp()
	{
		return GameMemory.Read64(UObject::base + 0x80);
	}
};

class UDelegateProperty : public UProperty, public UObject
{
	using UObject::UObject;
public:
	uint64 SignatureFunction()
	{
		return GameMemory.Read64(UObject::base + 0x78);
	}
};

class UMulticastDelegateProperty : public UProperty
{
public:
	uint64 SignatureFunction()
	{
		return GameMemory.Read64(UObject::base + 0x78);
	}
};

class UEnumProperty : public UProperty, public UObject
{
	using UObject::UObject;
public:
	uint64 UnderlyingProp()
	{
		return GameMemory.Read64(UObject::base + 0x78);
	}
	uint64 Enum()
	{
		return GameMemory.Read64(UObject::base + 0x80);
	}
};