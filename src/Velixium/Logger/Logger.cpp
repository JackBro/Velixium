#include "Logger.h"

Logger::Logger()
{
}

void __cdecl Logger::log(const char *fmt, ...)
{
	if (!created)
	{
		DeleteFile("C:\\log.txt");
		ofile.open("C:\\log.txt", ios::app);
		created = true;
	}

	va_list va_alist;
	char logbuf[256] = { 0 };

	va_start(va_alist, fmt);
	_vsnprintf(logbuf + strlen(logbuf), sizeof(logbuf) - strlen(logbuf), fmt, va_alist);
	va_end(va_alist);

	ofile << logbuf << endl;
}