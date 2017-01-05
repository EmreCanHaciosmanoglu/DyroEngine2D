#include "SceneGraph/Objects/GameObjects/UIObject.h"

#include "SceneGraph/Objects/Components/TransformComponent.h"

UIObject::UIObject(const std::tstring& name)
	:GameObject(name)
	, transform(new TransformComponent())
{
	OBJECT_INIT(_T("UIObject"));
}
UIObject::~UIObject()
{}

bool UIObject::initialize()
{
	return GameObject::initialize();
}
void UIObject::upddate()
{
	GameObject::update();
}
bool UIObject::shutdown()
{
	return GameObject::shutdown();
}

TransformComponent* UIObject::getTransform() const
{
	return this->transform;
}