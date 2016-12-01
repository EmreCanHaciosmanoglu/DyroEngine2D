#ifndef _SCENE_H
#define _SCENE_H

#include "SceneGraph/Object.h"
#ifndef _IDRAWABLE_H
#include "Interfaces\IDrawable.h"
#endif
#ifndef _IINPUT_H
#include "Interfaces\IInput.h"
#endif

#ifndef _VECTOR_
#include <vector>
#endif
#ifndef _STRING_H
#include "Defines\string.h"
#endif

class GameObject;
class Input;
class Manager;

class DebugRenderer;
class ContactListener;
class ContactFilter;

class b2World;

class Scene : public Object, public IDrawable, public IInput
{
public:
	Scene(const std::tstring& name);
	virtual ~Scene();

	virtual bool initialize();
	virtual void update();
	virtual void draw();
	virtual bool shutdown();

	virtual void setupInput(Input* input);

	virtual void activate();
	virtual void deactive();

	virtual void destroy();

	void enableDebugRendering();
	void disableDebugRendering();

	b2World* getPhyxWorld();

	void addGameObject(GameObject* object);
	void removeGameObject(GameObject* object);

	void addManager(Manager* manager);
	template<typename T>
	T* getManager() const;

private:
	void setupPyhx();

	b2World* phyx_world;

	DebugRenderer* debug_renderer;
	ContactListener* contact_listener;
	ContactFilter* contact_filter;

	bool debug_rendering;

	std::vector<GameObject*> vec_objects;
	std::vector<Manager*> vec_managers;
};

template <typename T>
T* Scene::getManager() const
{
	for (Manager* m : this->vec_managers)
	{
		T* new_m = dynamic_cast<T*>(m);
		if (new_m == nullptr)
			continue;

		return new_m;
	}

	return nullptr;
}

#endif //_SCENE_H

