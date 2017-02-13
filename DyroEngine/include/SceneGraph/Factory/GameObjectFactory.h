#ifndef _GAMEOBJECTFACTORY_H
#define _GAMEOBJECTFACTORY_H

#include "Core/Helpers/Patterns/Singleton.h"

#ifndef _ASSERT_H
#include "Core/Defines/assert.h"
#endif

#ifndef _GAMEOBJECT_H
#include "SceneGraph\Objects\GameObjects\GameObject.h"
#endif
#ifndef _SCENE_H
#include "SceneGraph\Objects\Scenes\Scene.h"
#endif

class GameObjectFactory : public Singleton<GameObjectFactory>
{
public:
	GameObjectFactory();
	virtual ~GameObjectFactory();

	void setScene(Scene* scene);

	template <typename T>
	T* createObject() const;

private:
	Scene* scene;
};

template <typename T>
T* GameObjectFactory::createObject() const
{
	T* object = new T();

#ifndef NDEBUG
	//Object needs to be a "GameObject"
	assert(dynamic_cast<GameObject*>(object) != nullptr);
#endif

	if (object != nullptr)
		this->scene->addGameObject(object);

	return object;
}

#endif