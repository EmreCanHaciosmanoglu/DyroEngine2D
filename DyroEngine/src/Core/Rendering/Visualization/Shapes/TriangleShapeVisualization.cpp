#include "Core/Rendering/Visualization/Shapes/TriangleShapeVisualization.h"

#include "Core/Data/Shapes/TriangleShape.h"

TriangleShapeVisualization::TriangleShapeVisualization(GameObject* object, Component* component)
	:ShapeVisualization(object, component, _T("TriangleVisualization"))
{

}
TriangleShapeVisualization::~TriangleShapeVisualization()
{

}

Rect2D TriangleShapeVisualization::getBoundingBox() const
{
	return Rect2D::empty;
}
