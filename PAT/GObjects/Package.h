#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <filesystem>

namespace fs = std::experimental::filesystem;

#include "GenericTypes.h"



class Package
{
	friend bool operator==(const Package& lhs, const Package& rhs);
public:
	Package(const UEObject& packageObj);

	std::string GetName() const { return packageObj.GetName(); }

	void Process(std::unordered_map<uint64, bool>& processedObjects);

	bool Save() const;

private:
	UEObject packageObj;

	struct Enum
	{
		std::string Name;
		std::string FullName;
		std::vector<std::string> Values;
	};
	std::vector<Enum> enums;
	void GenerateEnum(const UEEnum& enumObj);

	struct Member
	{
		std::string Name;
		std::string Type;

		size_t Offset;
		size_t Size;

		size_t Flags;
		std::string FlagsString;

		std::string Comment;
	};


	std::unordered_map<std::string, std::string> constants;
	void GenerateConst(const UEConst& constObj);



	struct ScriptStruct
	{
		std::string Name;
		std::string FullName;
		std::string NameCpp;
		std::string NameCppFull;
		int Size;
		int InheritedSize;
		std::vector<Member> Members;
	};

	std::vector<ScriptStruct> scriptStructs;
	static Member CreatePadding(size_t id, size_t offset, size_t size, std::string reason);

	static Member CreateBitfieldPadding(size_t id, size_t offset, std::string type, size_t bits);

	void GenerateMembers(const UEStruct& structObj, size_t offset, const std::vector<UEProperty>& properties, std::vector<Member>& members) const;

	void GenerateScriptStruct(const UEScriptStruct& scriptStructObj);

	void GenerateClass(const UEClass& classObj);

};

inline bool operator==(const Package& lhs, const Package& rhs) { return rhs.packageObj.GetAddress() == lhs.packageObj.GetAddress(); }
inline bool operator!=(const Package& lhs, const Package& rhs) { return !(lhs == rhs); }
