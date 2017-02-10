#include "SceneGraph\Objects\GameObjects\Camera\FreeCamera.h"

#include "SceneGraph\Objects\Components\TransformComponent.h"
#include "SceneGraph\Objects\Components\CameraComponent.h"

#include "Core\System\Manager\SystemManager.h"
#include "Core\System\Objects\Input.h"

#include "Core\Data\Objects\Timers\WorldTimer.h"

FreeCamera::FreeCamera(const std::tstring& name)
	:Camera(name)
	, speed(50.0f)
{
	OBJECT_INIT(_T("FreeCamera"));
}
FreeCamera::~FreeCamera()
{
}

bool FreeCamera::initialize()
{
	return Camera::initialize();
}
void FreeCamera::update()
{
	Camera::update();
}
bool FreeCamera::shutdown()
{
	return Camera::shutdown();
}

void FreeCamera::setupInput(Input* input)
{
	input->bindInput(InputBinding(VK_UP, std::bind(&FreeCamera::moveUp, this), InputStateType::DOWN));
	input->bindInput(InputBinding(VK_DOWN, std::bind(&FreeCamera::moveDown, this), InputStateType::DOWN));
	input->bindInput(InputBinding(VK_LEFT, std::bind(&FreeCamera::moveLeft, this), InputStateType::DOWN));
	input->bindInput(InputBinding(VK_RIGHT, std::bind(&FreeCamera::moveRight, this), InputStateType::DOWN));
}

void FreeCamera::setSpeed(float speed)
{
	this->speed = speed;
}
float FreeCamera::getSpeed() const
{
	return this->speed;
}

void FreeCamera::moveUp()
{
	TransformComponent* transform = getTransform();
	transform->translate(Vector2D(0, -1) * speed * (float)WorldTimer::getWorldDeltaTime());
}
void FreeCamera::moveDown()
{
	TransformComponent* transform = getTransform();
	transform->translate(Vector2D(0, 1) * speed * (float)WorldTimer::getWorldDeltaTime());
}
void FreeCamera::moveLeft()
{
	TransformComponent* transform = getTransform();
	transform->translate(Vector2D(-1, 0) * speed * (float)WorldTimer::getWorldDeltaTime());
}
void FreeCamera::moveRight()
{
	TransformComponent* transform = getTransform();
	transform->translate(Vector2D(1, 0) * speed * (float)WorldTimer::getWorldDeltaTime());
}