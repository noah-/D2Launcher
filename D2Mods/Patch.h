#pragma once
#include <vector>
#include <string>
#include <windows.h>
enum PatchType { Jump = 0xE9, Call = 0xE8, NOP = 0x90, Push = 0x6A };

class Patch {
public:
	std::vector<Patch*> Patches;
	PatchType type;
	int offset, length, function;
	BYTE* oldCode;
	bool injected;
	Patch(PatchType type, int offset, int function, int length) : type(type), function(function), length(length) {
		oldCode = new BYTE[length];
		injected = false;
		this->offset = (DWORD)GetModuleHandle(NULL) + offset;
		//Patches.push_back(this);
	}
	bool WriteBytes(int address, int len, BYTE* bytes) {
		DWORD dwOld;
		if (!VirtualProtect((void*)address, len, PAGE_READWRITE, &dwOld)) return FALSE;
		::memcpy((void*)address, bytes, len);
		return !!VirtualProtect((void*)address, len, dwOld, &dwOld);
	}
	bool Install() {
		if (injected) return true;
		BYTE* code = new BYTE[length];
		DWORD protect;
		ReadProcessMemory(GetCurrentProcess(), (void*)offset, oldCode, length, NULL);
		memset(code, 0x90, length);
		if (type != NOP) {
			code[0] = type;
			if (type == Call || type == Jump) *(DWORD*)&code[1] = function - (offset + 5);
			else code[1] = function;
		}
		VirtualProtect((VOID*)offset, length, PAGE_EXECUTE_READWRITE, &protect);
		memcpy_s((VOID*)offset, length, code, length);
		VirtualProtect((VOID*)offset, length, protect, &protect);
		injected = true;
		return true;
	}

	bool Remove() {
		if (!injected) return true;
		DWORD protect;
		VirtualProtect((VOID*)offset, length, PAGE_EXECUTE_READWRITE, &protect);
		memcpy_s((VOID*)offset, length, oldCode, length);
		VirtualProtect((VOID*)offset, length, protect, &protect);
		injected = false;
		return true;
	}
};
