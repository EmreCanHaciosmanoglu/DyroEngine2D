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
void SystemManager::getSystems(std::vector<System*>& systems)
{
	getObjects(systems);
}


bool SystemManager::initialize()
{
	this->factory = new SystemFactory();

	return true;
}
bool SystemManager::shutdown()
{
	SafeDelete(this->factory);

	std::vector<System*> systems;
	getObjects(systems);

	bool result = true;
	for (System* system : systems)
	{
		if (!system->shutdown())
			result = false;

		SafeDelete(system);
	}

	return result;
}