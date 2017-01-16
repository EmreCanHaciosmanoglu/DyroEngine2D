#include "Core\Diagnostics\Objects\WarningLog.h"

#include "Core\Types\LogType.h"

#include "Core\Defines\consolecolors.h"
#include "Core/Defines/iostream.h"
#include "Core/Defines/stringstream.h"

#ifndef _WINDOWS_
#include <Windows.h>
#endif

WarningLog::WarningLog(const std::tstring& m, int ln, const std::tstring& fn)
	:Log(LogType::WARNING_LOG, m, ln, fn)
{
	std::tstringstream buffer;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	buffer << _T("Warning Message") << _T(" WARNING: ") << getMessage().c_str();
	buffer << _T("\nFound in file: ") << getFileName();
	buffer << _T("\nAt linenumber: ") << getLineNumber();
	buffer << _T("\n");

	std::tcout << _T("WARNING: ") << getMessage().c_str() << std::endl;
	OutputDebugString(buffer.str().c_str());

	updateMessage(buffer.str().c_str());
}
WarningLog::~WarningLog()
{}

const std::tstring WarningLog::toString() const
{
	std::tstringstream buffer;
	buffer << _T("LogMessage Type: Warning") << std::endl << getMessage();
	return buffer.str();
}