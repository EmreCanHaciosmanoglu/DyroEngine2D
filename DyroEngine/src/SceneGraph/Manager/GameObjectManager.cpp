#include "SceneGraph\Manager\GameObjectManager.h"
#include "SceneGraph\Objects\GameObjects\GameObject.h"
#include "SceneGraph\Objects\Components\Component.h"

#include "Core\System\Objects\Input.h"

#include "Rendering\Objects\Visualization\Visualization.h"
#include "Rendering\Factory\VisualizationFactory.h"
#include "Rendering\Manager\VisualizationManager.h"

#include "Core\Defines\assert.h"
#include "Core\Defines\deletemacros.h"

#include <algorithm>

GameObjectManager::GameObjectManager()
	:visualization_factory(nullptr)
	, visualization_manager(nullptr)
{
	this->visualization_manager = new VisualizationManager();
	this->visualization_factory = new VisualizationFactory();
}
GameObjectManager::~GameObjectManager()
{}

bool GameObjectManager::initialize()
{
	this->visualization_manager->initialize();

	for (const std::pair<unsigned int, GameObject*>& pair : getObjects())
	{
		if (pair.second->getInitialized())
			continue;

		if (!pair.second->initialize())
			return false;
	}

	return true;
}
bool GameObjectManager::postInitialize()
{
	std::vector<GameObject*> objects;
	getObjects(objects);

	for (const std::pair<unsigned int, GameObject*>& pair : getObjects())
	{
		if (pair.second->getPostInitialized())
			continue;

		if (!pair.second->postInitialize())
			return false;
	}

	return true;
}
void GameObjectManager::setupInput(Input* input)
{
	std::vector<GameObject*> objects;
	getObjects(objects);

	for (const std::pair<unsigned int, GameObject*>& pair : getObjects())
		pair.second->setupInput(input);
}
void GameObjectManager::update()
{
	std::vector<GameObject*> objects;
	getObjects(objects);

	for (const std::pair<unsigned int, GameObject*>& pair : getObjects())
	{
		if (pair.second->isActive())
			pair.second->update();
	}
}
bool GameObjectManager::shutdown()
{
	bool result = true;

	if (!this->visualization_manager->shutdown())
		result = false;

	SafeDelete(this->visualization_manager);
	SafeDelete(this->visualization_factory);

	for (const std::pair<unsigned int, GameObject*>& pair : getObjects())
	{
		if (!pair.second->shutdown())
			result = false;
		delete pair.second;
	}

	return true;
}

void GameObjectManager::addGameObject(GameObject* object)
{
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
	std::map<unsigned int, GameObject*> game_objects = getObjects();
	std::map<unsigned int, GameObject*>::const_iterator it = std::find_if(game_objects.begin(), game_objects.end(),
		[name](std::pair<unsigned int, GameObject*> pair) -> bool
	{
		return name == pair.second->getName();
	});

	return (*it).second;
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
const std::map<unsigned int, Visualization*>& GameObjectManager::getVisualizations() const
{
	return this->visualization_manager->getVisualizations();
}

bool GameObjectManager::addObject(unsigned int id, GameObject* object)
{
	if (!Manager<GameObject>::addObject(id, object))
		return false;

	Visualization* visualization = this->visualization_factory->createVisualization(object, object->hasChilderen());
	if (visualization != nullptr)
	{
		visualization->setScene(object->getScene());
		this->visualization_manager->addVisualization(visualization);
	}
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