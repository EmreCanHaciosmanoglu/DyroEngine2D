#include "SceneGraph\Objects\GameObjects\Camera\FixedCamera.h"
#include "SceneGraph\Objects\Components\TransformComponent.h"

FixedCamera::FixedCamera(const Vector2D& position, bool isActive, const std::tstring& name)
	:Camera(name, isActive)
{
	getTransform()->setStartPosition(position);
}
FixedCamera::~FixedCamera()
{}