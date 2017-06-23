#include "SceneGraph/Objects/Scenes/MainMenu.h"
#include "SceneGraph/Objects/Components/TransformComponent.h"
#include "SceneGraph/Objects/GameObjects/UI/Button.h"
#include "SceneGraph/Objects/GameObjects/Camera/FixedCamera.h"
#include "SceneGraph/Factory/GameObjectFactory.h"
#include "SceneGraph/Manager/SceneManager.h"

#include "Core/System/Objects/Input.h"
#include "Core/Types/SettingsType.h"
#include "Core/Data/Manager/SettingsManager.h"
#include "Core/Data/Manager/FontManager.h"
#include "Core/Data/Objects/Settings/ApplicationSettings.h"
#include "Core/Data/Objects/Descriptions/UI/ButtonDescription.h"
#include "Core/Data/Objects/Font.h"
#include "Core/Defines/debug.h"

MainMenu::MainMenu()
	:Scene(_T("MainMenu"))
{
	OBJECT_INIT(_T("MainMenu"));
}
MainMenu::~MainMenu()
{
}

bool MainMenu::initialize()
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

	FixedCamera* camera = new FixedCamera(Vector2D(0, 0));
	addGameObject(camera);

	ButtonDescription* start_button_desc = new ButtonDescription();
	start_button_desc->setText(_T("Start"));
	Button* start_button = new Button(start_button_desc);
	start_button->getTransform()->setStartPosition(Vector2D(window_width / 2.0f, (window_height / 2.0f) - 25));
	start_button->onClicked(std::bind(&MainMenu::startGame, this));
	addGameObject(start_button);
	
	ButtonDescription* exit_button_desc = new ButtonDescription();
	exit_button_desc->setText(_T("Exit"));
	Button* exit_button = new Button(exit_button_desc);
	exit_button->getTransform()->setStartPosition(Vector2D(window_width / 2.0f, (window_height / 2.0f) + 25));
	exit_button->onClicked(std::bind(&MainMenu::exitGame, this));
	addGameObject(exit_button);

	return Scene::initialize();
}
void MainMenu::update()
{
	Scene::update();
}
bool MainMenu::shutdown()
{
	return Scene::shutdown();
}

void MainMenu::setupInput(Input* input)
{
}

void MainMenu::startGame()
{
	LogManager::getInstance().log(new InfoLog(_T("start game"), LOG_DATA));
	SceneManager::getInstance().setActiveScene(_T("TestScene"));

	SceneManager::getInstance().shutdownPreviousScene();
	SceneManager::getInstance().initializeActiveScene();
}
void MainMenu::exitGame()
{
	LogManager::getInstance().log(new InfoLog(_T("exit game"), LOG_DATA));

}