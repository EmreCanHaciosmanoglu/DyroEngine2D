#include "Core/System/Manager/SystemManager.h"

#include "Core/System/Objects/System.h"
#include "Core/System/Factory/SystemFactory.h"

#include "Core/Types/SystemType.h"
#include "Core/Defines/deletemacros.h"

SystemManager::SystemManager()
	:factory(nullptr)
{
}
SystemManager::~SystemManager()
{
}

bool SystemManager::addSystem(SystemType type)
{
	addObject((int)type, this->factory->createSystem(type));
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