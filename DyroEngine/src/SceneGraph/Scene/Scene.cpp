#include "SceneGraph/Scene/Scene.h"
#include "SceneGraph/Object/GameObjects/GameObject.h"

#ifndef _ALGORITHM
#include <algorithm>
#endif

#include "Defines\deletemacros.h"

#include "Helpers/Singleton.h"

#include "Interfaces/IDrawable.h"

Scene::Scene(const std::tstring& name)
	:Object(name)
	,renderer(nullptr)
{
}
Scene::~Scene()
{
}

bool Scene::initialize()
{
	for (GameObject* obj : this->vec_objects)
	{
		if (obj->getInitialized())
			continue;
		if (!obj->initialize())
			return false;
	}

	return true;
}
void Scene::update()
{
	for (GameObject* obj : this->vec_objects)
	{
		if (obj->isActive())
			obj->update();
	}
}
void Scene::draw()
{
	for (GameObject* obj : this->vec_objects)
	{
		IDrawable* drawable_obj = dynamic_cast<IDrawable*>(obj);
		if(drawable_obj == nullptr)
			continue;

		if(drawable_obj->getCanDraw())
			drawable_obj->draw();
	}
}
bool Scene::shutdown()
{
	for (GameObject* obj : this->vec_objects)
	{
		if (!obj->shutdown())
			return false;
		SafeDelete(obj);
	}
	this->vec_objects.clear();

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

void Scene::addGameObject(GameObject* object)
{
	std::vector<GameObject*>::iterator it = std::find(this->vec_objects.begin(), this->vec_objects.end(), object);
	if (it == this->vec_objects.end())
	{
		this->vec_objects.push_back(object);
		object->setScene(this);
	}
}
void Scene::removeGameObject(GameObject* object)
{
	std::vector<GameObject*>::iterator it = std::find(this->vec_objects.begin(), this->vec_objects.end(), object);
	if (it != this->vec_objects.end())
	{
		this->vec_objects.erase(it);
		SafeDelete((*it));
	}
}

void Scene::setRenderer(Renderer* renderer)
{
	this->renderer = renderer;
}
Renderer* Scene::getRenderer() const
{
	return this->renderer;
}