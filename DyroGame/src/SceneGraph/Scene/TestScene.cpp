#include "SceneGraph\Scene\TestScene.h"

#include "SceneGraph\Object\GameObjects\Camera\FollowCamera.h"
#include "SceneGraph\Object\GameObjects\Camera\FreeCamera.h"

#include "SceneGraph\Object\GameObjects\PhysicsObject.h"
#include "SceneGraph\Object\GameObjects\Obstacle.h"

#include "SceneGraph\Object\GameObjects\Spaceship.h"
#include "SceneGraph\Object\GameObjects\Astroid.h"

#include "SceneGraph\Object\Objects\Shapes\RectShape.h"
#include "SceneGraph\Object\Objects\Shapes\CircleShape.h"
#include "SceneGraph\Object\Objects\Timer.h"

#include "SceneGraph\Component\TransformComponent.h"
#include "SceneGraph\Component\ShapeComponent.h"

#include "SceneGraph\Component\Collision\BoxCollisionComponent.h"
#include "SceneGraph\Component\Collision\CircleCollisionComponent.h"

#include "Core\System\Manager\SystemManager.h"
#include "Core\System\Input.h"
#include "Core\System\MainTimer.h"

#include "Helpers\Singleton.h"

#include "Core\Settings\WorldSettings.h"
#include "Core\Settings\ApplicationSettings.h"
#include "Core\Settings\GameSettings.h"

#include "Diagnostics\Logger.h"

namespace
{
	const std::tstring ASTROID_SPAWN_TIMER_NAME = _T("astroid_spawn_timer");

	const float PI = 3.1415f;

	const float BORDER_WIDTH = 50.0f;
	const float BORDER_HEIGHT = 50.0f;

	const double ASTROID_SPAWN_TIMER_THRESHOLD = 50.0;
}

TestScene::TestScene()
	:Scene(_T("TestScene"))
	, spaceship(nullptr)
{
}
TestScene::~TestScene()
{
}

bool TestScene::initialize()
{
	ApplicationSettings* app_settings = Singleton<WorldSettings>::getInstance().getApplicationSettings();
	GameSettings* game_settings = Singleton<WorldSettings>::getInstance().getGameSettings();

	float window_width = (float)app_settings->getWindowWidth();
	float window_height = (float)app_settings->getWindowHeight();

	game_settings->setBackgroundColor(Color(0.16f, 0.15f, 0.18f));

	//ADD SPACESHIP
	this->spaceship = new Spaceship(_T("Player"));
	this->spaceship->getTransform()->rotate(PI / 2);
	this->spaceship->getTransform()->setPosition(window_width / 2, window_height / 2);
	addGameObject(this->spaceship);
	
	//ADD BORDER
	addBorder(Vector2D(0, window_height / 2), BORDER_WIDTH, window_height);
	addBorder(Vector2D(window_width, window_height / 2), BORDER_WIDTH, window_height);
	//addBorder(Vector2D(window_width / 2, 0), window_width - BORDER_WIDTH, BORDER_HEIGHT);
	addBorder(Vector2D(window_width / 2, window_height), window_width - BORDER_WIDTH, BORDER_HEIGHT);

	//ADD CAMERA
	addGameObject(new FollowCamera(this->spaceship, _T("Main Camera")));
	//addGameObject(new FreeCamera(_T("Main Camera")));

	spawnAstroids(10);

	//ADD SPAWNTIMER
	Timer* astroid_spawn_timer = new Timer(ASTROID_SPAWN_TIMER_NAME);
	astroid_spawn_timer->initialize();

	MainTimer* main_timer = dynamic_cast<MainTimer*>(Singleton<SystemManager>::getInstance().getSystem(SystemType::TIMER_SYSTEM));
	main_timer->addTimer(astroid_spawn_timer);

	return Scene::initialize();
}
bool TestScene::postInitialize()
{
	return Scene::postInitialize();
}
void TestScene::update()
{
	MainTimer* main_timer = dynamic_cast<MainTimer*>(Singleton<SystemManager>::getInstance().getSystem(SystemType::TIMER_SYSTEM));
	Timer* astroid_spawn_timer = main_timer->getTimer(ASTROID_SPAWN_TIMER_NAME);

	if (astroid_spawn_timer != nullptr)
	{
		if (astroid_spawn_timer->getTotalTime() > ASTROID_SPAWN_TIMER_THRESHOLD)
		{
			astroid_spawn_timer->reset();
			//spawnAstroids(10);
		}
	}

	Scene::update();
}
bool TestScene::shutdown()
{
	return Scene::shutdown();
}

void TestScene::setupInput(Input* input)
{
	input->bindInput(InputBinding(VK_F1, std::bind(&Scene::enableDebugRendering, this), InputStateType::PRESSED));
	input->bindInput(InputBinding(VK_F2, std::bind(&Scene::disableDebugRendering, this), InputStateType::PRESSED));
}

void TestScene::addBorder(const Vector2D& position, float colliderWidth, float colliderHeight)
{
	PhysicsObject* obstacle = new PhysicsObject(BodyType::STATIC);

	obstacle->getTransform()->setPosition(position);

	obstacle->addComponent(new ShapeComponent(new RectShape(0, 0, colliderWidth, colliderHeight)));
	obstacle->addComponent(new BoxCollisionComponent(obstacle->getRigidBody(), colliderWidth, colliderHeight));

	addGameObject(obstacle);
}

void TestScene::addAstroid(const Vector2D& position, float radius, const Vector2D& direction)
{
	Astroid* a = new Astroid(radius);
	a->getTransform()->setPosition(position);
	a->setDirection(direction);
	addGameObject(a);
}

void TestScene::spawnAstroids(int astroidAmount)
{
	//SPAWN ASTROIDS
	Singleton<Logger>::getInstance().log(_T("Spawn astroids"), LOGTYPE_INFO);

	ApplicationSettings* app_settings = Singleton<WorldSettings>::getInstance().getApplicationSettings();

	float window_width = (float)app_settings->getWindowWidth();
	float window_height = (float)app_settings->getWindowHeight();

	for (int i = 0; i < astroidAmount; ++i)
	{
		int radius = rand() % 80 + 40;

		int x_radius = ((int)window_width - (radius * 2));
		int y_radius = ((int)window_height - (radius * 2));

		int x = (rand() % x_radius) + (radius * 2);
		int y = (rand() % y_radius) + ((radius * 2) - (int)window_height); //Spawn above the screen

		addAstroid(Vector2D((float)x, (float)y), (float)radius, Vector2D(0.0f, 1.0f));
	}
}