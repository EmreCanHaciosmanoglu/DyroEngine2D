#ifndef _RESOURCE_H
#define _RESOURCE_H

#include "Helpers/Patterns/ObjectCounter.h"

#ifndef _STRING_H
#include "Defines\string.h"
#endif
#ifndef _RESOURCETYPE_H
#include "Defines\Types\ResourceType.h"
#endif

class Resource : public ObjectCounter<Resource>
{
public:
	Resource(const std::tstring& resourcePath, ResourceType type);
	virtual ~Resource();

	virtual bool initialize() = 0;
	virtual bool shutdown() = 0;

	unsigned int getResourceID() const;

	const std::tstring& getResourcePath();
	const std::tstring& getResourceName();

	ResourceType getResourceType();

private:
	unsigned int resource_id;
	std::tstring resource_path;
	std::tstring resource_name;

	ResourceType resource_type;
};

#endif
