#include "Core/Rendering/Visualization/Shapes/TriangleShapeVisualization.h"

#include "Core/Data/Shapes/TriangleShape.h"

TriangleShapeVisualization::TriangleShapeVisualization(GameObject* object)
	:ShapeVisualization(object)
{

}
TriangleShapeVisualization::~TriangleShapeVisualization()
{

}

Rect2D TriangleShapeVisualization::getBoundingBox() const
{
	return Rect2D::empty;
}
