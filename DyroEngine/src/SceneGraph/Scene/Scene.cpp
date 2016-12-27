#include "SceneGraph\Scene\Scene.h"

#include "SceneGraph\GameObjects\GameObject.h"
#include "SceneGraph\GameObjects\Manager\GameObjectManager.h"

#include "Core\System\Input.h"
#include "Core\System\Manager\SystemManager.h"

#include "Core\Rendering\Visualization\Objects\Visualization.h"
#include "Core\Rendering\Visualization\Manager\VisualizationManager.h"

#include "Defines\deletemacros.h"

#include "Helpers\Patterns/Singleton.h"
#include "Helpers\Collision\ContactListener.h"
#include "Helpers\Collision\ContactFilter.h"

#include "Core\Settings\WorldSettings.h"
#include "Core\Settings\PhyxSettings.h"

#include "Diagnostics\DebugRenderer.h"

#include <Box2D\Box2D.h>

#include <algorithm>

Scene::Scene(const std::tstring& name)
	:Object(name)
	, phyx_world(nullptr)
	, debug_rendering(false)
	, debug_renderer(nullptr)
	, contact_filter(nullptr)
	, contact_listener(nullptr)
	, game_object_manager(nullptr)
{
	OBJECT_INIT(_T("Scene"));

	this->game_object_manager = new GameObjectManager();
	addManager(this->game_object_manager);
}
Scene::~Scene()
{
}

bool Scene::initialize()
{
	setupPyhx();

	if (!this->game_object_manager->initialize())
		return false;

	return true;
}
bool Scene::postInitialize()
{
	Input* input = dynamic_cast<Input*>(Singleton<SystemManager>::getInstance().getSystem(SystemType::INPUT_SYSTEM));
	this->setupInput(input);

	this->game_object_manager->setupInput(input);
	if (!this->game_object_manager->postInitialize())
		return false;

	return true;
}
void Scene::update()
{
	PhyxSettings* settings = Singleton<WorldSettings>::getInstance().getPhyxSettings();

	if (Vector2D::toBox2DVec(settings->getGravity()) != this->phyx_world->GetGravity())
		this->phyx_world = new b2World(Vector2D::toBox2DVec(settings->getGravity()));

	this->phyx_world->Step(settings->getPhyxTimeStep(), settings->getVelocityInterpolation(), settings->getPositionInterpolation());

	//Update the contact listener so we can handle collision check when objects when still colliding
	this->contact_listener->update();

	this->game_object_manager->update();
}
bool Scene::shutdown()
{
	bool result = true;

	if (!this->game_object_manager->shutdown())
		result = false;

	SafeDelete(this->game_object_manager);
	SafeDelete(this->debug_renderer);
	SafeDelete(this->contact_filter);
	SafeDelete(this->contact_listener);

	SafeDelete(this->phyx_world);

	return result;
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
	object->setScene(this);
	this->game_object_manager->addGameObject(object);
}
void Scene::removeGameObject(GameObject* object)
{
	this->game_object_manager->removeGameObject(object);
}
void Scene::removeGameObject(unsigned int id)
{
	this->game_object_manager->removeGameObject(id);
}

void Scene::getGameObjects(std::vector<GameObject*>& objects) const
{
	this->game_object_manager->getGameObjects(objects);
}
void Scene::getVisualizations(std::vector<Visualization*>& visualizations) const
{
	this->game_object_manager->getVisualizations(visualizations);
}

void Scene::addManager(AbstractManager* manager)
{
	std::vector<AbstractManager*>::const_iterator it = std::find(this->vec_managers.begin(), this->vec_managers.end(), manager);
	if (it != this->vec_managers.end())
		return;

	this->vec_managers.push_back(manager);
}

void Scene::setupPyhx()
{
	this->debug_renderer = new DebugRenderer();
	this->contact_filter = new ContactFilter();
	this->contact_listener = new ContactListener();

	PhyxSettings* settings = Singleton<WorldSettings>::getInstance().getPhyxSettings();

	this->phyx_world = new b2World(Vector2D::toBox2DVec(settings->getGravity()));

	debug_renderer->SetFlags(b2Draw::e_shapeBit);
	debug_renderer->AppendFlags(b2Draw::e_centerOfMassBit);
	debug_renderer->AppendFlags(b2Draw::e_jointBit);
	debug_renderer->AppendFlags(b2Draw::e_pairBit);

	this->phyx_world->SetDebugDraw(debug_renderer);
	this->phyx_world->SetContactFilter(this->contact_filter);
	this->phyx_world->SetContactListener(this->contact_listener);
}