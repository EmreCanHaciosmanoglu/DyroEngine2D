#include "Core/Rendering/Visualization/Shapes/TriangleShapeVisualization.h"

#include "Core/Data/DataObjects/Shapes/TriangleShape.h"

TriangleShapeVisualization::TriangleShapeVisualization(GameObject* object)
	:ShapeVisualization(object)
{

}
TriangleShapeVisualization::~TriangleShapeVisualization()
{

}

Rect2D TriangleShapeVisualization::getBoundingBox() const
{
	GameObject* object = getDataObject();

	return dynamic_cast<TriangleShape*>(object)->getBoundingBox();
}
