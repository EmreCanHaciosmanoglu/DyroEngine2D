#include "SceneGraph\Object\GameObjects\GameObject.h"

#include "SceneGraph\Component\Component.h"
#include "SceneGraph\Scene\Scene.h"

#ifndef _ALGORITHM_
	#include <algorithm>
#endif

#include "Defines\deletemacros.h"

GameObject::GameObject(const std::tstring& name)
	:Object(name)
	, current_scene(nullptr)
	, parent(nullptr)
{
}
GameObject::~GameObject()
{
}

bool GameObject::initialize()
{
	for (Component* obj : this->vec_components)
	{
		if (obj->getInitialized())
			continue;

		if (!obj->initialize())
			return false;
	}
	for (GameObject* child_obj : this->vec_childeren)
	{
		if (child_obj->initialize())
			continue;

		if (!child_obj->initialize())
			return false;
	}

	return true;
}
void GameObject::update()
{
	for (Component* obj : this->vec_components)
	{
		if (obj->isActive())
			obj->update();
	}
	for (GameObject* child_obj : this->vec_childeren)
	{
		if (child_obj->isActive())
			child_obj->update();
	}
}
bool GameObject::shutdown()
{
	for (Component* obj : this->vec_components)
	{
		if (!obj->shutdown())
			return false;
		SafeDelete(obj);
	}
	this->vec_components.clear();
	for (GameObject* child_obj : this->vec_childeren)
	{
		if (!child_obj->shutdown())
			return false;
		SafeDelete(child_obj);
	}
	this->vec_childeren.clear();
	return true;
}

void GameObject::setupInput(Input* input)
{

}

void GameObject::setScene(Scene* scene)
{
	this->current_scene = scene;
}
Scene* GameObject::getScene() const
{
	return this->current_scene;
}
void GameObject::setParent(GameObject* parent)
{
	this->parent = parent;
}
GameObject* GameObject::getParent() const
{
	return this->parent;
}

std::vector<GameObject*> GameObject::getChilderen() const
{
	return this->vec_childeren;
}
std::vector<Component*> GameObject::getComponents() const
{
	return this->vec_components;
}

void GameObject::addComponent(Component* component)
{
	std::vector<Component*>::iterator it = std::find(this->vec_components.begin(), this->vec_components.end(), component);
	if (it == this->vec_components.end())
	{
		this->vec_components.push_back(component);
		component->setParent(this);
		if (component->getOrderValue() == Component::INVALID_ORDER_ID)
			component->setOrderValue(this->vec_components.size());
	}
}
void GameObject::removeComponent(Component* component)
{
	std::vector<Component*>::iterator it = std::find(this->vec_components.begin(), this->vec_components.end(), component);
	if (it != this->vec_components.end())
	{
		this->vec_components.erase(it);
		SafeDelete((*it));
	}
}
void GameObject::addChild(GameObject* child)
{
	std::vector<GameObject*>::iterator it = std::find(this->vec_childeren.begin(), this->vec_childeren.end(), child);
	if (it == this->vec_childeren.end())
	{
		this->vec_childeren.push_back(child);
		child->setParent(this);
		child->setScene(getScene());
	}
}
void GameObject::removeChild(GameObject* child)
{
	std::vector<GameObject*>::iterator it = std::find(this->vec_childeren.begin(), this->vec_childeren.end(), child);
	if (it != this->vec_childeren.end())
	{
		this->vec_childeren.erase(it);
		SafeDelete((*it));
	}
}