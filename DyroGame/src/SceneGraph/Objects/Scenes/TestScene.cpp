#include "SceneGraph/Objects/Scenes/TestScene.h"
#include "SceneGraph/Objects/GameObjects/Camera/FreeCamera.h"
#include "SceneGraph/Objects/GameObjects/Spaceship.h"
#include "SceneGraph/Objects/GameObjects/UI/Button.h"
#include "SceneGraph/Objects/Components/TransformComponent.h"
#include "SceneGraph/Factory/GameObjectFactory.h"

#include "Core/System/Objects/Input.h"
#include "Core/Types/SettingsType.h"
#include "Core/Types/DebugRenderingType.h"
#include "Core/Data/Manager/SettingsManager.h"
#include "Core/Data/Manager/FontManager.h"
#include "Core/Data/Objects/Descriptions/UI/ButtonDescription.h"
#include "Core/Data/Objects/Settings/ApplicationSettings.h"
#include "Core/Data/Objects/Settings/GameSettings.h"
#include "Core/Data/Objects/Settings/PhysicsSettings.h"
#include "Core/Data/Objects/Font.h"

TestScene::TestScene()
	:Scene(_T("TestScene"))
{
	OBJECT_INIT(_T("TestScene"));
}
TestScene::~TestScene()
{
}

bool TestScene::initialize()
{
	ApplicationSettings* app_settings = SettingsManager::getInstance().getSettings<ApplicationSettings>();
	if (app_settings == nullptr)
		return false;

	float window_width = (float)app_settings->getWindowWidth();
	float window_height = (float)app_settings->getWindowHeight();

	Font* consolas = new Font(_T("Consolas"), _T("consolas"));
	Font* verdana = new Font(_T("Verdana"), _T("verdana"));

	FontManager::createInstance();
	FontManager::getInstance().addFont(consolas);
	FontManager::getInstance().addFont(verdana);

	FontManager::getInstance().initialize();
	
	FreeCamera* camera = GameObjectFactory::getInstance().createObject<FreeCamera>();
	camera->setSpeed(200.0f);

	SpaceShip* ship = GameObjectFactory::getInstance().createObject<SpaceShip>();
	ship->getTransform()->setStartPosition(window_width / 2, window_height / 2 - 100);

	return Scene::initialize();
}
void TestScene::update()
{
	Scene::update();
}
bool TestScene::shutdown()
{
	FontManager::destroyInstance();

	return Scene::shutdown();
}

void TestScene::setupInput(Input* input)
{
	input->bindKey(KeyBinding(VK_F1, std::bind(&TestScene::noDebugRendering, this), InputStateType::PRESSED));
	input->bindKey(KeyBinding(VK_F2, std::bind(&TestScene::debugOnlyRendering, this), InputStateType::PRESSED));
	input->bindKey(KeyBinding(VK_F3, std::bind(&TestScene::overlayDebugRendering, this), InputStateType::PRESSED));
}
void TestScene::setupSettings(const SettingsData& settings)
{
	settings.physics_settings->setGravity(Vector2D());

	Scene::setupSettings(settings);
}

void TestScene::noDebugRendering()
{
	setDebugRenderingType(DebugRenderingType::NO_DEBUG);
}
void TestScene::debugOnlyRendering()
{
	setDebugRenderingType(DebugRenderingType::ONLY_DEBUG);
}
void TestScene::overlayDebugRendering()
{
	setDebugRenderingType(DebugRenderingType::OVERLAY_DEBUG);
}