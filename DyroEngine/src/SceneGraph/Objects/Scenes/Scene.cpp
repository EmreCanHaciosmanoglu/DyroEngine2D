#include "SceneGraph\Objects\Scenes\Scene.h"

#include "SceneGraph\Objects\GameObjects\GameObject.h"
#include "SceneGraph\Manager\GameObjectManager.h"
#include "SceneGraph\Factory\GameObjectFactory.h"

#include "Core\System\Objects\Input.h"
#include "Core\System\Manager\SystemManager.h"

#include "Rendering/Objects/Visualization/Visualization.h"
#include "Rendering\Manager\VisualizationManager.h"

#include "Core\Defines\deletemacros.h"

#include "Physics\Collision\ContactListener.h"
#include "Physics\Collision\ContactFilter.h"

#include "Core\Data\Manager\SettingsManager.h"
#include "Core\Data\Manager\LayerManager.h"
#include "Core\Data\Manager\TimerManager.h"

#include "SceneGraph\Objects\GameObjects\Camera\Camera.h"
#include "SceneGraph\Objects\Components\CameraComponent.h"

#include "Core/Data/Objects/Settings/ApplicationSettings.h"
#include "Core/Data/Objects/Settings/GameSettings.h"
#include "Core/Data/Objects/Settings/PhysicsSettings.h"
#include "Core\Data\Objects\Layer.h"

#include "Core/Types/SettingsType.h"
#include "Core/Types/DebugRenderingType.h"
#include "Core/Types/EngineStateType.h"

#include "Rendering\Renderer.h"
#include "Rendering\DebugRenderer.h"

#include <Box2D\Box2D.h>

#include <algorithm>

Scene::Scene(const std::tstring& name)
	:Object(name)
	, phyx_world(nullptr)
	, debug_rendering_type(DebugRenderingType::NO_DEBUG)
	, renderer(nullptr)
	, debug_renderer(nullptr)
	, contact_filter(nullptr)
	, contact_listener(nullptr)
	, game_object_manager(nullptr)
	, timer_manager(nullptr)
{
	OBJECT_INIT(_T("Scene"));

	//Create the game object factory
	if (!GameObjectFactory::hasInstance())
		GameObjectFactory::createInstance();

	GameObjectFactory::getInstance().setScene(this);

	this->game_object_manager = new GameObjectManager();
	addManager(this->game_object_manager);
}
Scene::~Scene()
{
	//Destroy teh game object factory
	GameObjectFactory::destroyInstance();
}

bool Scene::initialize()
{
	this->renderer = new Renderer(this);

	ApplicationSettings* app_settings = dynamic_cast<ApplicationSettings*>(SettingsManager::getInstance().getSettings(SettingsType::APPLICATION_SETTINGS));
	if (app_settings == nullptr)
		return false;
	GameSettings* game_settings = dynamic_cast<GameSettings*>(SettingsManager::getInstance().getSettings(SettingsType::GAME_SETTINGS));
	if (app_settings == nullptr)
		return false;
	PhysicsSettings* p_settings = dynamic_cast<PhysicsSettings*>(SettingsManager::getInstance().getSettings(SettingsType::PHYSICS_SETTINGS));
	if (app_settings == nullptr)
		return false;

	setupSettings(SettingsData(app_settings, game_settings, p_settings));
	setupPyhx();

	if (!this->game_object_manager->initialize())
		return false;

	//Retrieve the managers so we don't need to retrieve it every update
	this->timer_manager = getManager<TimerManager>();

	return true;
}
bool Scene::postInitialize()
{
	Input* input = dynamic_cast<Input*>(SystemManager::getInstance().getSystem(SystemType::INPUT_SYSTEM));
	this->setupInput(input);

	this->game_object_manager->setupInput(input);
	if (!this->game_object_manager->postInitialize())
		return false;

	return true;
}
void Scene::update()
{
	//Update managers
	this->timer_manager->update();

	//Retrieve the physics settings
	PhysicsSettings* physicsSettings = dynamic_cast<PhysicsSettings*>(SettingsManager::getInstance().getSettings(SettingsType::PHYSICS_SETTINGS));
	if (physicsSettings == nullptr)
		return;

	//Adjust gravity when needed
	if (Vector2D::toBox2DVec(physicsSettings->getGravity()) != this->phyx_world->GetGravity())
		this->phyx_world = new b2World(Vector2D::toBox2DVec(physicsSettings->getGravity()));

	//Update the physics world
	this->phyx_world->Step(physicsSettings->getPhyxTimeStep(), physicsSettings->getVelocityInterpolation(), physicsSettings->getPositionInterpolation());

	//Update the contact listener so we can handle collision check when objects when still colliding
	this->contact_listener->update();
	//Update all the objects that are added to the scene
	this->game_object_manager->update();

	//Renderer the scene after all calculations are done
	triggerRender();
}
bool Scene::shutdown()
{
	bool result = true;

	for (AbstractManager* manager : this->vec_managers)
	{
		if (!manager->shutdown())
			return false;
		SafeDelete(manager);
	}

	SafeDelete(this->debug_renderer);
	SafeDelete(this->contact_filter);
	SafeDelete(this->contact_listener);
	SafeDelete(this->phyx_world);

	SafeDelete(this->renderer);

	return result;
}

