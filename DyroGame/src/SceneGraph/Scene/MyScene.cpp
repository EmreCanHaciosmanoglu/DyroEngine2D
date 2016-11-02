#include "SceneGraph/Scene/MyScene.h"

#include "SceneGraph/Object/GameObjects/Camera/FreeCamera.h"

#include "SceneGraph/Object/GameObjects/SceneObject.h"
#include "SceneGraph/Object/Objects/Shapes/RectShape.h"
#include "SceneGraph/Object/Objects/Shapes/CircleShape.h"

#include "SceneGraph/Component/ShapeComponent.h"
#include "SceneGraph/Component/TransformComponent.h"
#include "SceneGraph/Component/ImageComponent.h"

#include "Core/System/Input.h"
#include "Core/System/MainTimer.h"

#include "Core/Resources/Manager/ResourceManager.h"
#include "Core/Resources/Image.h"

#include "Core/Settings/WorldSettings.h"
#include "Core/Settings/ApplicationSettings.h"

#include "Helpers/Singleton.h"

#include <functional>
#include <math.h>

namespace
{
	const int RECTANGLE_WIDTH = 256;
	const int RECTANGLE_HEIGHT = 256;

	const float RECTANGLE_ROTATION_SPEED = 2.0f;

	const float PI = 3.1415f;
}

MyScene::MyScene()
	:Scene(_T("MyScene"))
	, animated_angle(0.0f)
	,rectangle(nullptr)
	,camera(nullptr)
	,object(nullptr)
	,current_image(0)
{
	this->image_paths[0] = _T("resources/IMAGES/Android-Boss-royalty-free-game-art.png");
	this->image_paths[1] = _T("resources/IMAGES/Anime-Zombie-royalty-free-game-art.png");
	this->image_paths[2] = _T("resources/IMAGES/Armored-Samurai-royalty-free-game-art.png");
	this->image_paths[3] = _T("resources/IMAGES/Army-Zombie-royalty-free-game-art.png");
	this->image_paths[4] = _T("resources/IMAGES/Brain-Exposed-Zombie-royalty-free-game-art.png");
	this->image_paths[5] = _T("resources/IMAGES/CT-royalty-free-game-art.png");
	this->image_paths[6] = _T("resources/IMAGES/Dracula-royalty-free-game-art.png");
	this->image_paths[7] = _T("resources/IMAGES/Executioner-royalty-free-game-art.png");
	this->image_paths[8] = _T("resources/IMAGES/Farmer-Zombie-royalty-free-game-art.png");
	this->image_paths[9] = _T("resources/IMAGES/Goblin-royalty-free-game-art.png");
	this->image_paths[10] = _T("resources/IMAGES/Jack-Thug-royalty-free-game-art.png");
	this->image_paths[11] = _T("resources/IMAGES/Mage-royalty-free-game-art.png");
	this->image_paths[12] = _T("resources/IMAGES/Ralf-Thug-royalty-free-game-art.png");
	this->image_paths[13] = _T("resources/IMAGES/Robot-royalty-free-game-art.png");
	this->image_paths[14] = _T("resources/IMAGES/Roman-Knight-royalty-free-game-art.png");
}
MyScene::~MyScene()
{
}

