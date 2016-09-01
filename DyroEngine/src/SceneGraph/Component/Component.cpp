#include "SceneGraph/Component/Component.h"

#include "SceneGraph/Object/GameObjects/GameObject.h"

Component::Component(const std::tstring& name)
	:Object(name)
	, parent(nullptr)
	, order_id(INVALID_ORDER_ID)
{
}
Component::~Component()
{
}

int Component::getOrderValue() const
{
	return this->order_id;
}
void Component::setOrderValue(int value)
{
	this->order_id = value;
}

void Component::setParent(GameObject* parent)
{
	this->parent = parent;
}
GameObject* Component::getParent() const
{
	return this->parent;
}