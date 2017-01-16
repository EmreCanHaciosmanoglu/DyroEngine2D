#include "Core\Diagnostics\Objects\InfoLog.h"

#include "Core\Types\LogType.h"

#include "Core\Defines\consolecolors.h"
#include "Core/Defines/iostream.h"
#include "Core/Defines/stringstream.h"

#ifndef _WINDOWS_
#include <Windows.h>
#endif

InfoLog::InfoLog(const std::tstring& m, int ln, const std::tstring& fn)
	:Log(LogType::INFO_LOG, m, ln, fn)
{
	std::tstringstream buffer;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	buffer << _T("Info Message") << _T(" INFO: ") << getMessage().c_str();
	buffer << _T("\nFound in file: ") << getFileName();
	buffer << _T("\nAt linenumber: ") << getLineNumber();
	buffer << _T("\n");

	std::tcout << _T("INFO: ") << getMessage().c_str() << std::endl;
	OutputDebugString(buffer.str().c_str());

	updateMessage(buffer.str().c_str());
}
InfoLog::~InfoLog()
{}

const std::tstring InfoLog::toString() const
{
	std::tstringstream buffer;
	buffer << _T("LogMessage Type: Info") << std::endl << getMessage();
	return buffer.str();
}