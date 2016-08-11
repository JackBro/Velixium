#pragma once

#include "../dll.h"

#define PROXY_FUNC_SETUP(x) x = (t##x) engine.modules().GetExport(this->hModule, #x).procAddress

class WinAPIBase
{
protected:
	const ModuleData* hModule;
public:
	WinAPIBase(LPCWSTR szModuleName) : hModule(nullptr)
	{
		this->hModule = engine.modules().GetModule(szModuleName);
	}
};

class Proxy : public WinAPIBase
{
public:
	typedef short(WINAPI *tGetAsyncKeyState) (_In_ int vKey); tGetAsyncKeyState GetAsyncKeyState;
	typedef int(WINAPI *tMessageBoxA) (_In_ HWND hWnd, _In_ LPCTSTR lpText, _In_ LPCTSTR lpCaption, _In_ UINT uType); tMessageBoxA MessageBoxA;

	Proxy() : WinAPIBase(L"User32.dll")
	{
		PROXY_FUNC_SETUP(GetAsyncKeyState);
		PROXY_FUNC_SETUP(MessageBoxA);
	}

	const ModuleData* GetModule(LPCWSTR module);

	void memcpy(ptr_t address, PBYTE value, int len);
	void memcpy(ptr_t address, vector<uint8_t> value);
	void memcpy(ptr_t address, const char* value);

	std::vector<uint64_t> patternvec(const char* sig);
	std::vector<uint64_t> patternvec(LPCWSTR module, const char* sig);
	std::vector<uint64_t> patternvec(const vector<uint8_t> sig);
	std::vector<uint64_t> patternvec(LPCWSTR module, const vector<uint8_t> sig);
	DWORD pattern(const char* sig);
	DWORD pattern(const char* sig, int i);
	DWORD pattern(LPCWSTR module, const char* sig);
	DWORD pattern(LPCWSTR module, const char* sig, int i);
}; extern Proxy* proxy;