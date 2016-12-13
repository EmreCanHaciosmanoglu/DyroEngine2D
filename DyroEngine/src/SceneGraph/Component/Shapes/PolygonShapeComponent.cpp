#include "SceneGraph\Component\Shapes\PolygonShapeComponent.h"
#include "Core\Data\Shapes\PolygonShape.h"

PolygonShapeComponent::PolygonShapeComponent(PolygonShape* shape, const std::tstring& name)
	:ShapeComponent(shape, name)
{
	OBJECT_INIT(_T("PolygonShapeComponent"));
}
PolygonShapeComponent::~PolygonShapeComponent()
{}

PolygonShape* PolygonShapeComponent::getPolygonShape() const
{
	return dynamic_cast<PolygonShape*>(getShape());
}

Rect2D PolygonShapeComponent::getBoundingBox() const
{
	return getPolygonShape()->getBoundingBox();
}