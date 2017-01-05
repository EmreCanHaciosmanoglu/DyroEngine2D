#include "SceneGraph\Objects\Components\Shapes\RectShapeComponent.h"
#include "Core\Data\Objects\Descriptions\Shapes\RectShapeDescription.h"

RectShapeComponent::RectShapeComponent(RectShapeDescription* description, const std::tstring& name)
	:ShapeComponent(description, name)
{
	OBJECT_INIT(_T("RectShapeComponent"));
}
RectShapeComponent::~RectShapeComponent()
{}

void RectShapeComponent::setRect(const Rect2D& rect)
{
	getRectDescription()->setRect(rect);
}

const Rect2D& RectShapeComponent::getRect()
{
	return getRectDescription()->getRect();
}

RectShapeDescription* RectShapeComponent::getRectDescription() const
{
	return dynamic_cast<RectShapeDescription*>(getDescription());
}