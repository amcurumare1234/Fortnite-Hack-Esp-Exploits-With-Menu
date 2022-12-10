#pragma once
#include <msxml.h>    
#include <atomic>
#include <mutex>
#include <Windows.h>
#include <TlHelp32.h>
#include <cstdint>
#include <vector>
#include <random>
#include <memoryapi.h>
#include <string>
#include <thread>
#include <chrono>
#include <iostream>
#include <string_view>
#include <mutex>
#include <chrono>

static std::mutex mtx;

uint32_t process_id;

class timer
{
private:
	std::chrono::time_point<std::chrono::steady_clock> m_StartTime;

public:
	void Start()
	{
		m_StartTime = std::chrono::high_resolution_clock::now();
	}
	float GetDuration()
	{
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - m_StartTime);
		return duration.count();
	}
};

typedef struct _VEFFY_MEMORY
{
	void* buffer_address;
	UINT_PTR address;
	ULONGLONG size;
	ULONG pid;
	BOOLEAN write;
	BOOLEAN read;
	BOOLEAN req_base;
	void* output;
	const char* module_name;
	ULONG64 base_address;
} VEFFY_MEMORY;

template<typename ... Arg>
uint64_t call_hook(const Arg ... args)
{
	void* hooked_func = GetProcAddress(LoadLibrary(L"win32u.dll"), "NtDxgkGetProcessList");

	auto func = static_cast<uint64_t(_stdcall*)(Arg...)>(hooked_func);

	return func(args ...);
}

struct HandleDisposer
{
	using pointer = HANDLE;
	void operator()(HANDLE handle) const
	{
		if (handle != NULL || handle != INVALID_HANDLE_VALUE)
		{
			CloseHandle(handle);
		}
	}
};

using unique_handle = std::unique_ptr<HANDLE, HandleDisposer>;
extern HANDLE driver_memory_read, driver_memory_write, driver_memory_esp_write;

/*std::uint32_t get_process_id(std::string_view process_name)
{
	PROCESSENTRY32 processentry;
	const unique_handle snapshot_handle(CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL));

	if (snapshot_handle.get() == INVALID_HANDLE_VALUE)
		return NULL;

	processentry.dwSize = sizeof(MODULEENTRY32);

	while (Process32Next(snapshot_handle.get(), &processentry) == TRUE)
	{
		if (process_name.compare(processentry.szExeFile) == NULL)
		{
			return processentry.th32ProcessID;
		}
	}
	return NULL;
}
*/
static ULONG64 get_module_base_address(const char* module_name)
{
	VEFFY_MEMORY instructions = { 0 };
	instructions.pid = process_id;
	instructions.req_base = TRUE;
	instructions.read = FALSE;
	instructions.write = FALSE;
	instructions.module_name = module_name;
	call_hook(&instructions);

	ULONG64 base = NULL;
	base = instructions.base_address;
	return base;
}

template <class T>
T read(uintptr_t read_address)
{
	T response{};
	VEFFY_MEMORY instructions;
	instructions.pid = process_id;
	instructions.size = sizeof(T);
	instructions.address = read_address;
	instructions.read = TRUE;
	instructions.write = FALSE;
	instructions.req_base = FALSE;
	instructions.output = &response;
	call_hook(&instructions);

	return response;
}

static bool read(UINT_PTR address, void* buffer, SIZE_T size)
{
	VEFFY_MEMORY instructions;
	instructions.read = TRUE;
	instructions.write = FALSE;
	instructions.req_base = FALSE;

	instructions.pid = process_id;
	instructions.size = size;
	instructions.address = address;
	instructions.output = buffer;

	call_hook(&instructions);

	return true;
}

template<typename Type>
inline Type ReadChain(uint64_t address, std::vector<uint64_t> chain)
{
	uint64_t current = address;
	for (int i = 0; i < chain.size() - 1; i++)
	{
		current = read<uint64_t>(current + chain[i]);
	}
	return read<Type>(current + chain[chain.size() - 1]);
}

bool write_memory(UINT_PTR write_address, UINT_PTR source_address, SIZE_T write_size)
{
	VEFFY_MEMORY instructions;
	instructions.address = write_address;
	instructions.pid = process_id;
	instructions.write = TRUE;
	instructions.read = FALSE;
	instructions.req_base = FALSE;
	instructions.buffer_address = (void*)source_address;
	instructions.size = write_size;

	call_hook(&instructions);

	return true;
}


template<typename S>
bool write(UINT_PTR write_address, const S& value)
{
	return write_memory(write_address, (UINT_PTR)&value, sizeof(S));
}

inline std::string ReadASCII(uint64_t address)
{
	char buffer[1024];
	read(address, &buffer, 1024);
	return std::string(buffer);
}

inline std::string ReadMonoString(uint64_t address)
{
	char buffer[512];
	address = read<uint64_t>(address);
	read(address, buffer, 512);
	return buffer;
}

inline std::wstring ReadUnicode(uint64_t address)
{
	wchar_t buffer[1024 * sizeof(wchar_t)];
	read(address, &buffer, 1024 * sizeof(wchar_t));
	return std::wstring(buffer);
}

inline std::string ReadNative(uint64_t address)
{
	char buffer[1024];
	read(read<uint64_t>(address), &buffer, 1024);
	return std::string(buffer);
}

static std::string read_string(UINT_PTR String_address, SIZE_T size, bool esp_driver = false)
{
	std::unique_ptr<char[]> buffer(new char[size]);
	read(String_address, buffer.get(), size);
	return std::string(buffer.get());
}

static std::wstring read_wstring(UINT_PTR String_address, SIZE_T size, bool esp_driver = false)
{
	const auto buffer = std::make_unique<wchar_t[]>(size);
	read(String_address, buffer.get(), size * 2);
	return std::wstring(buffer.get());
}
