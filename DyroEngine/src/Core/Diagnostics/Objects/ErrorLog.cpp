#include "Core\Diagnostics\Objects\ErrorLog.h"

#include "Core\Types\LogType.h"

#include "Core\Defines\consolecolors.h"
#include "Core/Defines/iostream.h"
#include "Core/Defines/stringstream.h"

#ifndef _WINDOWS_
#include <Windows.h>
#endif

ErrorLog::ErrorLog(const std::tstring& m, int ln, const std::tstring& fn)
	:Log(LogType::ERROR_LOG, m, ln, fn)
{
	std::tstringstream buffer;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	buffer << _T("Error Message") << _T(" ERROR: ") << getMessage().c_str();
	buffer << _T("\nFound in file: ") << getFileName();
	buffer << _T("\nAt linenumber: ") << getLineNumber();
	buffer << _T("\n");

	std::tcout << _T("ERROR: ") << getMessage().c_str() << std::endl;
	OutputDebugString(buffer.str().c_str());

	updateMessage(buffer.str().c_str());
}
ErrorLog::~ErrorLog()
{}

const std::tstring ErrorLog::toString() const
{
	std::tstringstream buffer;
	buffer << _T("LogMessage Type: Error") << std::endl << getMessage();
	return buffer.str();
}