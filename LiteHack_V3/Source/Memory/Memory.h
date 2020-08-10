#pragma once
#include <Windows.h>
#include <cstdint>

typedef struct _MEMORY_STRUCT
{
	BYTE type;
	LONG usermode_pid;
	LONG target_pid;
	ULONG64 base_address;
	void* address;
	LONG size;
	void* output;
}MEMORY_STRUCT;

enum class PROTO_MESSAGE : uint8_t {
	TEST = 1,
	CLEAN1 = 2,
	CLEAN2 = 8,
	CLEAN3 = 9,
	GETBASE_DUMMY = 5,
	GETBASE_RAINBOWSIX = 6,
	GETBASE_PUBGLITE = 10,
	GETBASE_PUBG = 11,
	GETBASE_FORTNIGHT = 12,
	READ = 3,
	WRITE = 7,
};

class Memory
{
private:
	uint64_t GameBase;
	HANDLE hProcess = 0;
	// void* control_function = 0;
	// LONG UsermodePID;
	// LONG TargetPID;

	// template<typename ... A>
	// uint64_t call_hook(const A ... arguments)
	// {
	// 	const auto control = static_cast<uint64_t(__stdcall*)(A...)>(control_function);
	// 	return control(arguments ...);
	// }

	// template<typename T>
	// T KernelRead(const uint64_t& w_read)
	// {
	// 	T writeMe{};
	// 	if (w_read > 0x7FFFFFFFFFFF || w_read < 1) return T();
	// 	int size = sizeof(T);
	// 	MEMORY_STRUCT rStruct
	// 	{
	// 		(BYTE)PROTO_MESSAGE::READ, UsermodePID, TargetPID, GameBase, (void*)w_read, size, &writeMe
	// 	};
	// 	call_hook(&rStruct);
	// 	return writeMe;
	// }

	// template<typename T>
	// BOOL KernelWrite(T what, const uint64_t& w_write)
	// {
	// 	T writeMe{};
	// 	if (w_write > 0x7FFFFFFFFFFF || w_write < 1) return false;
	// 	int size = sizeof(T);
	// 	MEMORY_STRUCT rStruct
	// 	{
	// 		(BYTE)PROTO_MESSAGE::WRITE, UsermodePID, TargetPID, GameBase, (T*)w_write, size, &writeMe
	// 	};
	// 	return call_hook(&rStruct);
	// }

public:
	Memory();

	~Memory();

	int Init();

	uint32_t Read32(const uint64_t& w_read);

	uint64_t Read64(const uint64_t& w_read);

	template<typename T>
	bool Write(const uint64_t& w_write, T what)
	{
		// return KernelWrite<T>(what, w_write);
		return false;
	}

	byte* ReadSize(const int64_t& w_read, const int32_t& w_readSize);

	int64_t GetBase();

	template<typename T> T Read(const uint64_t& w_read)
	{
		// return KernelRead<T>(w_read);
		T buff;
		ReadProcessMemory(hProcess, (LPCVOID)w_read, &buff, sizeof(T), NULL);
		return buff;
	}
};
