#ifndef _WarningLog_H
#define _WarningLog_H

#include "Core/Diagnostics/Objects/Log.h"

class WarningLog : public Log
{
public:
	WarningLog(const std::tstring& m, int ln = -1, const std::tstring& fn = _T(""));
	virtual ~WarningLog();

	virtual const std::tstring toString() const;
};

#endif