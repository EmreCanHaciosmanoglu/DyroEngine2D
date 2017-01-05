#ifndef _SYSTEM_H
#define _SYSTEM_H

#ifndef _SYSTEMTYPE_H
#include "Core/Types/SystemType.h"
#endif

class System
{
public:
	System(SystemType type);
	virtual ~System();

	virtual bool initialize() = 0;
	virtual void update() = 0;
	virtual bool shutdown() = 0;

	void activate();
	void deactivate();

	bool getIsActive() const;

	SystemType getType() const;

private:
	SystemType system_type;
	bool active;
};

#endif // _SYSTEM_H
