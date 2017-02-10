#include "SceneGraph\Objects\GameObjects\Camera\Camera.h"

#include "SceneGraph\Objects\Components\TransformComponent.h"
#include "SceneGraph\Objects\Components\CameraComponent.h"

#include "SceneGraph/Manager/CameraManager.h"

#include "SceneGraph\Objects\Scenes\Scene.h"

Camera::Camera(const std::tstring& name, bool setActive)
	:GameObject(name)
	, camera(new CameraComponent())
	, transform(new TransformComponent())
	, start_active(setActive)
{
	OBJECT_INIT(_T("Camera"));

	addComponent(this->transform);
	addComponent(this->camera);
}
Camera::~Camera()
{
}

bool Camera::initialize()
{
	getScene()->getManager<CameraManager>()->addCamera(this, this->start_active);

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