#include "SceneGraph/Manager/SceneManager.h"

#ifndef _ALGORITHM_
#include <algorithm>
#endif

#include "Core/Defines/assert.h"
#include "Core/Defines/deletemacros.h"
#include "Core/Defines/renderlayers.h"

#include "Core/Helpers/Patterns/Singleton.h"
#include "Core/Helpers/Patterns/Manager.h"

#include "Core/Data/Objects/Layer.h"

SceneManager::SceneManager()
	:active_scene(nullptr)
{
}
SceneManager::~SceneManager()
{
}

bool SceneManager::initialize()
{
	LayerManager* layer_manager = createManager<LayerManager>();
	CameraManager* camera_manager = createManager<CameraManager>();
	ResourceManager* resource_manager = createManager<ResourceManager>();
	GeometryManager* geometry_manager = createManager<GeometryManager>();
	TextureManager* texture_manager = createManager<TextureManager>();
	TimerManager* timer_manager = createManager<TimerManager>();

	if (!this->active_scene->getInitialized())
	{
		layer_manager->addLayer(new Layer(layers::DEFAULT_LAYER, _T("Default")));
		layer_manager->addLayer(new Layer(layers::UI_LAYER, _T("UI")));
		layer_manager->addLayer(new Layer(layers::DEBUG_LAYER, _T("Debug")));
		layer_manager->addLayer(new Layer(layers::BACKGROUND_LAYER, _T("Background")));

		this->active_scene->addManager(layer_manager);
		this->active_scene->addManager(camera_manager);
		this->active_scene->addManager(resource_manager);
		this->active_scene->addManager(geometry_manager);
		this->active_scene->addManager(texture_manager);
		this->active_scene->addManager(timer_manager);

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
		this->active_scene->shutdown();
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