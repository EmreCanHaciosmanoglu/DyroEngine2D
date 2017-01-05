#include "Core/Data/Objects/MyGame.h"

#include "Core/Helpers/Patterns/Singleton.h"

#include "SceneGraph/Objects/Scenes/MyScene.h"
#include "SceneGraph/Manager/SceneManager.h"

MyGame::MyGame()
{
}
MyGame::~MyGame()
{
}

bool MyGame::initialize()
{
	//Add all the scenes you need
	Singleton<SceneManager>::getInstance().addScene(new MyScene());

	//Active your main scene
	Singleton<SceneManager>::getInstance().setActiveScene(_T("MyScene"));

	return true;
}
bool MyGame::shutdown()
{
	return true;
}