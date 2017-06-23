#include "SceneGraph\Objects\Scenes\Scene.h"
#include "SceneGraph\Objects\GameObjects\GameObject.h"
#include "SceneGraph\Objects\GameObjects\Camera\Camera.h"
#include "SceneGraph\Objects\Components\CameraComponent.h"
#include "SceneGraph\Manager\GameObjectManager.h"
#include "SceneGraph\Manager\CameraManager.h"

#include "Rendering\Objects\Visualization\Visualization.h"
#include "Rendering\Manager\VisualizationManager.h"
#include "Rendering\Renderer.h"
#include "Rendering\DebugRenderer.h"

#include "Physics\Collision\ContactListener.h"
#include "Physics\Collision\ContactFilter.h"

#include "Core\System\Objects\Input.h"
#include "Core\System\Manager\SystemManager.h"
#include "Core\Defines\deletemacros.h"
#include "Core\Data\Manager\SettingsManager.h"
#include "Core\Data\Manager\LayerManager.h"
#include "Core\Data\Manager\TimerManager.h"
#include "Core\Data\Manager\GeometryManager.h"
#include "Core\Data\Objects\Settings\ApplicationSettings.h"
#include "Core\Data\Objects\Settings\GameSettings.h"
#include "Core\Data\Objects\Settings\PhysicsSettings.h"
#include "Core\Data\Objects\Layer.h"
#include "Core\Types\SettingsType.h"
#include "Core\Types\DebugRenderingType.h"
#include "Core\Types\SceneManagerStateType.h"

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
	, timer_manager(nullptr)
	, game_object_manager(nullptr)
	, app_settings(nullptr)
	, game_settings(nullptr)
	, physics_settings(nullptr)
{
	OBJECT_INIT(_T("Scene"));

	//Retireve the settings so we don't need to retrieve them every update
	this->app_settings = SettingsManager::getInstance().getSettings<ApplicationSettings>();
	this->game_settings = SettingsManager::getInstance().getSettings<GameSettings>();
	this->physics_settings = SettingsManager::getInstance().getSettings<PhysicsSettings>();
}
Scene::~Scene()
{
}

bool Scene::initialize()
{
	//Retrieve the managers so we don't need to retrieve them every update
	this->timer_manager = getManager<TimerManager>();
	this->game_object_manager = getManager<GameObjectManager>();

	if (this->timer_manager == nullptr || this->game_object_manager == nullptr)
		return false;

	this->renderer = new Renderer(this);
	
	setupSettings(SettingsData(this->app_settings, this->game_settings, this->physics_settings));
	setupPyhx();

	if (!this->game_object_manager->initialize())
		return false;

	return true;
}
bool Scene::postInitialize()
{
	Input* input = SystemManager::getInstance().getSystem<Input>();
	if (input == nullptr)
		return false;

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

	//Adjust gravity when needed
	if (Vector2D::toBox2DVec(this->physics_settings->getGravity()) != this->phyx_world->GetGravity())
		this->phyx_world = new b2World(Vector2D::toBox2DVec(this->physics_settings->getGravity()));

	//Update the physics world
	this->phyx_world->Step(this->physics_settings->getPhyxTimeStep(), this->physics_settings->getVelocityInterpolation(), this->physics_settings->getPositionInterpolation());

	//Update the contact listener so we can handle collision check when objects when still colliding
	this->contact_listener->update();
	//Update all the objects that are added to the scene
	this->game_object_manager->update();
}
void Scene::draw()
{
	std::vector<RenderItem*> items;

	if (debug_rendering_type == DebugRenderingType::ONLY_DEBUG || debug_rendering_type == DebugRenderingType::OVERLAY_DEBUG)
		this->phyx_world->DrawDebugData();

	if (debug_rendering_type != DebugRenderingType::ONLY_DEBUG)
	{
		ApplicationSettings* app_settings = SettingsManager::getInstance().getSettings<ApplicationSettings>();
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
bool Scene::shutdown()
{
	setInitialized(false);
	setPostInitialized(false);

	this->app_settings = nullptr;
	this->game_settings = nullptr;
	this->physics_settings = nullptr;
	this->timer_manager = nullptr;
	this->game_object_manager = nullptr;

	this->vec_managers.clear();

	this->debug_rendering_type = DebugRenderingType::NO_DEBUG;

	SafeDelete(this->debug_renderer);
	SafeDelete(this->contact_filter);
	SafeDelete(this->contact_listener);
	SafeDelete(this->phyx_world);
	SafeDelete(this->renderer);

	return true;
}

void Scene::setupInput(Input* input)
{
}
void Scene::setupSettings(const SettingsData& settings)
{
	settings.game_settings->setBackgroundColor(Color(0.16f, 0.15f, 0.18f));
}

void Scene::setDebugRenderingType(DebugRenderingType type)
{
	this->debug_rendering_type = type;
}

b2World* Scene::getPhyxWorld() const
{
	return this->phyx_world;
}
SettingsData Scene::getSettings() const
{
	return SettingsData{ this->app_settings,this->game_settings, this->physics_settings };
}

void Scene::addGameObject(GameObject* object)
{
	object->setScene(this);
	object->setLayer(getManager<LayerManager>()->getLayer(_T("Default")));

	//cache the game object manager for the first time
	if (this->game_object_manager == nullptr)
		this->game_object_manager = getManager<GameObjectManager>();

	this->game_object_manager->addGameObject(object);
	if (SceneManagerState::SCENEMANAGER_STATE == SceneManagerState::SceneManagerStateType::UPDATE)
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
void Scene::removeManager(AbstractManager* manager)
{
	std::vector<AbstractManager*>::const_iterator it = std::find(this->vec_managers.begin(), this->vec_managers.end(), manager);
	if (it == this->vec_managers.end())
		return;

	this->vec_managers.erase(it);
}

void Scene::setupPyhx()
{
	this->debug_renderer = new DebugRenderer(this->renderer);
	this->contact_filter = new ContactFilter();
	this->contact_listener = new ContactListener();

	PhysicsSettings* physicsSettings = SettingsManager::getInstance().getSettings<PhysicsSettings>();
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