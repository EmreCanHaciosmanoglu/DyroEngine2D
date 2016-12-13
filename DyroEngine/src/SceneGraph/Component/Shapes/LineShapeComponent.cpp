#include "SceneGraph\Component\Shapes\LineShapeComponent.h"
#include "Core\Data\Shapes\LineShape.h"

LineShapeComponent::LineShapeComponent(LineShape* shape, const std::tstring& name)
	:ShapeComponent(shape, name)
{
	OBJECT_INIT(_T("LineShapeComponent"));
}
LineShapeComponent::~LineShapeComponent()
{}

LineShape* LineShapeComponent::getLineShape() const
{
	return dynamic_cast<LineShape*>(getShape());
}