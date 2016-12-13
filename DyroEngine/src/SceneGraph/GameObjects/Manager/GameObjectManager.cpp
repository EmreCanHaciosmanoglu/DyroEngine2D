#include "SceneGraph\GameObjects\Manager\GameObjectManager.h"
#include "SceneGraph\GameObjects\GameObject.h"
#include "SceneGraph\Component\Component.h"

#include "Core\Rendering\Visualization\Manager\VisualizationFactory.h"
#include "Core\Rendering\Visualization\Manager\VisualizationManager.h"

#include "Defines\assert.h"

#include <algorithm>

GameObjectManager::GameObjectManager()
	:visualization_factory(nullptr)
	,visualization_manager(nullptr)
{
	this->visualization_manager = new VisualizationManager();
	this->visualization_factory = new VisualizationFactory();
}
GameObjectManager::~GameObjectManager()
{}

bool GameObjectManager::initialize()
{
	this->visualization_manager = new VisualizationManager();
	this->visualization_manager->initialize();

	std::vector<GameObject*> objects;
	getObjects(objects);

	for (GameObject* obj : objects)
	{
		if (obj->getInitialized())
			continue;

		if (!obj->initialize())
			return false;
	}

	return true;
}
bool GameObjectManager::shutdown()
{
	this->visualization_manager->shutdown();

	SafeDelete(this->visualization_manager);
	SafeDelete(this->visualization_factory);

	std::vector<GameObject*> objects;
	getObjects(objects);

	for (GameObject* obj : objects)
	{
		if (!obj->shutdown())
			return false;
		SafeDelete(obj);
	}

	return true;
}

void GameObjectManager::addGameObject(GameObject* object)
{
	assert(object == nullptr);

	addObject(object->getID(), object);
}

void GameObjectManager::removeGameObject(unsigned int id)
{
	removeObject(id);
}
void GameObjectManager::removeGameObject(GameObject* object)
{
	removeObject(object);
}

GameObject* GameObjectManager::getGameObject(const std::tstring& name) const
{
	std::vector<GameObject*> game_objects;
	getObjects(game_objects);

	std::vector<GameObject*>::const_iterator it = std::find_if(game_objects.begin(),game_objects.end(),
		[name](GameObject* object) -> bool
	{
		return name == object->getName();
	});

	return getObject((*it)->getID());
}
GameObject* GameObjectManager::getGameObject(unsigned int id) const
{
	return getObject(id);
}

void GameObjectManager::getGameObjects(std::vector<GameObject*>& objects) const
{
	getObjects(objects);
}
const std::map<unsigned int, GameObject*>& GameObjectManager::getGameObjects() const
{
	return getObjects();
}
void GameObjectManager::getVisualizations(std::vector<Visualization*>& visualizations) const
{
	this->visualization_manager->getVisualizations(visualizations);
}
const std::map<unsigned int, Visualization*> GameObjectManager::getVisualizations() const
{
	return this->visualization_manager->getVisualizations();
}

bool GameObjectManager::addObject(unsigned int id, GameObject* object)
{
	if (!Manager<GameObject>::addObject(id, object))
		return false;

	this->visualization_manager->addVisualization(this->visualization_factory->createVisualization(object));
	return true;
}

bool GameObjectManager::removeObject(unsigned int id)
{
	return Manager<GameObject>::removeObject(getObject(id));
}
bool GameObjectManager::removeObject(GameObject* object)
{
	if (!Manager<GameObject>::removeObject(object))
		return false;

	this->visualization_manager->removeVisualizations(object);
	return true;
}