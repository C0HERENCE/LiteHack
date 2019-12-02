#pragma once
#include <Windows.h>
#include <cstdint>
#define USEDRIVER
#ifdef USEDRIVER 
typedef struct readStruct
{
	ULONGLONG UserBufferAdress;
	ULONGLONG GameAddressOffset;
	ULONGLONG ReadSize;
	ULONG     UserPID;
	ULONG     GamePID;
	BOOLEAN   WriteOrRead;
	UINT32	  ProtocolMsg;
} ReadStruct, * pReadStruct;

enum class PROTO_MESSAGE {
	PROTO_NORMAL_READ = 0,
	PROTO_GET_BASEADDR = 1,
	PROTO_NORMAL_WRITE = 2
};

ref class Memory
{
private:
	HANDLE hDriver;

	uint64_t GameBase;

	template<typename T>
	T KernelRead(const uint64_t& w_read, PROTO_MESSAGE readtype)
	{
		T writeMe;
		readStruct rStruct{ (uint64_t)&writeMe, (uint64_t)w_read, sizeof(T), (uint32_t)GetCurrentProcessId(), 0, TRUE, (UINT32)readtype };
		WriteFile(hDriver, (LPCVOID)&rStruct, sizeof(ReadStruct), NULL, NULL);
		return writeMe;
	}

	template<typename T>
	BOOL KernelWrite(T what, const uint64_t& w_write, PROTO_MESSAGE readtype)
	{
		T writeMe = what;
		readStruct rStruct{ (uint64_t)&writeMe, (uint64_t)w_write, sizeof(T), (uint32_t)GetCurrentProcessId(), 0, TRUE, (UINT32)readtype };
		return WriteFile(hDriver, (LPCVOID)&rStruct, sizeof(ReadStruct), NULL, NULL);
	}

public:
	Memory();

	~Memory();

	int Init();

	uint32_t Read32(const uint64_t& w_read);

	uint64_t Read64(const uint64_t& w_read);

	template<typename T>
	bool Write(T what, const uint64_t& w_write)
	{
		return KernelWrite<T>(what, w_write, PROTO_MESSAGE::PROTO_NORMAL_WRITE);
	}

	byte* ReadSize(const int64_t& w_read, const int32_t& w_readSize);

	int64_t GetBase();

	template<typename T> T Read(const uint64_t& w_read)
	{
		return KernelRead<T>(w_read, PROTO_MESSAGE::PROTO_NORMAL_READ);
	}
};;

#endif

#ifndef USEDRIVER
#include <msclr\marshal_cppstd.h>  
ref class Memory
{
public:
	Memory();

	~Memory();

	int Init(HANDLE handle);

	uint32_t Read32(const uint64_t& w_read);

	uint64_t Read64(const uint64_t& w_read);

	byte* ReadSize(const int64_t& w_read, const int32_t& w_readSize);

	int64_t GetBase();

	template<typename T> T Read(const uint64_t& w_read)
	{
		T buff;
		ReadProcessMemory(hProcess, (LPCVOID)w_read, &buff, sizeof(T), NULL);
		return buff;
	}

	template<typename T> bool Write(T what, const uint64_t& w_write)
	{
		return false;
	}

private:
	HANDLE hProcess;

	uint64_t GameBase;
};;
#endif 
