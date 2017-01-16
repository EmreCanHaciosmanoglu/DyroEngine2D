#ifndef _LOGMANAGER_H
#define _LOGMANAGER_H

#include "Core/Helpers/Patterns/Manager.h"
#include "Core/Helpers/Patterns/Singleton.h"

#define LOG_INFO __LINE__,__FILEW__

class Log;

class LogManager : public Manager<Log>, public Singleton<LogManager>
{
public:
	LogManager();
	virtual ~LogManager();

	bool initialize();
	bool shutdown();

	void log(Log* log);
	void writeLogToFile();
};

#endif