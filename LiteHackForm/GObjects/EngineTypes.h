#pragma once
#include "..//offsets_decryptions.h"
extern Memory GameMemory;


class FName
{
public:
	FName()
	{

	}
	FName(uint64 _base)
	{
		base = _base;
	}
	int GetComparisonIndex() const;
	int GetNumber() const;
private:
	uint64 base;
};

template<class T>
class TArray
{
	friend struct FString;

public:
	int Length() const
	{
		return m_nCount;
	}

	bool IsValid() const
	{
		if (m_nCount > m_nMax)
			return false;
		if (!m_Data)
			return false;
		return true;
	}

	bool IsValidIndex(uint32 i) const
	{
		return i < m_nCount;
	}

	uint64 GetAddress() const
	{
		return m_Data;
	}

	template<typename U = T>
	typename std::enable_if<std::is_pointer<U>::value, typename std::remove_pointer<U>::type>::type GetValue(uint32 index) const
	{
		auto offset = GameMemory.Read<uint64>(m_Data + sizeof(uint64) * index);
		return GameMemory.Read<typename std::remove_pointer<U>::type>(offset);
	}

	T operator[](size_t i)
	{
		return GameMemory.Read<T>(m_Data + i * sizeof(T));
	};

	const T operator[](size_t i) const
	{
		return GameMemory.Read<T>(m_Data + i * sizeof(T));
	};

	T GetById(int i)
	{
		return T(GameMemory.Read64(m_Data + i * 8));
	}

protected:
	uint64 m_Data;
	uint32 m_nCount;
	uint32 m_nMax;
};


struct FPointer
{
	uintptr_t Dummy;
};

struct FQWord
{
	int A;
	int B;
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
		wchar_t Name[64];
		GameMemory.ReadWString(m_Data, Name, m_nCount * sizeof(wchar_t));
		char text[60];
		sprintf_s(text, "%ls", Name);
		return text;
	}
};

struct FText
{
	char UnknownData[0x18];
};

class FScriptInterface
{
private:
	uint64* ObjectPointer;
	void* InterfacePointer;

public:
	uint64* GetObject() const
	{
		return ObjectPointer;
	}

	uint64*& GetObjectRef()
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