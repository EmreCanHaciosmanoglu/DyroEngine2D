#include "SceneGraph/Scene/Scene.h"

#ifndef _ALGORITHM
#include <algorithm>
#endif

#include "Defines\deletemacros.h"

#include "Helpers/Singleton.h"


Scene::Scene(const std::tstring& name)
	:Object(name)
{
}
Scene::~Scene()
{
}

bool Scene::initialize()
{
	return true;
}
void Scene::update()
{
}
void Scene::draw()
{
}
bool Scene::shutdown()
{
	return true;
}

void Scene::activate()
{
	Object::activate();
}
void Scene::deactive()
{
	Object::deactive();
}

void Scene::destroy()
{
	Object::destroy();
}