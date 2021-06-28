#include "STDInclude.hpp"

namespace Main
{
	static BYTE originalCode[5];
	static PBYTE originalEP = 0;

	void UnprotectModule(HMODULE hModule)
	{
		PIMAGE_DOS_HEADER header = (PIMAGE_DOS_HEADER)hModule;
		PIMAGE_NT_HEADERS ntHeader = (PIMAGE_NT_HEADERS)((DWORD)hModule + header->e_lfanew);

		// unprotect the entire PE image
		SIZE_T size = ntHeader->OptionalHeader.SizeOfImage;
		DWORD oldProtect;
		VirtualProtect((LPVOID)hModule, size, PAGE_EXECUTE_READWRITE, &oldProtect);
	}

	void DoInit()
	{
		// return to the original EP
		memcpy(originalEP, &originalCode, sizeof(originalCode));

		// unprotect our entire PE image
		HMODULE hModule;
		if (SUCCEEDED(GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCWSTR)DoInit, &hModule)))
		{
			UnprotectModule(hModule);
		}

		// detect which executable's patches to apply
		DWORD dataStrData = Utils::Hook::Get<DWORD>(0x59B69C);
		if (dataStrData == 0x6C6C6143)
			MP::PatchT4();
		else
			SP::PatchT4();

		hModule = GetModuleHandle(NULL);
		PIMAGE_DOS_HEADER header = (PIMAGE_DOS_HEADER)hModule;
		PIMAGE_NT_HEADERS ntHeader = (PIMAGE_NT_HEADERS)((DWORD)hModule + header->e_lfanew);

		// back up original code
		originalEP = (PBYTE)((DWORD)hModule + ntHeader->OptionalHeader.AddressOfEntryPoint);

		__asm
		{
			jmp originalEP
		}
	}

	void SetSafeInit()
	{
		// find the entry point for the executable process, set page access, and replace the EP
		HMODULE hModule = GetModuleHandle(NULL); // passing NULL should be safe even with the loader lock being held (according to ReactOS ldr.c)

		if (hModule)
		{
			PIMAGE_DOS_HEADER header = (PIMAGE_DOS_HEADER)hModule;
			PIMAGE_NT_HEADERS ntHeader = (PIMAGE_NT_HEADERS)((DWORD)hModule + header->e_lfanew);

			UnprotectModule(hModule);

			// back up original code
			PBYTE ep = (PBYTE)((DWORD)hModule + ntHeader->OptionalHeader.AddressOfEntryPoint);
			memcpy(originalCode, ep, sizeof(originalCode));

			// patch to call our EP
			int newEP = (int)DoInit - ((int)ep + 5);
			ep[0] = 0xE9; // for some reason this doesn't work properly when run under the debugger
			memcpy(&ep[1], &newEP, 4);

			originalEP = ep;
		}
	}
}


bool APIENTRY DllMain(HMODULE, DWORD dwReason, LPVOID)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		DWORD textSegData = Utils::Hook::Get<DWORD>(0x401000);

		// detection for all executables to hook into
		if (textSegData == 0x0400EC81)
			Main::SetSafeInit();
	}
	return true;
}
