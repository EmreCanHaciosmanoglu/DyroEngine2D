#include "SceneGraph/Objects/GameObjects/SceneObject.h"

#include "SceneGraph/Objects/Components/Component.h"
#include "SceneGraph\Objects\Components\TransformComponent.h"
#include "SceneGraph\Objects\Components\CameraComponent.h"

#include "SceneGraph\Objects\Scenes\Scene.h"
#include "Rendering\Renderer.h"

#include "SceneGraph/Objects/GameObjects/Camera/Camera.h"
#include "SceneGraph/Manager/CameraManager.h"

SceneObject::SceneObject(const std::tstring& name)
	:GameObject(name)
	, transform(new TransformComponent())
{
	OBJECT_INIT(_T("SceneObject"));

	addComponent(this->transform);
}
SceneObject::~SceneObject()
{
}

bool SceneObject::initialize()
{
	return GameObject::initialize();
}
void SceneObject::update()
{
	return GameObject::update();
}
bool SceneObject::shutdown()
{
	return GameObject::shutdown();
}

TransformComponent* SceneObject::getTransform() const
{
	return this->transform;
}