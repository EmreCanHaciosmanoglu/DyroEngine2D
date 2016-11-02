#include "Core/Resources/Resource.h"

Resource::Resource(const std::tstring& resourcePath, ResourceType type)
	:resource_path(resourcePath)
	, resource_type(type)
{
	int start_index = this->resource_path.find_last_of('\\');
	if (start_index == std::tstring::npos)
		start_index = this->resource_path.find_last_of('/');
	++start_index;
	int end_index = this->resource_path.find_last_of('.');

	this->resource_name = this->resource_path.substr(start_index, end_index - start_index);
}
Resource::~Resource()
{
}

const std::tstring& Resource::getResourcePath()
{
	return this->resource_path;
}
const std::tstring& Resource::getResourceName()
{
	return this->resource_name;
}

ResourceType Resource::getResourceType()
{
	return this->resource_type;
}