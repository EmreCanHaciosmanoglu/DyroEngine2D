#include "SceneGraph/Scene/Manager/SceneManager.h"
#include "SceneGraph/Scene/Scene.h"

#ifndef _ALGORITHM_
	#include <algorithm>
#endif

#include "Defines/assert.h"
#include "Defines/deletemacros.h"

#include "Helpers\Singleton.h"

SceneManager::SceneManager()
	:active_scene(nullptr)
{
}
SceneManager::~SceneManager()
{
}

bool SceneManager::initialize()
{
	setupManager<Renderer>();

	if (!this->active_scene->getInitialized())
	{
		this->active_scene->setRenderer(&Singleton<Renderer>::getInstance());

		if (!this->active_scene->initialize())
			return false;
		this->active_scene->setInitialized();
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
void SceneManager::draw()
{
	//Initialize the scene before trying to draw it.
	assert(this->active_scene->getInitialized());

	if (this->active_scene->getCanDraw() && this->active_scene->isActive())
		this->active_scene->draw();
}
bool SceneManager::shutdown()
{
	for (Scene* scene : this->vec_scenes)
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

	destroyManager<Renderer>();

	return true;
}

void SceneManager::addScene(Scene* scene)
{
	std::vector<Scene*>::iterator it = std::find(vec_scenes.begin(), vec_scenes.end(), scene);
	if (it == vec_scenes.end())
		vec_scenes.push_back(scene);
}

void SceneManager::setActiveScene(const std::tstring& name)
{
	std::vector<Scene*>::iterator it = std::find_if(vec_scenes.begin(), vec_scenes.end(), 
		[name](Scene* scene) -> bool
	{
		return scene->getName() == name;
	});

	//Scene with given name was not found.
	assert(it != vec_scenes.end());

	if (this->active_scene)
	{
		this->active_scene->deactive();
		this->active_scene->destroy();
	}

	this->active_scene = (*it);
	this->active_scene->activate();

}
Scene* SceneManager::getActiveScene() const
{
	return this->active_scene;
}