bool MyScene::initialize()
{
	//PRELOAD IMAGES
	for (int i = 0; i < IMAGE_PATH_AMOUNT; ++i)
		getResourceManager()->getResource<Image>(this->image_paths[i]);

	this->camera = new FreeCamera(_T("Main Camera"),200.0f);
	this->camera->getTransform()->setPosition(Vector2D(0, 0));
	addGameObject(this->camera);

	float window_width = (float)Singleton<WorldSettings>::getInstance().getApplicationSettings().getWindowWidth();
	float window_height = (float)Singleton<WorldSettings>::getInstance().getApplicationSettings().getWindowHeight();

	//ADD RECTANGLE
	this->rectangle = new SceneObject(_T("Rectangle"));
	
	RectShape* rect_shape = new RectShape(0, 0, RECTANGLE_WIDTH, RECTANGLE_HEIGHT);
	rect_shape->setColor(Color(1, 0, 0));
	this->rectangle->addComponent(new ShapeComponent(rect_shape)); // Ownership of the " RectShape " is transferred to the " ShapeComponent ".
	
	this->rectangle->getTransform()->setPosition(Vector2D((window_width / 2), (window_height / 2)));
	this->rectangle->getTransform()->center(Vector2D(-RECTANGLE_WIDTH/2,-RECTANGLE_HEIGHT/2));
	
	addGameObject(this->rectangle);

	//ADD CIRCLE
	for (int i = 0; i < CIRCLE_AMOUNT; ++i)
	{
		this->circles[i] = new SceneObject(_T("Circle"));

		CircleShape* circle_shape = new CircleShape(Vector2D(0, 0), 5);
		circle_shape->setColor(Color(((rand() % 100) / 100.0f), ((rand() % 100) / 100.0f), ((rand() % 100) / 100.0f)));
		this->circles[i]->addComponent(new ShapeComponent(circle_shape)); // Ownership of the " CircleShape " is transferred to the " ShapeComponent ".

		addGameObject(this->circles[i]);
	}

	//ADD IMAGE
	this->object = new SceneObject(_T("Object"));

	ImageComponent* image_component = new ImageComponent(getResourceManager()->getResource<Image>(this->image_paths[this->current_image]));
	image_component->setTransparencyColor(Color(1.0f, 0, 1.0f));
	this->object->addComponent(image_component);
	
	this->object->getTransform()->setPosition(Vector2D(window_width / 2, window_height / 2));
	this->object->getTransform()->setScale(Vector2D(0.5f, 0.5f));
	
	addGameObject(object);

	return Scene::initialize();
}
void MyScene::update()
{
	float window_width = (float)Singleton<WorldSettings>::getInstance().getApplicationSettings().getWindowWidth();
	float window_height = (float)Singleton<WorldSettings>::getInstance().getApplicationSettings().getWindowHeight();

	this->rectangle->getTransform()->setRotation(this->animated_angle * RECTANGLE_ROTATION_SPEED);

	float step = (PI * 2.0f) / CIRCLE_AMOUNT;
	for (int i = 0; i < CIRCLE_AMOUNT; ++i)
	{
		Matrix2D mat_rotate = Matrix2D::createRotationMatrix(-this->animated_angle + (step * i));
		Vector2D rotated_vector = mat_rotate.transformVector(Vector2D(300, 0));

		this->circles[i]->getTransform()->setPosition(rotated_vector + Vector2D(window_width / 2, window_height / 2));
	}

	this->animated_angle = this->animated_angle > (PI * 2.0f) ? this->animated_angle - (PI * 2.0f) : this->animated_angle + MainTimer::delta_time;

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

	input->bindInput(InputBinding('X', std::bind(&MyScene::mirrorXImage, this), InputStateType::PRESSED));
	input->bindInput(InputBinding('Y', std::bind(&MyScene::mirrorYImage, this), InputStateType::PRESSED));
	input->bindInput(InputBinding('C', std::bind(&MyScene::centerImage, this), InputStateType::PRESSED));
	input->bindInput(InputBinding('R', std::bind(&MyScene::resetImage, this), InputStateType::PRESSED));

	input->bindInput(InputBinding(VK_F1, std::bind(&MyScene::nextImage, this), InputStateType::PRESSED));
	input->bindInput(InputBinding(VK_F2, std::bind(&MyScene::previousImage, this), InputStateType::PRESSED));
	input->bindInput(InputBinding(VK_F3, std::bind(&MyScene::randomImage, this), InputStateType::PRESSED));
}

void MyScene::changeColorRectangle()
{
	this->rectangle->getComponent<ShapeComponent>()->setColor(Color((rand() % 255) / 255.0f, (rand() % 255) / 255.0f, (rand() % 255) / 255.0f));
}
void MyScene::changeColorCircle()
{
	for (int i = 0; i < CIRCLE_AMOUNT; ++i)
		this->circles[i]->getComponent<ShapeComponent>()->setColor(Color((rand() % 255) / 255.0f, (rand() % 255) / 255.0f, (rand() % 255) / 255.0f));
}

void MyScene::mirrorXImage() 
{
	ImageComponent* component = this->object->getComponent<ImageComponent>();
	component->mirrorImageX();
}
void MyScene::mirrorYImage() 
{
	ImageComponent* component = this->object->getComponent<ImageComponent>();
	component->mirrorImageY();
}
void MyScene::centerImage() 
{
	ImageComponent* component = this->object->getComponent<ImageComponent>();
	component->centerImage();
}
void MyScene::resetImage()
{
	ImageComponent* component = this->object->getComponent<ImageComponent>();
	component->resetCenter();
	component->resetMirror();
}

void MyScene::nextImage()
{
	++current_image;
	if (current_image > IMAGE_PATH_AMOUNT - 1)
		current_image = 0;

	ImageComponent* component = this->object->getComponent<ImageComponent>();
	component->setImage(getResourceManager()->getResource<Image>(image_paths[current_image]));
}
void MyScene::previousImage()
{
	--current_image;
	if (current_image < 0)
		current_image = IMAGE_PATH_AMOUNT - 1;

	ImageComponent* component = this->object->getComponent<ImageComponent>();
	component->setImage(getResourceManager()->getResource<Image>(image_paths[current_image]));
}
void MyScene::randomImage()
{
	current_image = rand() % IMAGE_PATH_AMOUNT;
	ImageComponent* component = this->object->getComponent<ImageComponent>();
	component->setImage(getResourceManager()->getResource<Image>(image_paths[current_image]));
}