#include "SceneGraph/Objects/Object.h"
#include "Core/Defines/debug.h"

Object::Object(const std::tstring& name)
	: TaggedObject(name)
	, active(true)
	, initialized(false)
	, post_initialized(false)
	, destroyed(false)
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

void Object::setInitialized()
{
	this->initialized = true;
}
bool Object::getInitialized()
{
	return this->initialized;
}
void Object::setPostInitialized()
{
	this->post_initialized = true;
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

void Object::destroy()
{
	this->destroyed = true;

	this->initialized = false;
	this->post_initialized = false;
}
bool Object::isDestroyed() const
{
	return this->destroyed;
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