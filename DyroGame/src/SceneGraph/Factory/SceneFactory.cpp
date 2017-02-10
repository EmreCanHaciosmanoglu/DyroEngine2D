#include "SceneGraph\Factory\SceneFactory.h"

// Scenes
#include "SceneGraph\Objects\Scenes\MyScene.h"

SceneFactory::SceneFactory()
{}
SceneFactory::~SceneFactory()
{}

Scene* SceneFactory::createScene(const std::tstring& sceneTypeID) const
{
	if (sceneTypeID == MyScene::getClassTypeId())
		return new MyScene();

	return nullptr;
}