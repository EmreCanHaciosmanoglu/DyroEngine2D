#include "SceneGraph/Object.h"

Object::Object(const std::tstring& name)
	:active(true)

	, initialized(false)
	, post_initialized(false)
	, destroyed(false)

	,name(name == _T("") ? generateUniqueName<Object>(_T("Object_")) : name)
	,id(ObjectCounter<Object>::getAmount())
{
}
Object::~Object()
{
}

unsigned int Object::getObjectID() const
{
	return this->id;
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

void Object::setName(const std::tstring& name)
{
	this->name = name;
}
const std::tstring& Object::getName() const
{
	return this->name;
}