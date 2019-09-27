#pragma once
#include <cstdint>
#include <type_traits>
#include "..//..//Utils/MemoryHelper.h"
extern MemoryHelper mem;
template<class T>
class TArray
{
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

	bool IsValidIndex(int32_t i) const
	{
		return i < m_nCount;
	}

	uint64 GetAddress() const
	{
		return m_Data;
	}

	template<typename U = T>
	typename std::enable_if<std::is_pointer<U>::value, typename std::remove_pointer<U>::type>::type GetValue(int32_t index) const
	{
		auto offset = mem.Read<uintptr_t>(m_Data + sizeof(uintptr_t) * index);
		return mem.Read<typename std::remove_pointer<U>::type>(offset);
	}
private:
	uintptr_t m_Data;
	int32_t m_nCount;
	int32_t m_nMax;
};
