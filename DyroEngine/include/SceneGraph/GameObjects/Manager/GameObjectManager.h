#ifndef _GAMEOBJECTMANAGER_H
#define _GAMEOBJECTMANAGER_H

#include "Helpers\Manager.h"

#ifndef _VECTOR_H
#include <vector>
#endif
#ifndef _MAP_
#include <map>
#endif

class GameObject;

class Visualization;
class VisualizationManager;
class VisualizationFactory;

class Input;

class GameObjectManager : public Manager<GameObject>
{
public:
	GameObjectManager();
	virtual ~GameObjectManager();

	virtual bool initialize();
	virtual bool postInitialize();
	virtual void setupInput(Input* input);
	virtual void update();
	virtual bool shutdown();

	void addGameObject(GameObject* object);

	void removeGameObject(unsigned int id);
	void removeGameObject(GameObject* object);

	GameObject* getGameObject(const std::tstring& name) const;
	GameObject* getGameObject(unsigned int id) const;

	void getGameObjects(std::vector<GameObject*>& objects) const;
	const std::map<unsigned int, GameObject*>& getGameObjects() const;

	void getVisualizations(std::vector<Visualization*>& visualizations) const;
	const std::map<unsigned int, Visualization*> getVisualizations() const;

protected:

	virtual bool addObject(unsigned int id, GameObject* object);

	virtual bool removeObject(unsigned int id);
	virtual bool removeObject(GameObject* object);

private:
	VisualizationFactory* visualization_factory;
	VisualizationManager* visualization_manager;
};

#endif