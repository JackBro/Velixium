#include "Proxy.h"

void Proxy::memcpy(ptr_t address, PBYTE value, int len)
{
	for (int i = 0; i < len; ++i)
		engine.memory().Write(address + i, value[i]);
}

void Proxy::memcpy(ptr_t address, vector<uint8_t> value)
{
	for (size_t i = 0; i < value.size(); ++i)
		engine.memory().Write(address + i, value[i]);
}

void Proxy::memcpy(ptr_t address, const char * value)
{
	memcpy(address, vector<uint8_t>(value, value + strlen((const char*)value)));
}

std::vector<uint64_t> Proxy::patternvec(const char * sig)
{
	std::vector<uint64_t> vPattern;
	PatternSearch myPattern(sig);
	myPattern.SearchRemote(engine, 0xCC, engine.modules().GetMainModule()->baseAddress, engine.modules().GetMainModule()->size, vPattern);
	return vPattern;
}

std::vector<uint64_t> Proxy::patternvec(LPCWSTR module, const char * sig)
{
	std::vector<uint64_t> vPattern;
	PatternSearch myPattern(sig);
	myPattern.SearchRemote(engine, 0xCC, GetModule(module)->baseAddress, GetModule(module)->size, vPattern);
	return vPattern;
}

std::vector<uint64_t> Proxy::patternvec(const vector<uint8_t> sig)
{
	std::vector<uint64_t> vPattern;
	PatternSearch myPattern(sig);
	myPattern.SearchRemote(engine, 0xCC, engine.modules().GetMainModule()->baseAddress, engine.modules().GetMainModule()->size, vPattern);
	return vPattern;
}

std::vector<uint64_t> Proxy::patternvec(LPCWSTR module, const vector<uint8_t> sig)
{
	std::vector<uint64_t> vPattern;
	PatternSearch myPattern(sig);
	myPattern.SearchRemote(engine, 0xCC, GetModule(module)->baseAddress, GetModule(module)->size, vPattern);
	return vPattern;
}

DWORD Proxy::pattern(const char* sig)
{
	return (DWORD)patternvec(sig)[0];
}

DWORD Proxy::pattern(const char * sig, int i)
{
	return (DWORD)patternvec(sig)[i];
}

DWORD Proxy::pattern(LPCWSTR module, const char* sig)
{
	return (DWORD)patternvec(module, sig)[0];
}

DWORD Proxy::pattern(LPCWSTR module, const char * sig, int i)
{
	return (DWORD)pattern(module, sig)[&i];
}

const ModuleData * Proxy::GetModule(LPCWSTR module)
{
	return engine.modules().GetModule(module);
}