#ifndef _LOG_H
#define _LOG_H

#include "Core/Helpers/TaggedObject.h"

enum class LogType;

class Log : public TaggedObject<Log>
{
public:
	Log(LogType t, const std::tstring& m, int ln = -1, const std::tstring& fn = _(""));
	virtual ~Log();

private:
	LogType type;
	std::tstring message;
};

#endif