#include "SceneGraph\Objects\Components\Shapes\TriangleShapeComponent.h"
#include "Core\Data\Objects\Descriptions\Shapes\TriangleShapeDescription.h"

TriangleShapeComponent::TriangleShapeComponent(TriangleShapeDescription* shape, const std::tstring& name)
	:PolygonShapeComponent(shape, name)
{
	OBJECT_INIT(_T("TriangleShapeComponent"));
}
TriangleShapeComponent::~TriangleShapeComponent()
{}

void TriangleShapeComponent::setXScale(float scale)
{
	getTriangleDescription()->setXScale(scale);
}
void TriangleShapeComponent::setYScale(float scale)
{
	getTriangleDescription()->setYScale(scale);
}

float TriangleShapeComponent::getXScale() const
{
	return getTriangleDescription()->getXScale();
}
float TriangleShapeComponent::getYScale() const
{
	return getTriangleDescription()->getYScale();
}

TriangleShapeDescription* TriangleShapeComponent::getTriangleDescription() const
{
	return dynamic_cast<TriangleShapeDescription*>(getDescription());
}