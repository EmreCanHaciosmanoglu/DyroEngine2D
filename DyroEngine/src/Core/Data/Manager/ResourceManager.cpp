#include "Core/Data/Manager/ResourceManager.h"

#ifndef _DELETEMACROS_H
#include "Core\Defines\deletemacros.h"
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
	std::vector<Resource*> resources;
	getObjects(resources);

	for (Resource* r : resources)
	{
		if (!r->initialize())
			return false;
	}

	return true;
}
bool ResourceManager::shutdown()
{
	std::vector<Resource*> resources;
	getObjects(resources);

	for (Resource* r : resources)
	{
		if (!r->shutdown())
			return false;

		SafeDelete(r);
	}

	return true;
}