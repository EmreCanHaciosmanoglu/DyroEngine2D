#include "SceneGraph/Object/GameObjects/UIObject.h"

#include "SceneGraph/Component/TransformComponent.h"

UIObject::UIObject(const std::tstring& name = _T(""))
	:GameObject(name)
	,transform(new TransformComponent())
{}
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
void UIObject::draw()
{
}
bool UIObject::shutdown()
{
	return GameObject::shutdown();
}

TransformComponent* UIObject::getTransform() const
{
	return this->transform;
}