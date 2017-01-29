#ifndef _SCENE_H
#define _SCENE_H

#include "SceneGraph/Objects/Object.h"
#ifndef _IINPUT_H
#include "Core/Helpers/Interfaces/IInput.h"
#endif

#ifndef _VECTOR_
#include <vector>
#endif
#ifndef _STRING_H
#include "Core\Defines\string.h"
#endif

class Input;

class Visualization;
class GameObject;

class AbstractManager;
class GameObjectManager;
class TimerManager;
class TransitionManager;
class VisualizationManager;

class Renderer;
class DebugRenderer;

class ContactListener;
class ContactFilter;
class b2World;

enum class DebugRenderingType;

class Scene : public Object, public IInput
{
	/**
	\note Must be present in every subclass definition.
	*/
	OBJECT_STATICS("Scene")

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

	void setDebugRenderingType(DebugRenderingType type);

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

	void triggerRender();

	b2World* phyx_world;

	Renderer* renderer;
	DebugRenderer* debug_renderer;

	ContactListener* contact_listener;
	ContactFilter* contact_filter;

	DebugRenderingType debug_rendering_type;

	GameObjectManager* game_object_manager;
	TimerManager* timer_manager;

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
