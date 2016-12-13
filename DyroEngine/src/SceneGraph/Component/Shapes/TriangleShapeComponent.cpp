#include "SceneGraph\Component\Shapes\TriangleShapeComponent.h"
#include "Core\Data\Shapes\TriangleShape.h"

TriangleShapeComponent::TriangleShapeComponent(TriangleShape* shape, const std::tstring& name)
	:PolygonShapeComponent(shape,name)
{
	OBJECT_INIT(_T("TriangleShapeComponent"));
}
TriangleShapeComponent::~TriangleShapeComponent()
{}

TriangleShape* TriangleShapeComponent::getTriangleShape() const
{
	return dynamic_cast<TriangleShape*>(getShape());
}