#include "Core/System/Manager/SystemManager.h"

#include "Core/System/System.h"
#include "Core/System/Manager/SystemFactory.h"

#include "Defines/Types/SystemType.h"
#include "Defines/deletemacros.h"

SystemManager::SystemManager()
	:factory(nullptr)
{
}
SystemManager::~SystemManager()
{
}

System* SystemManager::getSystem(SystemType type)
{
	System* system = getObject((int)type);
	if (system != nullptr)
		return system;

	System* new_system = this->factory->createSystem(type);
	addObject((int)type, new_system);

	return new_system;
}
std::vector<System*> SystemManager::getSystems()
{
	return getObjects();
}


bool SystemManager::initialize()
{
	this->factory = new SystemFactory();

	return true;
}
bool SystemManager::shutdown()
{
	SafeDelete(this->factory);

	bool result = true;
	for (System* system : getObjects())
	{
		if (!system->shutdown())
			result = false;

		SafeDelete(system);
	}

	return result;
}