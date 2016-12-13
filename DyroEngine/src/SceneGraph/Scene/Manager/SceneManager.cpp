#include "SceneGraph/Scene/Manager/SceneManager.h"
#include "SceneGraph/Scene/Scene.h"

#ifndef _ALGORITHM_
	#include <algorithm>
#endif

#include "Defines/assert.h"
#include "Defines/deletemacros.h"

#include "Helpers\Singleton.h"
#include "Helpers\Manager.h"

SceneManager::SceneManager()
	:active_scene(nullptr)
{
}
SceneManager::~SceneManager()
{
}

bool SceneManager::initialize()
{
	setupManager<CameraManager>();
	setupManager<ResourceManager>();

	if (!this->active_scene->getInitialized())
	{
		this->active_scene->addManager(&Singleton<CameraManager>::getInstance());
		this->active_scene->addManager(&Singleton<ResourceManager>::getInstance());

		if (!this->active_scene->initialize())
			return false;
		this->active_scene->setInitialized();

		if (!this->active_scene->getPostInitialized())
		{
			if (!this->active_scene->postInitialize())
				return false;
			this->active_scene->setPostInitialized();
		}
	}
	return true;
}
void SceneManager::update()
{
	//Initialize the scene before trying to update it.
	assert(this->active_scene->getInitialized());

	if (this->active_scene->isActive())
		this->active_scene->update();
}
bool SceneManager::shutdown()
{
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

	destroyManager<ResourceManager>();
	destroyManager<CameraManager>();

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

	if (this->active_scene)
	{
		this->active_scene->deactive();
		this->active_scene->destroy();
	}

	this->active_scene = scene;
	this->active_scene->activate();
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

	setActiveScene((*it)->getID());
}
Scene* SceneManager::getActiveScene() const
{
	return this->active_scene;
}