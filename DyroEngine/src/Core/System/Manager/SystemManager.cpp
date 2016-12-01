#include "Core/System/Manager/SystemManager.h"

#ifndef _ALGORITHM
	#include <algorithm>
#endif

#include "Core/System/System.h"
#include "Core/System/Manager/SystemFactory.h"

#ifndef _IDRAWABLE_H
#include "Interfaces\IDrawable.h"
#endif

#include "Defines/Types/SystemType.h"
#include "Defines/deletemacros.h"

#include "Helpers/Singleton.h"

SystemManager::SystemManager()
	:factory(nullptr)
{
}
SystemManager::~SystemManager()
{
}

System* SystemManager::getSystem(SystemType type)
{
	std::vector<System*>::const_iterator it = std::find_if(this->vec_systems.begin(), this->vec_systems.end(), 
		[type](System* s) -> bool
	{
		return s->getType() == type;
	});
	if (it != this->vec_systems.end())
		return (*it);

	System* new_system = this->factory->createSystem(type);

	if (dynamic_cast<IDrawable*>(new_system) != nullptr)
		this->vec_drawable_systems.push_back(new_system);
	this->vec_systems.push_back(new_system);

	return new_system;
}

std::vector<System*>& SystemManager::getDrawableSystems()
{
	return this->vec_drawable_systems;
}
std::vector<System*>& SystemManager::getSystems()
{
	return this->vec_systems;
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
	for (System* system : this->vec_systems)
	{
		if (!system->shutdown())
			result = false;

		SafeDelete(system);
	}

	this->vec_systems.clear();
	this->vec_drawable_systems.clear();

	return result;
}