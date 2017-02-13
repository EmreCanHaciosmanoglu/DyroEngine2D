#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "SceneGraph\Objects\Object.h"

#ifndef _IINPUT_H
#include "Core\Helpers\Interfaces\IInput.h"
#endif

#ifndef _LIMITS_
#include <limits>
#endif

#ifndef _RECT2D_H
#include "Math\Objects\Rect2D.h"
#endif

#ifndef _GAMEOBJECTMANAGER_H
#include "SceneGraph\Manager\GameObjectManager.h"
#endif
#ifndef _COMPONENTMANAGER_H
#include "SceneGraph\Manager\ComponentManager.h"
#endif

class Scene;
class Input;

class Layer;

class GameObject : public Object, public IInput
{
	/**
	\note Must be present in every subclass definition.
	*/
	OBJECT_STATICS("GameObject")

public:
	GameObject(const std::tstring& name = _T(""));
	virtual ~GameObject();

	virtual bool initialize();
	virtual bool postInitialize();
	virtual void update();
	virtual bool shutdown();

	virtual void setupInput(Input* input);

	void setScene(Scene* scene);
	Scene* getScene() const;
	void setParent(GameObject* parent);
	GameObject* getParent() const;

	bool hasChilderen() const;

	void getChilderen(std::vector<GameObject*>& childeren) const;
	void getComponents(std::vector<Component*>& components) const;

	template <typename T> T* getComponent() const;
	Component* getComponent(const std::tstring& name);
	Component* getComponent(unsigned int id);

	void addComponent(Component* component);
	void removeComponent(Component* component);
	void removeComponent(unsigned int id);

	void addChild(GameObject* object);
	void removeChild(GameObject* object);
	void removeChild(unsigned int id);

	void setLayer(Layer* layer);
	Layer* getLayer() const;

	Rect2D getBounds() const;

private:
	GameObjectManager* childeren;
	ComponentManager* components;

	GameObject* parent;

	Scene* current_scene;

	unsigned int layer_id;
};

template <typename T>
T* GameObject::getComponent() const
{
	return this->components->getComponent<T>();
}

#endif
