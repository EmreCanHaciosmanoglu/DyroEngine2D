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

class AbstractManager;
class GameObjectManager;
class VisualizationManager;

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
	void removeGameObject(unsigned int id);

	void getGameObjects(std::vector<GameObject*>& objects) const;
	void getVisualizations(std::vector<Visualization*>& visualizations) const;

	void addManager(AbstractManager* manager);
	template<typename T>
	T* getManager() const;

private:
	void setupPyhx();

	b2World* phyx_world;

	DebugRenderer* debug_renderer;
	ContactListener* contact_listener;
	ContactFilter* contact_filter;

	bool debug_rendering;

	GameObjectManager* game_object_manager;

	std::vector<AbstractManager*> vec_managers;
};

template <typename T>
T* Scene::getManager() const
{
	for (AbstractManager* m : this->vec_managers)
	{
		T* new_m = dynamic_cast<T*>(m);
		if (new_m == nullptr)
			continue;

		return new_m;
	}

	return nullptr;
}

#endif //_SCENE_H
