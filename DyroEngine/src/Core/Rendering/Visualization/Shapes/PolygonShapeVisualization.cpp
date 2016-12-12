#include "Core/Rendering/Visualization/Shapes/PolygonShapeVisualization.h"

#include "Core/Data/DataObjects/Shapes/PolygonShape.h"

PolygonShapeVisualization::PolygonShapeVisualization(GameObject* object)
	:ShapeVisualization(object)
{

}
PolygonShapeVisualization::~PolygonShapeVisualization()
{

}

Rect2D PolygonShapeVisualization::getBoundingBox() const
{
	GameObject* object = getDataObject();

	return dynamic_cast<PolygonShape*>(object)->getBoundingBox();
}
