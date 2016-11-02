#ifndef _RESOURCE_H
#define _RESOURCE_H

#ifndef _STRING_H
#include "Defines\string.h"
#endif
#ifndef _RESOURCETYPE_H
#include "Defines\Types\ResourceType.h"
#endif

class Resource
{
public:
	Resource(const std::tstring& resourcePath, ResourceType type);
	virtual ~Resource();

	virtual bool initialize() = 0;
	virtual bool shutdown() = 0;

	const std::tstring& getResourcePath();
	const std::tstring& getResourceName();

	ResourceType getResourceType();

private:
	std::tstring resource_path;
	std::tstring resource_name;

	ResourceType resource_type;
};

#endif

