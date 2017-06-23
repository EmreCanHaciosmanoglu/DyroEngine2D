#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H

#include "Core/Helpers/Patterns/Manager.h"
#include "Core/Helpers/Patterns/Singleton.h"

#ifndef _STRING_H
#include "Core/Defines/string.h"
#endif

#include "Core\Data\Manager\LayerManager.h"
#include "Core\Data\Manager\ResourceManager.h"
#include "Core\Data\Manager\GeometryManager.h"
#include "Core\Data\Manager\TimerManager.h"
#include "Rendering\Manager\TextureManager.h"
#include "SceneGraph\Manager\CameraManager.h"
#include "SceneGraph\Manager\GameObjectManager.h"

#include "Core\Defines\debug.h"

#ifndef _VECTOR_
#include <vector>
#endif

#include "SceneGraph/Objects/Scenes/Scene.h"

class SceneManager : public Manager<Scene>, public Singleton<SceneManager>
{
public:
	SceneManager();
	virtual ~SceneManager();

	virtual bool initialize();
	void update();
	virtual bool shutdown();

	void addScene(Scene* scene);

	void setActiveScene(unsigned int id);
	void setActiveScene(const std::tstring& name);

	bool initializePreviousScene();
	bool initializeActiveScene();
	bool initializeScene(Scene* scene);
	 
	bool shutdownPreviousScene();
	bool shutdownActiveScene();
	bool shutdownScene(Scene* scene);

	Scene* getActiveScene() const;

private:
	void createManagers();
	void destroyManagers();

	template<typename T>
	T* createManager();
	template<typename T>
	T* getManager() const;

	template<typename T>
	bool initializeManager(T* manager);
	template<typename T>
	bool shutdownManager(T* manager);
	template<typename T>
	bool destroyManager(T* manager);

	template<typename T>
	void clearManager(T* manager);


	std::vector<AbstractManager*> managers;

	Scene* previous_scene;
	Scene* active_scene;
};

template <typename T>
T* SceneManager::getManager() const
{
	for (AbstractManager* m : this->managers)
	{
		T* new_m = dynamic_cast<T*>(m);
		if (new_m == nullptr)
			continue;

		return new_m;
	}

	return nullptr;
}

#endif _SCENEMANAGER_H
