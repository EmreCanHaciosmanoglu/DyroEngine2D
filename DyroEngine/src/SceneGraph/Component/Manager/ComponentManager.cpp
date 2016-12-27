#include "SceneGraph\Component\Manager\ComponentManager.h"
#include "SceneGraph\Component\Component.h"

#include "Defines\deletemacros.h"
#include "Defines\assert.h"

ComponentManager::ComponentManager()
{}
ComponentManager::~ComponentManager()
{}

bool ComponentManager::initialize()
{
	std::vector<Component*> components;
	getComponents(components);

	//Setup order of the components
	//FIFO -> first in first out ( destruction principle of the components )
	std::sort(components.begin(), components.end(),
		[](const Component* c1, const Component* c2) -> bool
	{
		if (c1->getExecutionOrder() == Component::INVALID_ORDER_ID && c2->getExecutionOrder() == Component::INVALID_ORDER_ID)
			return false;

		else if (c1->getExecutionOrder() == Component::INVALID_ORDER_ID)
			return false;
		else if (c2->getExecutionOrder() == Component::INVALID_ORDER_ID)
			return true;

		return c1->getExecutionOrder() < c2->getExecutionOrder();
	});

	for (Component* c : components)
	{
		if (c->getInitialized())
			continue;

		if (!c->initialize())
			return false;
	}

	return true;
}
bool ComponentManager::postInitialize()
{
	for (const std::pair<unsigned int, Component*>& pair : getObjects())
	{
		if (pair.second->getPostInitialized())
			continue;

		if (!pair.second->postInitialize())
			return false;
	}

	return true;
}
void ComponentManager::update()
{
	for (const std::pair<unsigned int, Component*>& pair : getObjects())
	{
		if (pair.second->isActive())
			pair.second->update();
	}
}
bool ComponentManager::shutdown()
{
	std::vector<Component*> components;
	getComponents(components);

	//Setup order of the components
	//FIFO -> first in first out ( destruction principle of the components )
	std::sort(components.begin(), components.end(),
		[](const Component * c1, const Component * c2) -> bool
	{
		if (c1->getExecutionOrder() == Component::INVALID_ORDER_ID && c2->getExecutionOrder() == Component::INVALID_ORDER_ID)
			return true;

		else if (c1->getExecutionOrder() == Component::INVALID_ORDER_ID)
			return true;
		else if (c2->getExecutionOrder() == Component::INVALID_ORDER_ID)
			return false;

		return c1->getExecutionOrder() > c2->getExecutionOrder();
	});

	bool result = true;
	for (Component* c : components)
	{
		if (!c->shutdown())
			result = false;
		delete c;
	}

	return result;
}

void ComponentManager::addComponent(Component* component)
{
	addObject(component->getID(), component);
}

void ComponentManager::removeComponent(Component* component)
{
	removeObject(component);
}
void ComponentManager::removeComponent(unsigned int id)
{
	removeObject(id);
}

Component* ComponentManager::getComponent(const std::tstring& name) const
{
	std::map<unsigned int, Component*> components = getObjects();
	std::map<unsigned int, Component*>::const_iterator it = std::find_if(components.begin(), components.end(),
		[name](std::pair<unsigned int, Component*> pair) -> bool
	{
		return name == pair.second->getName();
	});

	return (*it).second;
}
Component* ComponentManager::getComponent(unsigned int id) const
{
	return getObject(id);
}

void ComponentManager::getComponents(std::vector<Component*>& objects) const
{
	getObjects(objects);
}
const std::map<unsigned int, Component*>& ComponentManager::getComponents() const
{
	return getObjects();
}