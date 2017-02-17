#include "Core\Diagnostics\Manager\LogManager.h"
#include "Core\Diagnostics\Objects\InfoLog.h"
#include "Core\Diagnostics\Objects\WarningLog.h"
#include "Core\Diagnostics\Objects\ErrorLog.h"

#include "Core\Types\LogType.h"

#include "Core/Defines/stringstream.h"
#include "Core/Defines/iostream.h"
#include "Core/Defines/fstream.h"
#include "Core/Defines/assert.h"

#ifndef _WINDOWS_
#include <Windows.h>
#endif

LogManager::LogManager()
{}
LogManager::~LogManager()
{}

bool LogManager::initialize()
{
	return true;
}
bool LogManager::shutdown()
{
	return true;
}

void LogManager::log(Log* log)
{
	addObject(log->getID(), log);
}
void LogManager::writeLogToFile()
{
	std::vector<Log*> log_messages;
	getObjects(log_messages);

	for (Log* log : log_messages)
	{
		std::tstringstream buffer;
		buffer << ".\\Logs\\" << _T("LogFile") << log->getID() << _T(".txt") << _T("\0");

		std::tofstream logfile(buffer.str().c_str(), std::ios::in | std::ios::out | std::ios::trunc);

		if (!logfile)
		{
			OutputDebugString(_T("Cannot create log file \n"));
			return;
		}

		logfile << _T("Logfile ") << log->getID() << std::endl;
		logfile << __DATE__ << _T(" ") << __TIME__ << std::endl;
		logfile << log->toString() << std::endl;
		logfile << _T("End of log");

		logfile.close();
	}
}

void LogManager::info(const std::tstring& message, int ln, const std::tstring& fn)
{
	LogManager::getInstance().log(new InfoLog(message, ln, fn));
}
void LogManager::warning(const std::tstring& message, int ln, const std::tstring& fn)
{
	LogManager::getInstance().log(new WarningLog(message, ln, fn));
}
void LogManager::error(const std::tstring& message, int ln, const std::tstring& fn)
{
	LogManager::getInstance().log(new ErrorLog(message, ln, fn));
}
