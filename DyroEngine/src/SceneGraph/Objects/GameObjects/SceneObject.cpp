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
Rect2D SceneObject::getBoundingBox() const
{
	Rect2D bounding_rect;

	std::vector<Component*> components;
	getComponents(components);

	for (Component* c : components)
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