#ifndef _LOGMANAGER_H
#define _LOGMANAGER_H

#include "Core/Helpers/Patterns/Manager.h"

#define LOGTYPE_INFO LogType::INFO_LOG,__LINE__,__FILEW__
#define LOGTYPE_WARNING LogType::WARNING_LOG,__LINE__,__FILEW__
#define LOGTYPE_ERROR LogType::ERROR_LOG,__LINE__,__FILEW__
#define LOGTYPE_TODO LogType::TODO_LOG,__LINE__,__FILEW__

class Log;

class LogManager : Manager<Log>
{
public:
	LogManager();
	virtual ~LogManager();

	bool initialize();
	bool shutdown();

	void log(const Log& log);
	void writeLogToFile();
};

#endif