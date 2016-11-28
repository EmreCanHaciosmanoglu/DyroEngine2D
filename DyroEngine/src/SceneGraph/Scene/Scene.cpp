#include "SceneGraph\Scene\Scene.h"
#include "SceneGraph\Object\GameObjects\GameObject.h"

#include "Core\System\Input.h"
#include "Core\System\Manager\SystemManager.h"

#include "Defines\deletemacros.h"

#include "Helpers\Singleton.h"

#include "Core\Settings\WorldSettings.h"
#include "Core\Settings\PhyxSettings.h"

#include "Interfaces\IDrawable.h"
#include "Interfaces\IDrawableDebugInfo.h"

#include "Diagnostics\DebugRenderer.h"

#include <Box2D\Box2D.h>

#include <algorithm>

Scene::Scene(const std::tstring& name)
	:Object(name)
	,phyx_world(nullptr)
	,debug_rendering(false)
{
}
Scene::~Scene()
{
}

bool Scene::initialize()
{
	setupPyhx();

	Input* input = dynamic_cast<Input*>(Singleton<SystemManager>::getInstance().getSystem(SystemType::INPUT_SYSTEM));
	this->setupInput(input);

	for (GameObject* obj : this->vec_objects)
	{
		if (obj->getInitialized())
			continue;

		obj->setupInput(input);

		if (!obj->initialize())
			return false;
	}

	return true;
}
void Scene::update()
{
	PhyxSettings* settings = Singleton<WorldSettings>::getInstance().getPhyxSettings();

	if(Vector2D::toBox2DVec(settings->getGravity()) != this->phyx_world->GetGravity())
		this->phyx_world = new b2World(Vector2D::toBox2DVec(settings->getGravity()));

	phyx_world->Step(settings->getPhyxTimeStep(), settings->getVelocityInterpolation(), settings->getPositionInterpolation());

	for (GameObject* obj : this->vec_objects)
	{
		if (obj->isActive())
			obj->update();
	}
}
void Scene::draw()
{
	if (!this->debug_rendering)
	{
		for (GameObject* obj : this->vec_objects)
		{
			IDrawable* drawable_obj = dynamic_cast<IDrawable*>(obj);
			if (drawable_obj == nullptr)
				continue;

			if (drawable_obj->getCanDraw())
				drawable_obj->draw();
		}
	}
	else
	{
		this->phyx_world->DrawDebugData();

		for (GameObject* obj : this->vec_objects)
		{
			IDrawableDebugInfo* drawable_obj = dynamic_cast<IDrawableDebugInfo*>(obj);
			if (drawable_obj == nullptr)
				continue;

			if (drawable_obj->getCanDrawDebugInfo())
				drawable_obj->drawDebugInfo();
		}
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

	SafeDelete(this->phyx_world);

	return true;
}

void Scene::setupPyhx()
{
	PhyxSettings* settings = Singleton<WorldSettings>::getInstance().getPhyxSettings();

	this->phyx_world = new b2World(Vector2D::toBox2DVec(settings->getGravity()));

	DebugRenderer* debug_renderer = getManager<DebugRenderer>();

	debug_renderer->SetFlags(b2Draw::e_shapeBit);
	debug_renderer->AppendFlags(b2Draw::e_centerOfMassBit);
	debug_renderer->AppendFlags(b2Draw::e_jointBit);
	debug_renderer->AppendFlags(b2Draw::e_pairBit);

	this->phyx_world->SetDebugDraw(debug_renderer);
}
void Scene::setupInput(Input* input)
{

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

void Scene::enableDebugRendering()
{
	this->debug_rendering = true;
}
void Scene::disableDebugRendering()
{
	this->debug_rendering = false;
}

b2World* Scene::getPhyxWorld()
{
	return this->phyx_world;
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

void Scene::addManager(Manager* manager)
{
	std::vector<Manager*>::const_iterator it = std::find(this->vec_managers.begin(), this->vec_managers.end(), manager);
	if (it != this->vec_managers.end())
		return;

	this->vec_managers.push_back(manager);
}