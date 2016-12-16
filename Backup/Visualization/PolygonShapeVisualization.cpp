#include "Core/Rendering/Visualization/Shapes/PolygonShapeVisualization.h"
#include "SceneGraph\Component\Shapes\PolygonShapeComponent.h"

#include "Core/Data/Shapes/PolygonShape.h"

PolygonShapeVisualization::PolygonShapeVisualization(Object* object, const std::tstring& name)
	:ShapeVisualization(object, name)
{

}
PolygonShapeVisualization::~PolygonShapeVisualization()
{

}

Rect2D PolygonShapeVisualization::getBoundingBox() const
{
	return Rect2D::empty;
}

void PolygonShapeVisualization::generateRenderItems(std::vector<RenderItem>& items)
{
	PolygonShapeComponent* component = dynamic_cast<PolygonShapeComponent*>(getObject());
	if (component == nullptr)
		return;
}