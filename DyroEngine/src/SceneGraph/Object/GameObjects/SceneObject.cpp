#include "SceneGraph/Object/GameObjects/SceneObject.h"
#include "SceneGraph/Component/Component.h"

SceneObject::SceneObject(const std::tstring& name)
	:GameObject(name)
{
}
SceneObject::~SceneObject()
{
}

bool SceneObject::initialize()
{
	return GameObject::initialize();
}
void SceneObject::update()
{
	return GameObject::update();
}
void SceneObject::draw()
{
	for (Component* obj : getComponents())
	{
		IDrawable* drawable_obj = dynamic_cast<IDrawable*>(obj);
		if (drawable_obj == nullptr)
			continue;

		if (drawable_obj->getCanDraw())
			drawable_obj->draw();
	}
	for (GameObject* obj : getChilderen())
	{
		IDrawable* drawable_obj = dynamic_cast<IDrawable*>(obj);
		if (drawable_obj == nullptr)
			continue;

		if (drawable_obj->getCanDraw())
			drawable_obj->draw();
	}
}
bool SceneObject::shutdown()
{
	return GameObject::shutdown();
}