#ifndef _ErrorLog_H
#define _ErrorLog_H

#include "Core/Diagnostics/Objects/Log.h"

class ErrorLog : public Log
{
public:
	ErrorLog(const std::tstring& m, int ln = -1, const std::tstring& fn = _T(""));
	virtual ~ErrorLog();

	virtual const std::tstring toString() const;
};

#endif