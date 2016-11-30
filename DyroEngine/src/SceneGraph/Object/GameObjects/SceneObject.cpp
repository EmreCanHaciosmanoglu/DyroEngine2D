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
void SceneObject::draw()
{
	Matrix2D world_matrix = getTransform()->getWorldMatrix();
	Matrix2D view_matrix = getScene()->getManager<CameraManager>()->getActiveCamera()->getCamera()->getViewMatrix();

	Renderer* renderer = getScene()->getManager<Renderer>();

	renderer->setTransformMatrix(world_matrix * view_matrix);

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

	renderer->setTransformMatrix(Matrix2D::createIdentityMatrix());
}
bool SceneObject::shutdown()
{
	return GameObject::shutdown();
}

TransformComponent* SceneObject::getTransform() const
{
	return this->transform;
}

Rect2D SceneObject::getBoundingBox() const
{
	Rect2D bounding_rect;

	bounding_rect.left = 0;
	bounding_rect.top = 0;

	for (Component* c : getComponents())
	{
		IBoundingBox* bounding_box = dynamic_cast<IBoundingBox*>(c);
		if (bounding_box != nullptr)
		{
			if (bounding_rect.right < bounding_box->getBoundingBox().right)
				bounding_rect.right = bounding_box->getBoundingBox().right;
			if (bounding_rect.bottom < bounding_box->getBoundingBox().bottom)
				bounding_rect.bottom = bounding_box->getBoundingBox().bottom;
		}
	}

	return bounding_rect;
}