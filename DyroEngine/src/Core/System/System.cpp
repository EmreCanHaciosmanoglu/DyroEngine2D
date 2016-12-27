#include "Core\System\System.h"

#include "Defines/Types/SystemType.h"

System::System(SystemType type)
	:system_type(type)
	, active(true)
{
}
System::~System()
{
}

void System::activate()
{
	this->active = true;
}
void System::deactivate()
{
	this->active = false;
}

bool System::getIsActive() const
{
	return this->active;
}

SystemType System::getType() const
{
	return this->system_type;
}