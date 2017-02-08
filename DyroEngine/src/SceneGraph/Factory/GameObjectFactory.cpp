#include "SceneGraph\Factory\GameObjectFactory.h"

GameObjectFactory::GameObjectFactory()
	:scene(nullptr)
{}
GameObjectFactory::~GameObjectFactory()
{}

void GameObjectFactory::setScene(Scene* scene)
{
	this->scene = scene;
}