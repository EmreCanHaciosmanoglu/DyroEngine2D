#include "Core/System/Manager/SystemManager.h"
#include "Core/Types/SystemType.h"

#include "Core/Defines/deletemacros.h"

SystemManager::SystemManager()
{}
SystemManager::~SystemManager()
{}

bool SystemManager::initialize()
{
	std::vector<System*> systems;
	getObjects(systems);

	for (System* system : systems)
	{
		if (!system->initialize())
			return false;
	}

	return true;
}
bool SystemManager::shutdown()
{
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

bool SystemManager::addSystem(SystemType type)
{
	return addObject((int)type, this->factory.createSystem(type));
}

void SystemManager::getSystems(std::vector<System*>& systems)
{
	getObjects(systems);
}
