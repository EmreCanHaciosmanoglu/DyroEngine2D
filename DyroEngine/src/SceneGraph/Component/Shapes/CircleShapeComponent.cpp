#include "SceneGraph\Component\Shapes\CircleShapeComponent.h"

#include "Core\Data\Objects\Descriptions\Shapes\CircleShapeDescription.h"

CircleShapeComponent::CircleShapeComponent(CircleShapeDescription* description, const std::tstring& name)
	:ShapeComponent(description, name)
{
	OBJECT_INIT(_T("CircleShapeComponent"));
}
CircleShapeComponent::~CircleShapeComponent()
{}

void CircleShapeComponent::setCenterPosition(const Vector2D& center)
{
	getCircleDescription()->setCenter(center);
}
void CircleShapeComponent::setRadius(float radius)
{
	getCircleDescription()->setRadius(radius);
}

const Vector2D& CircleShapeComponent::getCenterPosition() const
{
	return getCircleDescription()->getCenter();
}
float CircleShapeComponent::getRadius() const
{
	return getCircleDescription()->getRadius();
}

CircleShapeDescription* CircleShapeComponent::getCircleDescription() const
{
	return dynamic_cast<CircleShapeDescription*>(getDescription());
}