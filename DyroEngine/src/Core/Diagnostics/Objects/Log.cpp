#include "Core\Diagnostics\Objects\Log.h"

Log::Log(LogType t, const std::tstring& m, int ln, const std::tstring& fn)
	:TaggedObject(_T("Log"))
{}
Log::~Log()
{}

LogType Log::getType() const
{
	return this->type;
}

const std::tstring& Log::getMessage() const
{
	return this->message;
}
const std::tstring& Log::getFileName() const
{
	return this->file_name;
}

int Log::getLineNumber() const
{
	return this->line_number;
}

void Log::updateMessage(const std::tstring& newMessage)
{
	this->message = newMessage;
}