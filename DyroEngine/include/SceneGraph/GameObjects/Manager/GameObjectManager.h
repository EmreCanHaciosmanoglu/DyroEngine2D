#ifndef _GAMEOBJECTMANAGER_H
#define _GAMEOBJECTMANAGER_H

#include "Helpers\Manager.h"

class GameObject;
class VisualizationManager;

class GameObjectManager : public Manager<GameObject>
{
public:
	GameObjectManager();
	virtual ~GameObjectManager();

	virtual bool initialize();
	virtual bool shutdown();

	void addGameObject(GameObject* object);

	void removeGameObject(unsigned int id);
	void removeGameObject(GameObject* object);

	GameObject* getGameObject(const std::tstring& name);
	GameObject* getGameObject(unsigned int id);

	void getGameObjects(std::vector<GameObject*>& objects);
	void getGameObjects(std::map<unsigned int, GameObject*>& objects);

protected:

	virtual bool addObject(unsigned int id, GameObject* object);

	virtual bool removeObject(unsigned int id);
	virtual bool removeObject(GameObject* object);

private:
	VisualizationManager* visualization_manager;
};

#endif