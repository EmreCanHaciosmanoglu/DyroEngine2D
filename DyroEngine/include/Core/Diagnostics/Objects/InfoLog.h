#ifndef _InfoLog_H
#define _InfoLog_H

#include "Core/Diagnostics/Objects/Log.h"

class InfoLog : public Log
{
public:
	InfoLog(const std::tstring& m, int ln = -1, const std::tstring& fn = _T(""));
	virtual ~InfoLog();

	virtual const std::tstring toString() const;
};

#endif