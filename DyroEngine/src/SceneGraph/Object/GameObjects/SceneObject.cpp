#include "SceneGraph/Object/GameObjects/SceneObject.h"

#include "SceneGraph/Component/Component.h"
#include "SceneGraph\Component\TransformComponent.h"
#include "SceneGraph\Component\CameraComponent.h"

#include "SceneGraph\Scene\Scene.h"
#include "Core\Rendering\Renderer.h"

#include "SceneGraph/Object/GameObjects/Camera/Camera.h"
#include "SceneGraph/Object/GameObjects/Camera/Manager/CameraManager.h"

SceneObject::SceneObject(const std::tstring& name)
	:GameObject(name)
	,transform(new TransformComponent())
{
}
SceneObject::~SceneObject()
{
}

bool SceneObject::initialize()
{
	addComponent(this->transform);

	return GameObject::initialize();
}
void SceneObject::update()
{
	return GameObject::update();
}
void SceneObject::draw()
{
	Matrix2D world_matrix = getTransform()->getWorldMatrix();
	Matrix2D view_matrix = getScene()->getCameraManager()->getActiveCamera()->getCamera()->getViewMatrix();

	getScene()->getRenderer()->setTransformMatrix(world_matrix * view_matrix);

	for (Component* obj : getComponents())
	{
		IDrawable* drawable_obj = dynamic_cast<IDrawable*>(obj);
		if (drawable_obj == nullptr)
			continue;

		if (drawable_obj->getCanDraw())
			drawable_obj->draw();
	}
	for (GameObject* obj : getChilderen())
	{
		IDrawable* drawable_obj = dynamic_cast<IDrawable*>(obj);
		if (drawable_obj == nullptr)
			continue;

		if (drawable_obj->getCanDraw())
			drawable_obj->draw();
	}

	getScene()->getRenderer()->setTransformMatrix(Matrix2D::createIdentityMatrix());
}
bool SceneObject::shutdown()
{
	return GameObject::shutdown();
}

TransformComponent* SceneObject::getTransform() const
{
	return this->transform;
}