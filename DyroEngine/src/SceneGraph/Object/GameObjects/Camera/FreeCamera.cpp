#include "SceneGraph\Object\GameObjects\Camera\FreeCamera.h"

#include "SceneGraph\Component\TransformComponent.h"
#include "SceneGraph\Component\CameraComponent.h"

#include "Helpers\Singleton.h"
#include "Core\System\Manager\SystemManager.h"
#include "Core\System\Input.h"
#include "Core\System\MainTimer.h"

FreeCamera::FreeCamera(const std::tstring& name, float speed)
	:Camera(name)
	,speed(speed)
{
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

	input->bindInput(InputBinding('W', std::bind(&FreeCamera::moveUp, this), InputStateType::DOWN));
	input->bindInput(InputBinding('S', std::bind(&FreeCamera::moveDown, this), InputStateType::DOWN));
	input->bindInput(InputBinding('A', std::bind(&FreeCamera::moveLeft, this), InputStateType::DOWN));
	input->bindInput(InputBinding('D', std::bind(&FreeCamera::moveRight, this), InputStateType::DOWN));
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
	transform->translate(Vector2D(0, -1) * speed * MainTimer::delta_time);
}
void FreeCamera::moveDown()
{
	TransformComponent* transform = getTransform();
	transform->translate(Vector2D(0, 1) * speed * MainTimer::delta_time);
}
void FreeCamera::moveLeft()
{
	TransformComponent* transform = getTransform();
	transform->translate(Vector2D(-1, 0) * speed * MainTimer::delta_time);
}
void FreeCamera::moveRight()
{
	TransformComponent* transform = getTransform();
	transform->translate(Vector2D(1, 0) * speed * MainTimer::delta_time);
}