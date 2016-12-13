#include "SceneGraph\GameObjects\Camera\Camera.h"

#include "SceneGraph\Component\TransformComponent.h"
#include "SceneGraph\Component\CameraComponent.h"

#include "Helpers/Singleton.h"
#include "SceneGraph/GameObjects/Camera/Manager/CameraManager.h"

Camera::Camera(const std::tstring& name, bool setActive)
	:GameObject(name)
	,camera(new CameraComponent())
	,transform(new TransformComponent())
{
	OBJECT_INIT(_T("Camera"));

	Singleton<CameraManager>::getInstance().addCamera(this, setActive);

	addComponent(this->transform);
	addComponent(this->camera);
}
Camera::~Camera()
{
}

bool Camera::initialize()
{
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
