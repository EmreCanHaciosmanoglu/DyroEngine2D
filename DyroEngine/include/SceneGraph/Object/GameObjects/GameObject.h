#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "SceneGraph\Object.h"
#ifndef _IINPUT_H
#include "Interfaces\IInput.h"
#endif

#ifndef _SINGLETON_H
#include "Helpers/Singleton.h"
#endif
#ifndef _LOGGER_H
#include "Diagnostics/Logger.h"
#endif

#ifndef _VECTOR_
#include <vector>
#endif
#ifndef _LIMITS_
#include <limits>
#endif

class Component;
class Scene;
class Input;

class GameObject : public Object, public IInput
{
public:
	GameObject(const std::tstring& name = _T(""));
	virtual ~GameObject();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	virtual void setupInput(Input* input);

	void setScene(Scene* scene);
	Scene* getScene() const;
	void setParent(GameObject* parent);
	GameObject* getParent() const;

	std::vector<GameObject*> getChilderen() const;

	template <typename T> T* getComponent() const;
	std::vector<Component*> getComponents() const;

	void addComponent(Component* component);
	void removeComponent(Component* component);

	void addChild(GameObject* object);
	void removeChild(GameObject* object);

private:
	std::vector<GameObject*> vec_childeren;
	std::vector<Component*> vec_components;

	GameObject* parent;

	Scene* current_scene;
};

template <typename T>
T* GameObject::getComponent() const
{
	for (Component* c : this->vec_components)
	{
		T* new_c = dynamic_cast<T*>(c);
		if (new_c == nullptr)
			continue;

		return new_c;
	}

	return nullptr;
}

#endif
