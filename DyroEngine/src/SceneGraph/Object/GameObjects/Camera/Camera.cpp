#include "SceneGraph\Object\GameObjects\Camera\Camera.h"

#include "SceneGraph\Component\TransformComponent.h"
#include "SceneGraph\Component\CameraComponent.h"

#include "Helpers/Singleton.h"
#include "SceneGraph/Object/GameObjects/Camera/Manager/CameraManager.h"

Camera::Camera(const std::tstring& name, bool setActive)
	:GameObject(name)
	,camera(new CameraComponent())
	,transform(new TransformComponent())
{
	Singleton<CameraManager>::getInstance().addCamera(this, setActive);
}
Camera::~Camera()
{
}

bool Camera::initialize()
{
	addComponent(this->transform);
	addComponent(this->camera);

	return GameObject::initialize();
}
void Camera::update()
{
	GameObject::update();
}
bool Camera::shutdown()
{
	return GameObject::shutdown();
}

CameraComponent* Camera::getCamera() const
{
	return this->camera;
}
TransformComponent* Camera::getTransform() const
{
	return this->transform;
}
