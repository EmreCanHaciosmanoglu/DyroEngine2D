#include "SceneGraph/Objects/Object.h"
#include "Core/Defines/debug.h"

Object::Object(const std::tstring& name)
	: TaggedObject(name)
	, active(true)
	, initialized(false)
	, post_initialized(false)
{
	OBJECT_INIT(_T("Object"));
}
Object::~Object()
{
}

bool Object::isOfType(const std::tstring& classTypeId) const
{
	return std::find(this->inheritance_list.begin(), this->inheritance_list.end(), classTypeId) != this->inheritance_list.end();
}
const std::vector<std::tstring>& Object::getInheritanceList() const
{
	return this->inheritance_list;
}

void Object::setInitialized(bool initialized)
{
	this->initialized = initialized;
}
void Object::setPostInitialized(bool postInitialized)
{
	this->post_initialized = postInitialized;
}
bool Object::getInitialized()
{
	return this->initialized;
}
bool Object::getPostInitialized()
{
	return this->post_initialized;
}

void Object::activate()
{
	this->active = true;
}
void Object::deactive()
{
	this->active = false;
}
bool Object::isActive()
{
	return this->active;
}

void Object::OBJECT_INIT(const std::tstring& classTypeId)
{
	std::vector<std::tstring>::const_iterator it = std::find(this->inheritance_list.begin(), this->inheritance_list.end(), classTypeId);
	if (it != this->inheritance_list.end())
	{
		LogManager::getInstance().log(new ErrorLog(_T("DataObject : duplicate class type id detected; ignored:") + classTypeId, LOG_DATA));
		return;
	}

	this->inheritance_list.push_back(classTypeId);
}