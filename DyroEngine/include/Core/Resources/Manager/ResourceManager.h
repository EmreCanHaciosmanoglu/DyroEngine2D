#ifndef _RESOURCEMANAGER_H
#define _RESOURCEMANAGER_H

#include "Helpers\Manager.h"

#ifndef _STRING_H
#include "Defines\string.h"
#endif

#ifndef _RESOURCE_H
#include "Core\Resources\Resource.h"
#endif

#ifndef _MAP_
#include <map>
#endif
#ifndef _ALGORITHM_
#include <algorithm>
#endif

class ResourceManager : public Manager
{
public:
	ResourceManager();
	virtual ~ResourceManager();

	virtual bool initialize();
	virtual bool shutdown();

	template<typename T> T* getResource(const std::tstring& path);

private:

	std::map<const std::tstring, Resource*> resources;
};

template<typename T>
T* ResourceManager::getResource(const std::tstring& path)
{

}

#endif
