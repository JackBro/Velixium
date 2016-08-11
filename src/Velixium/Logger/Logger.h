#pragma once

#include "../dll.h"

class Logger
{
private:
	ofstream ofile;
	bool created = false;

public:
	Logger();
	void __cdecl log(const char *fmt, ...);
}; extern Logger logger;