#include "../Utils/MemoryHelper.h"
#include "FText.hpp"

std::string FTextData::GetName() const
{
	wchar_t entityname[128] = { 0 };
	//memory->read_array(this->m_pName, entityname, sizeof entityname);
	std::wstring ws(entityname);
	std::string ret(ws.begin(), ws.end());
	return ret;
}