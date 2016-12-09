#ifndef _SCENE_H
#define _SCENE_H

#include "SceneGraph/Object.h"
#ifndef _IINPUT_H
#include "Interfaces\IInput.h"
#endif

#ifndef _VECTOR_
#include <vector>
#endif
#ifndef _STRING_H
#include "Defines\string.h"
#endif

class Visualization;

class GameObject;
class Input;
class Manager;

class DebugRenderer;
class ContactListener;
class ContactFilter;

class b2World;

class Scene : public Object, public IInput
{
public:
	Scene(const std::tstring& name);
	virtual ~Scene();

	virtual bool initialize();
	virtual bool postInitialize();
	virtual void update();
	virtual bool shutdown();

	virtual void setupInput(Input* input);

	virtual void activate();
	virtual void deactive();

	void enableDebugRendering();
	void disableDebugRendering();

	b2World* getPhyxWorld();

	void addGameObject(GameObject* object);
	void removeGameObject(GameObject* object);

	const std::vector<GameObject*>& getGameObjects() const;
	const std::vector<GameObject*> getUIObjects() const;
	const std::vector<Visualization*> getVisualizations() const;

	void addManager(Manager* manager);
	template<typename T>
	T* getManager() const;

private:
	void setupPyhx();

	bool initializeObjects(std::vector<GameObject*>& objects);
	bool postInitializeObjects(std::vector<GameObject*>& objects);
	void updateObjects(std::vector<GameObject*>& objects);
	bool shutdownObjects(std::vector<GameObject*> objects);

	b2World* phyx_world;

	DebugRenderer* debug_renderer;
	ContactListener* contact_listener;
	ContactFilter* contact_filter;

	bool debug_rendering;

	std::vector<GameObject*> vec_objects;
	std::vector<GameObject*> vec_ui_objects;

	std::vector<Manager*> vec_managers;

	std::vector<Visualization*> vec_visualizations;
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

