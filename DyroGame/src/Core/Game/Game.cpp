#include "Core/Game/Game.h"

#include "Helpers/Singleton.h"

#include "SceneGraph/Scene/MyScene.h"
#include "SceneGraph/Scene/Manager/SceneManager.h"

Game::Game()
{
}
Game::~Game()
{
}

bool Game::initialize()
{
	//Add all the scenes you need
	Singleton<SceneManager>::getInstance().addScene(new MyScene());

	//Active your main scene
	Singleton<SceneManager>::getInstance().setActiveScene(_T("MyScene"));

	return true;
}
bool Game::shutdown()
{
	return true;
}
