#include "Core/Data/Objects/MyGame.h"

#include "SceneGraph\Factory\SceneFactory.h"
#include "SceneGraph\Manager\SceneManager.h"

namespace
{
	const std::tstring MYSCENE_NAME = _T("MyScene");
	const std::tstring TESTSCENE_NAME = _T("TestScene");
	const std::tstring MAINMENUSCENE_NAME = _T("MainMenu");
}

MyGame::MyGame()
{
}
MyGame::~MyGame()
{
}

bool MyGame::initialize()
{
	//Create scene factory
	SceneFactory factory;

	//Add all the scenes you need
	SceneManager::getInstance().addScene(factory.createScene(MYSCENE_NAME));
	SceneManager::getInstance().addScene(factory.createScene(TESTSCENE_NAME));
	SceneManager::getInstance().addScene(factory.createScene(MAINMENUSCENE_NAME));

	//Active your main scene
	SceneManager::getInstance().setActiveScene(TESTSCENE_NAME);

	return true;
}
bool MyGame::shutdown()
{
	return true;
}