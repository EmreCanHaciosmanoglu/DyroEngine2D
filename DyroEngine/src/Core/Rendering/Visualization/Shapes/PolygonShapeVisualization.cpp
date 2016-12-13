#include "Core/Rendering/Visualization/Shapes/PolygonShapeVisualization.h"

#include "Core/Data/Shapes/PolygonShape.h"

PolygonShapeVisualization::PolygonShapeVisualization(GameObject* object)
	:ShapeVisualization(object)
{

}
PolygonShapeVisualization::~PolygonShapeVisualization()
{

}

Rect2D PolygonShapeVisualization::getBoundingBox() const
{
	return Rect2D::empty;
}