void Scene::setupInput(Input* input)
{
}
void Scene::setupSettings(const SettingsData& settings)
{
	settings.game_settings->setBackgroundColor(Color(0.16f, 0.15f, 0.18f));
}

void Scene::activate()
{
	Object::activate();
}
void Scene::deactive()
{
	Object::deactive();
}

void Scene::setDebugRenderingType(DebugRenderingType type)
{
	this->debug_rendering_type = type;
}

b2World* Scene::getPhyxWorld()
{
	return this->phyx_world;
}

void Scene::addGameObject(GameObject* object)
{
	object->setScene(this);
	object->setLayer(getManager<LayerManager>()->getLayer(_T("Default")));

	this->game_object_manager->addGameObject(object);
	if (EngineState::ENGINE_STATE == EngineState::EngineStateType::RUNNING)
	{
		object->initialize();
		object->postInitialize();
	}
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
Visualization* Scene::getVisualization(const GameObject* object) const
{
	return this->game_object_manager->getVisualization(object);
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
	this->debug_renderer = new DebugRenderer(this->renderer);
	this->contact_filter = new ContactFilter();
	this->contact_listener = new ContactListener();

	PhysicsSettings* physicsSettings = dynamic_cast<PhysicsSettings*>(SettingsManager::getInstance().getSettings(SettingsType::PHYSICS_SETTINGS));
	if (physicsSettings == nullptr)
		return;

	this->phyx_world = new b2World(Vector2D::toBox2DVec(physicsSettings->getGravity()));

	debug_renderer->SetFlags(b2Draw::e_shapeBit);
	debug_renderer->AppendFlags(b2Draw::e_centerOfMassBit);
	debug_renderer->AppendFlags(b2Draw::e_jointBit);
	debug_renderer->AppendFlags(b2Draw::e_pairBit);

	this->phyx_world->SetDebugDraw(debug_renderer);
	this->phyx_world->SetContactFilter(this->contact_filter);
	this->phyx_world->SetContactListener(this->contact_listener);
}

void Scene::triggerRender()
{
	std::vector<RenderItem*> items;

	if (debug_rendering_type == DebugRenderingType::ONLY_DEBUG || debug_rendering_type == DebugRenderingType::OVERLAY_DEBUG)
		this->phyx_world->DrawDebugData();

	if (debug_rendering_type != DebugRenderingType::ONLY_DEBUG)
	{
		ApplicationSettings* app_settings = dynamic_cast<ApplicationSettings*>(SettingsManager::getInstance().getSettings(SettingsType::APPLICATION_SETTINGS));
		if (app_settings == nullptr)
			return;

		int window_width = app_settings->getWindowWidth();
		int window_height = app_settings->getWindowHeight();

		Rect2D screen_bounds(0, 0, window_width, window_height);

		//Get all visualizations that are visible in the screen
		std::map<unsigned int, Visualization*> visualizations = this->game_object_manager->getVisualizations();
		for (const std::pair<unsigned int, Visualization*>& pair : visualizations)
		{
			Rect2D visualization_bounds = pair.second->getBoundingBox();

			if (screen_bounds.overlaps(visualization_bounds))
				pair.second->getRenderItems(items);
		}
	}

	//Render visualizations
	RenderInfo info;
	info.items = items;
	info.mat_view = getManager<CameraManager>()->getActiveCamera()->getCamera()->getViewMatrix();

	this->renderer->render(info);

	//Clear the render item list
	items.clear();
}