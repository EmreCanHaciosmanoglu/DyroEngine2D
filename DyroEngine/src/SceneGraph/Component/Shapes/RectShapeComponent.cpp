#include "SceneGraph\Component\Shapes\RectShapeComponent.h"
#include "Core\Data\Shapes\RectShape.h"

RectShapeComponent::RectShapeComponent(RectShape* shape, const std::tstring& name)
	:ShapeComponent(shape,name)
{
	OBJECT_INIT(_T("RectShapeVisualization"));
}
RectShapeComponent::~RectShapeComponent()
{}

RectShape* RectShapeComponent::getRectShape() const
{
	return dynamic_cast<RectShape*>(getShape());
}

Rect2D RectShapeComponent::getBoundingBox() const
{
	return getRectShape()->getBoundingBox();
}