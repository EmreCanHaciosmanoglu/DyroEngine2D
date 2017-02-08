#include "SceneGraph\Objects\GameObjects\Camera\Camera.h"

#include "SceneGraph\Objects\Components\TransformComponent.h"
#include "SceneGraph\Objects\Components\CameraComponent.h"

#include "SceneGraph/Manager/CameraManager.h"

#include "SceneGraph\Objects\Scenes\Scene.h"

Camera::Camera(const std::tstring& name, bool setActive)
	:GameObject(name)
	, camera(new CameraComponent())
	, transform(new TransformComponent())
{
	OBJECT_INIT(_T("Camera"));

	getScene()->getManager<CameraManager>()->addCamera(this, setActive);

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