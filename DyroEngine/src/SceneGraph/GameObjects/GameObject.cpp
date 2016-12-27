#include "SceneGraph\GameObjects\GameObject.h"

#include "SceneGraph\Component\Component.h"
#include "SceneGraph\Scene\Scene.h"

#include "Core\Data\Objects\Layer.h"
#include "Core\Data\Manager\LayerManager.h"

#ifndef _ALGORITHM_
#include <algorithm>
#endif

#include "Defines\deletemacros.h"

GameObject::GameObject(const std::tstring& name)
	:Object(name)
	, current_scene(nullptr)
	, parent(nullptr)
	, childeren(nullptr)
	, components(nullptr)
{
	OBJECT_INIT(_T("GameObject"));

	this->childeren = new GameObjectManager();
	this->components = new ComponentManager();
}
GameObject::~GameObject()
{
}

bool GameObject::initialize()
{
	if (!this->components->initialize())
		return false;
	if (!this->childeren->initialize())
		return false;

	return true;
}
bool GameObject::postInitialize()
{
	if (!this->components->postInitialize())
		return false;
	if (!this->childeren->postInitialize())
		return false;

	return true;
}
void GameObject::update()
{
	this->components->update();
	this->childeren->update();
}
bool GameObject::shutdown()
{
	bool result = true;
	if (!this->components->shutdown())
		result = false;
	if (!this->childeren->shutdown())
		result = false;

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

bool GameObject::hasChilderen() const
{
	return (int)this->childeren->getSize() > 0;
}

void GameObject::getChilderen(std::vector<GameObject*>& childeren) const
{
	this->childeren->getGameObjects(childeren);
}
void GameObject::getComponents(std::vector<Component*>& components) const
{
	this->components->getComponents(components);
}

void GameObject::addComponent(Component* component)
{
	component->setParent(this);
	this->components->addComponent(component);
}
void GameObject::removeComponent(Component* component)
{
	this->components->removeComponent(component);
	SafeDelete(component);
}
void GameObject::removeComponent(unsigned int id)
{
	Component* c = this->components->getComponent(id);
	this->components->removeComponent(id);
	SafeDelete(c);
}
void GameObject::addChild(GameObject* child)
{
	child->setParent(this);
	child->setScene(getScene());
	this->childeren->addGameObject(child);
}
void GameObject::removeChild(GameObject* child)
{
	this->childeren->removeGameObject(child);
	SafeDelete(child);
}
void GameObject::removeChild(unsigned int id)
{
	GameObject* c = this->childeren->getGameObject(id);
	this->childeren->removeGameObject(id);
	SafeDelete(c);
}

void GameObject::setLayer(Layer* layer)
{
	this->layer_id = layer->getID();
	getScene()->getManager<LayerManager>()->addLayer(layer);
}
Layer* GameObject::getLayer() const
{
	return getScene()->getManager<LayerManager>()->getLayer(this->layer_id);
}