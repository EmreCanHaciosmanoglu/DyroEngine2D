#include "SceneGraph/Manager/SceneManager.h"
#include "SceneGraph/Factory/GameObjectFactory.h"

#include "Core/Defines/assert.h"
#include "Core/Defines/deletemacros.h"

#include "Core/Helpers/Patterns/Singleton.h"
#include "Core/Helpers/Patterns/Manager.h"

#include "Core/Data/Manager/MessageManager.h"
#include "Core/Data/Objects/Message/Messages/SwitchSceneMessage.h"

#include "Core/Types/SceneManagerStateType.h"
#include "Core/Types/MessageType.h"

#ifndef _ALGORITHM_
#include <algorithm>
#endif

SceneManagerState::SceneManagerStateType SceneManagerState::SCENEMANAGER_STATE = SceneManagerState::SceneManagerStateType::INVALID;

SceneManager::SceneManager()
	:active_scene(nullptr)
	, previous_scene(nullptr)
{
	createManagers();
}
SceneManager::~SceneManager()
{
	destroyManagers();
}

bool SceneManager::initialize()
{
	SceneManagerState::SCENEMANAGER_STATE = SceneManagerState::SceneManagerStateType::INITIALIZE;
	initializeActiveScene();

	return true;
}
void SceneManager::update()
{	
	//Initialize & Post-Initialize the scene before trying to update it.
	assert(this->active_scene->getInitialized());
	assert(this->active_scene->getPostInitialized());

	SceneManagerState::SCENEMANAGER_STATE = SceneManagerState::SceneManagerStateType::UPDATE;

	if (this->active_scene->isActive())
	{
		this->active_scene->update();
		this->active_scene->draw();
	}

}
bool SceneManager::shutdown()
{
	SceneManagerState::SCENEMANAGER_STATE = SceneManagerState::SceneManagerStateType::SHUTDOWN;

	std::vector<Scene*> scenes;
	getObjects(scenes);

	for (Scene* scene : scenes)
	{
		if (!scene->getInitialized())
		{
			SafeDelete(scene);
			continue;
		}

		if (!scene->shutdown())
			return false;

		SafeDelete(scene);
	}

	return true;
}

void SceneManager::addScene(Scene* scene)
{
	addObject(scene->getID(), scene);
}

void SceneManager::setActiveScene(unsigned int id)
{
	Scene* scene = getObject(id);
	if (scene == nullptr)
		return;

	this->previous_scene = this->active_scene;
	if (this->active_scene)
	{
		this->active_scene->deactive();
	}

	GameObjectFactory::getInstance().setScene(scene);

	this->active_scene = scene;
	this->active_scene->activate();

	//MessageManager::getInstance().sendMessage(new SwitchSceneMessage());
}
void SceneManager::setActiveScene(const std::tstring& name)
{
	std::vector<Scene*> scenes;
	getObjects(scenes);

	std::vector<Scene*>::const_iterator it = std::find_if(scenes.begin(), scenes.end(),
		[name](Scene* scene) -> bool
	{
		return scene->getName() == name;
	});

	if (it == scenes.end())
		return;

	setActiveScene((*it)->getID());
}

bool SceneManager::initializePreviousScene()
{
	if (this->previous_scene == nullptr)
		return false;

	SceneManagerState::SCENEMANAGER_STATE = SceneManagerState::SceneManagerStateType::INITIALIZE;

	return initializeScene(this->previous_scene);
}
bool SceneManager::initializeActiveScene()
{
	if (this->active_scene == nullptr)
		return false;

	SceneManagerState::SCENEMANAGER_STATE = SceneManagerState::SceneManagerStateType::INITIALIZE;

	return initializeScene(this->active_scene);
}
bool SceneManager::initializeScene(Scene* scene)
{
	for (AbstractManager* manager : this->managers)
		scene->addManager(manager);

	if (!scene->getInitialized())
	{
		initializeManager<GameObjectManager>(getManager<GameObjectManager>());
		initializeManager<GeometryManager>(getManager<GeometryManager>());
		initializeManager<CameraManager>(getManager<CameraManager>());

		if (!scene->initialize())
			return false;

		scene->setInitialized(true);

		if (!scene->getPostInitialized())
		{
			if (!scene->postInitialize())
				return false;

			scene->setPostInitialized(true);
		}
	}

	return true;
}

bool SceneManager::shutdownPreviousScene()
{
	if (this->previous_scene == nullptr)
		return false;

	SceneManagerState::SCENEMANAGER_STATE = SceneManagerState::SceneManagerStateType::SHUTDOWN;

	return shutdownScene(this->previous_scene);
}
bool SceneManager::shutdownActiveScene()
{
	if (this->active_scene == nullptr)
		return false;

	SceneManagerState::SCENEMANAGER_STATE = SceneManagerState::SceneManagerStateType::SHUTDOWN;

	return shutdownScene(this->active_scene);
}
bool SceneManager::shutdownScene(Scene* scene)
{
	destroyManager<GameObjectManager>(getManager<GameObjectManager>());
	destroyManager<GeometryManager>(getManager<GeometryManager>());
	destroyManager<CameraManager>(getManager<CameraManager>());

	return scene->shutdown();
}

Scene* SceneManager::getActiveScene() const
{
	return this->active_scene;
}

void SceneManager::createManagers()
{
	//Create the game object factory
	GameObjectFactory::createInstance();

	GameObjectManager* game_object_manager = createManager<GameObjectManager>();
	LayerManager* layer_manager = createManager<LayerManager>();
	CameraManager* camera_manager = createManager<CameraManager>();
	ResourceManager* resource_manager = createManager<ResourceManager>();
	GeometryManager* geometry_manager = createManager<GeometryManager>();
	TextureManager* texture_manager = createManager<TextureManager>();
	TimerManager* timer_manager = createManager<TimerManager>();

	this->managers.push_back(game_object_manager);
	this->managers.push_back(layer_manager);
	this->managers.push_back(camera_manager);
	this->managers.push_back(resource_manager);
	this->managers.push_back(geometry_manager);
	this->managers.push_back(texture_manager);
	this->managers.push_back(timer_manager);

	for (AbstractManager* manager : this->managers)
		manager->initialize();

	game_object_manager->postInitialize();
}
void SceneManager::destroyManagers()
{
	for (AbstractManager* manager : this->managers)
	{
		manager->shutdown();
		SafeDelete(manager);
	}

	//Destroy the game object factory
	GameObjectFactory::destroyInstance();
}

template<typename T>
T* SceneManager::createManager()
{
	return new T();
}

template<typename T>
bool SceneManager::initializeManager(T* manager)
{
	return manager->initialize();
}
template<typename T>
bool SceneManager::shutdownManager(T* manager)
{
	return manager->shutdown();
}
template<typename T>
bool SceneManager::destroyManager(T* manager)
{
	if (!shutdownManager<T>(manager))
		return false;

	clearManager<T>(manager);

	return true;
}

template<typename T>
void SceneManager::clearManager(T* manager)
{
	manager->clear();
}