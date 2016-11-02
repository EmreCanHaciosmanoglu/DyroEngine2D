#include "Core/Resources/Manager/ResourceManager.h"

#ifndef _DELETEMACROS_H
#include "Defines\deletemacros.h"
#endif

ResourceManager::ResourceManager()
	:Manager()
{
}
ResourceManager::~ResourceManager()
{
}

bool ResourceManager::initialize()
{
	for (std::pair<const std::tstring, Resource*>& pair : this->resources)
	{
		if (!pair.second->initialize())
			return false;
	}

	return true;
}
bool ResourceManager::shutdown()
{
	for (std::pair<const std::tstring, Resource*>& pair : this->resources)
	{
		if (!pair.second->shutdown())
			return false;

		SafeDelete(pair.second);
	}
	this->resources.clear();

	return true;
}