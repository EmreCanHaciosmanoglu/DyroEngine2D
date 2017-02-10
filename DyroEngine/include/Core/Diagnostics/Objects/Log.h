#ifndef _LOG_H
#define _LOG_H

#include "Core/Helpers/TaggedObject.h"

enum class LogType;

class Log : public TaggedObject<Log>
{
public:
	Log(LogType t, const std::tstring& m, int ln = -1, const std::tstring& fn = _T(""));
	virtual ~Log();

	virtual const std::tstring toString() const = 0;

	LogType getType() const;

	const std::tstring& getMessage() const;
	const std::tstring& getFileName() const;

	int getLineNumber() const;

protected:
	void updateMessage(const std::tstring& newMessage);

private:
	LogType type;

	std::tstring message;
	std::tstring file_name;

	int line_number;
};

#endif