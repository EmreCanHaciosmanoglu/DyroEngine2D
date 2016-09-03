#include "SceneGraph/Scene/MyScene.h"

#include "SceneGraph/Object/GameObjects/GameObject.h"
#include "SceneGraph/Object/Objects/Shapes/RectShape.h"
#include "SceneGraph/Object/Objects/Shapes/CircleShape.h"
#include "SceneGraph/Component/ShapeComponent.h"

MyScene::MyScene()
	:Scene(_T("MyScene"))
	,rectangle(nullptr)
	,circle(nullptr)
{
}
MyScene::~MyScene()
{
}

bool MyScene::initialize()
{
	//This is how we will create our different game objects.

	//Unfortunately we did not implement a way to add them to the scene, we will do this in one of the following lessons
	//Currently these allocations will result in memory-leaks because the pointers are never freed, 
	//		once we have implemented the management of different game objects inside a scene, the scene will handle all the memory of those game objects.

	this->rectangle = new GameObject();
	this->rectangle->addComponent(new ShapeComponent(new RectShape(10, 10, 100, 100))); // Ownership of the " RectShape " is transferred to the " ShapeComponent ".
	//addGameObect(this->rectangle);
	this->circle = new GameObject();
	this->circle->addComponent(new ShapeComponent(new CircleShape(500, 500, 100))); // Ownership of the " CircleShape " is transferred to the " ShapeComponent ".
	//addGameObject(this->circle);

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