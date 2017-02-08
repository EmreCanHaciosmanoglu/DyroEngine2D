#include "SceneGraph/Objects/GameObjects/Camera/FollowCamera.h"
#include "SceneGraph/Objects/GameObjects/SceneObject.h"

#include "SceneGraph/Objects/Components/TransformComponent.h"

#include "Core/Defines/assert.h"

FollowCamera::FollowCamera(SceneObject* target, const std::tstring& name, float damping)
	:Camera(name)
	, damping(damping)
	, target(target)
{
	OBJECT_INIT(_T("FollowCamera"));
}
FollowCamera::~FollowCamera()
{}

bool FollowCamera::initialize()
{
	//Target cannot be null
	assert(this->target != nullptr);

	return Camera::initialize();
}
void FollowCamera::update()
{
	//TransformComponent* target_transform = this->target->getTransform();

	//Move the camera to the position of the target
	if (this->damping == 0.0f)
	{
		//this->getTransform()->setPosition(target_transform->getPosition());
	}
	else
	{
		//Apply damping
		//this->getTransform()->setPosition(target_transform->getPosition());
	}

	Camera::update();
}
bool FollowCamera::shutdown()
{
	return Camera::shutdown();
}

void FollowCamera::setTarget(SceneObject* target)
{
	this->target = target;
}
SceneObject* FollowCamera::getTarget() const
{
	return this->target;
}

void FollowCamera::setDamping(float damping)
{
	this->damping = damping;
}
float FollowCamera::getDamping() const
{
	return this->damping;
}