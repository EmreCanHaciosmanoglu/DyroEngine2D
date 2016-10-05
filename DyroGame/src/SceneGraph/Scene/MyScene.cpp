#include "SceneGraph/Scene/MyScene.h"

#include "SceneGraph/Object/GameObjects/SceneObject.h"
#include "SceneGraph/Object/Objects/Shapes/RectShape.h"
#include "SceneGraph/Object/Objects/Shapes/CircleShape.h"
#include "SceneGraph/Component/ShapeComponent.h"

#include "Core\System\Input.h"

#include <functional>

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
	this->rectangle = new SceneObject();
	RectShape* rect_shape = new RectShape(10, 10, 100, 100);
	rect_shape->setColor(Color(1, 0, 0));
	this->rectangle->addComponent(new ShapeComponent(rect_shape)); // Ownership of the " RectShape " is transferred to the " ShapeComponent ".
	addGameObject(this->rectangle);
	this->circle = new SceneObject();
	CircleShape* circle_shape = new CircleShape(500, 500, 100);
	circle_shape->setColor(Color(0, 0, 1));
	this->circle->addComponent(new ShapeComponent(circle_shape)); // Ownership of the " CircleShape " is transferred to the " ShapeComponent ".
	addGameObject(this->circle);

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

void MyScene::setupInput(Input* input)
{
	input->bindInput(InputBinding(VK_NEXT, std::bind(&MyScene::changeColorRectangle, this), InputStateType::PRESSED));
	input->bindInput(InputBinding(VK_PRIOR, std::bind(&MyScene::changeColorCircle, this), InputStateType::PRESSED));
}

void MyScene::changeColorRectangle()
{
	this->rectangle->getComponent<ShapeComponent>()->setColor(Color((rand() % 255) / 255.0f, (rand() % 255) / 255.0f, (rand() % 255) / 255.0f));
}
void MyScene::changeColorCircle()
{
	this->circle->getComponent<ShapeComponent>()->setColor(Color((rand() % 255) / 255.0f, (rand() % 255) / 255.0f, (rand() % 255) / 255.0f));
}