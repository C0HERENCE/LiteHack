#pragma once
#include "..//Utils/MemoryHelper.h"
#include <type_traits>
extern Memory GameMemory;
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
		return GameMemory.Read<T>(m_Data + i * 8);
	};

	const T operator[](size_t i) const
	{
		return GameMemory.Read<T>(m_Data + i * 8);
	};

private:
	uint64 m_Data;
	uint32 m_nCount;
	uint32 m_nMax;
};
