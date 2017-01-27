#ifndef _COMPONENTMANAGER_H
#define _COMPONENTMANAGER_H

#include "Core/Helpers/Patterns/Manager.h"
#include "SceneGraph\Objects\Components\Component.h"

class ComponentManager : public Manager<Component>
{
public:
	ComponentManager();
	virtual ~ComponentManager();

	virtual bool initialize();
	virtual bool postInitialize();
	virtual void update();
	virtual bool shutdown();

	void addComponent(Component* component);

	void removeComponent(Component* component);
	void removeComponent(unsigned int id);

	template <typename T> T* getComponent() const;
	Component* getComponent(const std::tstring& name) const;
	Component* getComponent(unsigned int id) const;

	void getComponents(std::vector<Component*>& objects) const;
	const std::map<unsigned int, Component*>& getComponents() const;
};

template <typename T>
T* ComponentManager::getComponent() const
{
	for (const std::pair<unsigned int, Component*>& pair : getObjects())
	{
		T* new_c = dynamic_cast<T*>(pair.second);
		if (new_c == nullptr)
			continue;

		return new_c;
	}

	return nullptr;
}

#endif