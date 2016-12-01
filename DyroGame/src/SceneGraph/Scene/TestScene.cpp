#include "SceneGraph\Scene\TestScene.h"

#include "SceneGraph\Object\GameObjects\Camera\FollowCamera.h"
#include "SceneGraph\Object\GameObjects\Spaceship.h"
#include "SceneGraph\Object\GameObjects\Obstacle.h"

#include "SceneGraph\Object\Objects\Shapes\RectShape.h"

#include "SceneGraph\Component\TransformComponent.h"
#include "SceneGraph\Component\ShapeComponent.h"

#include "SceneGraph\Component\Collision\BoxCollisionComponent.h"

#include "Core\System\Input.h"

#include "Helpers\Singleton.h"

#include "Core\Settings\WorldSettings.h"
#include "Core\Settings\ApplicationSettings.h"
#include "Core\Settings\GameSettings.h"

namespace
{
	const float BORDER_WIDTH = 50.0f;
	const float BORDER_HEIGHT = 50.0f;

	const float OBSTACLE_WIDTH = 100.0f;
	const float OBSTACLE_HEIGHT = 100.0f;
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
	this->spaceship->getTransform()->setPosition(window_width / 2, window_width / 2);
	addGameObject(this->spaceship);

	//ADD BORDER
	//addObstacle(Vector2D(0, window_height / 2), BORDER_WIDTH, window_height);
	//addObstacle(Vector2D(window_width , window_height / 2), BORDER_WIDTH, window_height);
	//addObstacle(Vector2D(window_width / 2, 0), window_width - BORDER_WIDTH, BORDER_HEIGHT);
	//addObstacle(Vector2D(window_width / 2, window_height), window_width - BORDER_WIDTH, BORDER_HEIGHT);

	//ADD OBSTACLE
	addObstacle(Vector2D(window_width / 2, window_height / 2), OBSTACLE_WIDTH, OBSTACLE_HEIGHT);

	//ADD CAMERA
	addGameObject(new FollowCamera(this->spaceship, _T("Main Camera")));

	return Scene::initialize();
}
void TestScene::update()
{
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

void TestScene::addObstacle(const Vector2D& position, float colliderWidth, float colliderHeight)
{
	Obstacle* obstacle = new Obstacle(BodyType::STATIC);

	obstacle->getTransform()->setPosition(position);

	obstacle->addComponent(new ShapeComponent(new RectShape(0, 0, colliderWidth, colliderHeight)));
	obstacle->addComponent(new BoxCollisionComponent(obstacle->getRigidBody(), colliderWidth, colliderHeight));

	addGameObject(obstacle);
}