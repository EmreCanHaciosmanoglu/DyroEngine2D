#include "SceneGraph/GameObjects/SceneObject.h"

#include "SceneGraph/Component/Component.h"
#include "SceneGraph\Component\TransformComponent.h"
#include "SceneGraph\Component\CameraComponent.h"

#include "SceneGraph\Scene\Scene.h"
#include "Core\Rendering\Renderer.h"

#include "SceneGraph/GameObjects/Camera/Camera.h"
#include "SceneGraph/GameObjects/Camera/Manager/CameraManager.h"

SceneObject::SceneObject(const std::tstring& name)
	:GameObject(name)
	,transform(new TransformComponent())
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

Rect2D SceneObject::getBoundingBox() const
{
	Rect2D bounding_rect;

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

	bounding_rect *= getTransform()->getScale();
	bounding_rect += getTransform()->getPosition();

	return bounding_rect;
}