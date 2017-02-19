#ifndef _LOGMANAGER_H
#define _LOGMANAGER_H

#include "Core/Helpers/Patterns/Singleton.h"
#include "Core/Helpers/Patterns/Manager.h"

#define LOG_DATA __LINE__,__FILEW__

#define LOG_INFO(message) LogManager::info(message, LOG_DATA);
#define LOG_WARNING(message) LogManager::warning(message, LOG_DATA);
#define LOG_ERROR(message) LogManager::error(message, LOG_DATA);

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

	static void info(const std::tstring& message, int ln, const std::tstring& fn);
	static void warning(const std::tstring& message, int ln, const std::tstring& fn);
	static void error(const std::tstring& message,  int ln, const std::tstring& fn);
};

#endif