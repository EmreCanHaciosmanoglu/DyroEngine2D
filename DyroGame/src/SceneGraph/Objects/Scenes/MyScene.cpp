#include "SceneGraph\Objects\Scenes\MyScene.h"

#include "SceneGraph\Objects\GameObjects\Camera\FreeCamera.h"

#include "SceneGraph\Objects\GameObjects\SceneObject.h"
#include "SceneGraph\Objects\GameObjects\PhysicsObject.h"

#include "SceneGraph\Objects\Components\Shapes\RectShapeComponent.h"
#include "SceneGraph\Objects\Components\Shapes\TriangleShapeComponent.h"
#include "SceneGraph\Objects\Components\Shapes\CircleShapeComponent.h"
#include "SceneGraph\Objects\Components\TransformComponent.h"
#include "SceneGraph\Objects\Components\Physics\Collision\BoxCollisionComponent.h"
#include "SceneGraph\Objects\Components\Physics\Collision\CircleCollisionComponent.h"
#include "SceneGraph\Objects\Components\Physics\Collision\TriangleCollisionComponent.h"

#include "Core\System\Objects\Input.h"

#include "Core\Helpers/Patterns\Singleton.h"

#include "Core/Types/SettingsType.h"

#include "Core\Data\Manager\SettingsManager.h"

#include "Core\Data\Objects\Settings\ApplicationSettings.h"
#include "Core\Data\Objects\Settings\GameSettings.h"
#include "Core\Data\Objects\Descriptions\Shapes\CircleShapeDescription.h"
#include "Core\Data\Objects\Descriptions\Shapes\RectShapeDescription.h"
#include "Core\Data\Objects\Descriptions\Shapes\TriangleShapeDescription.h"

// DyroGame
#include "SceneGraph\Objects\GameObjects\CrazyEmitter.h"

namespace
{
	const int RECT_AMOUNT = 3;
	const int CIRCLE_AMOUNT = 2;
	const int TRIANGLE_AMOUNT = 2;

	const int CIRCLE_RADIUS = 10;

	const int TRIANGLE_SCALE = 10;

	const int RECT_WIDTH = 20;
	const int RECT_HEIGHT = 20;

	const int GROUND_RECT_WIDTH = 1280;
	const int GROUND_RECT_HEIGHT = 100;
}

MyScene::MyScene()
	:Scene(_T("MyScene"))
{
	OBJECT_INIT(_T("MyScene"));
}
MyScene::~MyScene()
{
}

bool MyScene::initialize()
{
	ApplicationSettings* app_settings = dynamic_cast<ApplicationSettings*>(SettingsManager::getInstance().getSettings(SettingsType::APPLICATION_SETTINGS));
	if (app_settings == nullptr)
		return false;

	GameSettings* game_settings = dynamic_cast<GameSettings*>(SettingsManager::getInstance().getSettings(SettingsType::GAME_SETTINGS));
	if (game_settings == nullptr)
		return false;

	float window_width = (float)app_settings->getWindowWidth();
	float window_height = (float)app_settings->getWindowHeight();

	game_settings->setBackgroundColor(Color(0.16f, 0.15f, 0.18f));

	addGameObject(new FreeCamera(_T("Main Camera"), 200.0f));

	float step_rect = window_width / (RECT_AMOUNT + 1);
	for (int i = 0; i < RECT_AMOUNT; ++i)
	{
		PhysicsObject* phyx_object = new PhysicsObject(BodyType::DYNAMIC);
		phyx_object->setName(_T("BOX_") + std::tstring(TOSTRING(i)));
		phyx_object->getTransform()->setPosition(Vector2D(step_rect * (i + 1), 0.0f));

		phyx_object->addComponent(new RectShapeComponent(new RectShapeDescription(0, 0, RECT_WIDTH, RECT_HEIGHT)));
		phyx_object->addComponent(new BoxCollisionComponent(phyx_object->getRigidBody(), (float)RECT_WIDTH, (float)RECT_HEIGHT, 0.5f, 0.5f, 1.0f));

		addGameObject(phyx_object);
	}
	float step_circle = window_width / (CIRCLE_AMOUNT + 1);
	for (int i = 0; i < CIRCLE_AMOUNT; ++i)
	{
		PhysicsObject* phyx_object = new PhysicsObject(BodyType::DYNAMIC);
		phyx_object->setName(_T("CIRCLE_") + std::tstring(TOSTRING(i)));
		phyx_object->getTransform()->setPosition(Vector2D(step_circle * (i + 1), 0.0f));

		phyx_object->addComponent(new CircleShapeComponent(new CircleShapeDescription(0, 0, (float)CIRCLE_RADIUS)));
		phyx_object->addComponent(new CircleCollisionComponent(phyx_object->getRigidBody(), (float)CIRCLE_RADIUS));

		addGameObject(phyx_object);
	}
	float step_triangle = window_width / (TRIANGLE_AMOUNT + 1);
	for (int i = 0; i < TRIANGLE_AMOUNT; ++i)
	{
		PhysicsObject* phyx_object = new PhysicsObject(BodyType::DYNAMIC);
		phyx_object->setName(_T("TRIANGLE_") + std::tstring(TOSTRING(i)));
		phyx_object->getTransform()->setPosition(Vector2D(step_triangle * (i + 1), 100.0f));

		phyx_object->addComponent(new TriangleShapeComponent(new TriangleShapeDescription((float)TRIANGLE_SCALE, (float)TRIANGLE_SCALE,true)));
		phyx_object->addComponent(new TriangleCollisionComponent(phyx_object->getRigidBody(), (float)TRIANGLE_SCALE, (float)TRIANGLE_SCALE));

		addGameObject(phyx_object);
	}

	PhysicsObject* ground_object = new PhysicsObject(BodyType::STATIC);
	ground_object->setName(_T("GROUND_OBJECT"));
	ground_object->getTransform()->setPosition(Vector2D(window_width / 2, window_height - GROUND_RECT_HEIGHT / 2));

	ground_object->addComponent(new RectShapeComponent(new RectShapeDescription(0, 0, GROUND_RECT_WIDTH, GROUND_RECT_HEIGHT)));
	ground_object->addComponent(new BoxCollisionComponent(ground_object->getRigidBody(), (float)GROUND_RECT_WIDTH, (float)GROUND_RECT_HEIGHT, 0.0f, 0.5f, 1.0f));

	addGameObject(ground_object);

	return Scene::initialize();
}
void MyScene::update()
{
	Scene::update();
}
bool MyScene::shutdown()
{
	return Scene::shutdown();
}

void MyScene::setupInput(Input* input)
{
	input->bindInput(InputBinding(VK_F1, std::bind(&Scene::enableDebugRendering, this), InputStateType::PRESSED));
	input->bindInput(InputBinding(VK_F2, std::bind(&Scene::disableDebugRendering, this), InputStateType::PRESSED));
}