#ifndef _TODOLOG_H
#define _TODOLOG_H

#include "Core/Diagnostics/Objects/Log.h"

class TodoLog : public Log
{
public:
	TodoLog(const std::tstring& m, int ln = -1, const std::tstring& fn = _T(""));
	virtual ~TodoLog();

	virtual const std::tstring toString() const;
};

#endif