#include "SceneGraph\Component\Shapes\PolygonShapeComponent.h"
#include "Core\Data\Objects\Descriptions\Shapes\PolygonShapeDescription.h"

PolygonShapeComponent::PolygonShapeComponent(PolygonShapeDescription* description, const std::tstring& name)
	:ShapeComponent(description, name)
{
	OBJECT_INIT(_T("PolygonShapeComponent"));
}
PolygonShapeComponent::~PolygonShapeComponent()
{}

void PolygonShapeComponent::setPoints(const std::vector<Vector2D>& points)
{
	getPolygonDescription()->setPoints(points);
}
void PolygonShapeComponent::setPoints(Vector2D* points, unsigned int size)
{
	getPolygonDescription()->setPoints(points, size);
}
void PolygonShapeComponent::setClose(bool close)
{
	getPolygonDescription()->setClose(close);
}

const std::vector<Vector2D>& PolygonShapeComponent::getPoints() const
{
	return getPolygonDescription()->getPoints();
}
bool PolygonShapeComponent::getClose() const
{
	return getPolygonDescription()->getClose();
}

PolygonShapeDescription* PolygonShapeComponent::getPolygonDescription() const
{
	return dynamic_cast<PolygonShapeDescription*>(getDescription());
}