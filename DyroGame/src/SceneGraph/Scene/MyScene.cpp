#include "SceneGraph/Scene/MyScene.h"

MyScene::MyScene()
	:Scene(_T("MyScene"))
{
}
MyScene::~MyScene()
{
}

bool MyScene::initialize()
{
	return Scene::initialize();
}
void MyScene::update()
{
	Scene::update();
}
bool MyScene::shutdown()
{
	return Scene::shutdown();
}