#include "SceneGraph/Component/Component.h"

#include "SceneGraph/GameObjects/GameObject.h"

Component::Component(const std::tstring& name)
	:Object(name)
	, parent(nullptr)
	, execution_order(INVALID_ORDER_ID)
{
}
Component::~Component()
{
}

bool Component::postInitialize()
{
	return true;
}
void Component::update()
{

}

int Component::getExecutionOrder() const
{
	return this->execution_order;
}
void Component::setExecutionOrder(int value)
{
	this->execution_order = value;
}

void Component::setParent(GameObject* parent)
{
	this->parent = parent;
}
GameObject* Component::getParent() const
{
	return this->parent;
}