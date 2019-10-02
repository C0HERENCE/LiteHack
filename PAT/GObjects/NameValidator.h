#pragma once
#include <string>

class UEConst;
class UEEnum;
class UEStruct;
std::string MakeValidName(std::string&& name);

std::string SimplifyEnumName(std::string&& name);

std::string MakeUniqueCppName(const UEConst& c);
std::string MakeUniqueCppName(const UEEnum& e);
std::string MakeUniqueCppName(const UEStruct& ss);
