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
	return true;
}
bool ResourceManager::shutdown()
{
	return true;
}