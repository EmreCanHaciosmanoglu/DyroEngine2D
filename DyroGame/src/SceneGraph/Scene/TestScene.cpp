#include "SceneGraph\Scene\TestScene.h"

#include "SceneGraph\Object\GameObjects\Camera\FollowCamera.h"
#include "SceneGraph\Object\GameObjects\Spaceship.h"

#include "SceneGraph/Component/TransformComponent.h"

#include "Core\System\Input.h"

#include "Helpers\Singleton.h"

#include "Core\Settings\WorldSettings.h"
#include "Core\Settings\ApplicationSettings.h"
#include "Core\Settings\GameSettings.h"

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

void TestScene::addBorder(const Vector2D& position, const Vector2D& scale, float rotation)
{
	SceneObject* border = new SceneObject(_T("BORDER"));

	
}