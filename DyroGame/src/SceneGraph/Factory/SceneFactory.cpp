#include "SceneGraph\Factory\SceneFactory.h"

// Scenes
#include "SceneGraph\Objects\Scenes\MyScene.h"
#include "SceneGraph\Objects\Scenes\TestScene.h"
#include "SceneGraph\Objects\Scenes\MainMenu.h"

SceneFactory::SceneFactory()
{}
SceneFactory::~SceneFactory()
{}

Scene* SceneFactory::createScene(const std::tstring& sceneTypeID) const
{
	if (sceneTypeID == MyScene::getClassTypeId())
		return new MyScene();
	else if (sceneTypeID == TestScene::getClassTypeId())
		return new TestScene();
	else if (sceneTypeID == MainMenu::getClassTypeId())
		return new MainMenu();

	return nullptr;
}