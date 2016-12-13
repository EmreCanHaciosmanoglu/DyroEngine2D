#include "SceneGraph\Component\Shapes\CircleShapeComponent.h"
#include "Core\Data\Shapes\CircleShape.h"

CircleShapeComponent::CircleShapeComponent(CircleShape* shape, const std::tstring& name)
	:ShapeComponent(shape, name)
{
	OBJECT_INIT(_T("CircleShapeComponent"));
}
CircleShapeComponent::~CircleShapeComponent()
{}

CircleShape* CircleShapeComponent::getCircleShape() const
{
	return dynamic_cast<CircleShape*>(getShape());
}

Rect2D CircleShapeComponent::getBoundingBox() const
{
	return getCircleShape()->getBoundingBox();
}