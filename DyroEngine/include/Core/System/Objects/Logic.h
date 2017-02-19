#ifndef _LOGIC_H
#define _LOGIC_H

#include "Core/System/Objects/System.h"

class Logic : public System
{
public:
	Logic();
	virtual ~Logic();

	virtual bool initialize();
	void update();
	virtual bool shutdown();

private:
};

#endif