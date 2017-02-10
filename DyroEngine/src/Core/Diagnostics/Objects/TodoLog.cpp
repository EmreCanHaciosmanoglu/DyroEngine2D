#include "Core\Diagnostics\Objects\TodoLog.h"

#include "Core\Types\LogType.h"

#include "Core\Defines\consolecolors.h"
#include "Core/Defines/iostream.h"
#include "Core/Defines/stringstream.h"

#ifndef _WINDOWS_
#include <Windows.h>
#endif

TodoLog::TodoLog(const std::tstring& m, int ln, const std::tstring& fn)
	:Log(LogType::TODO_LOG, m, ln, fn)
{
	std::tstringstream buffer;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTCYAN);
	buffer << _T("Todo Message") << _T(" TODO: ") << getMessage().c_str();
	buffer << _T("\nFound in file: ") << getFileName();
	buffer << _T("\nAt linenumber: ") << getLineNumber();
	buffer << _T("\n");

	std::tcout << _T("TODO: ") << getMessage().c_str() << std::endl;
	OutputDebugString(buffer.str().c_str());

	updateMessage(buffer.str().c_str());
}
TodoLog::~TodoLog()
{}

const std::tstring TodoLog::toString() const
{
	std::tstringstream buffer;
	buffer << _T("LogMessage Type: ToDo ") << std::endl << getMessage();
	return buffer.str();
}