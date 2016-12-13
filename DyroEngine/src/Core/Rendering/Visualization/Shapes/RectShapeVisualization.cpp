#include "Core/Rendering/Visualization/Shapes/RectShapeVisualization.h"

#include "Core/Data/Shapes/RectShape.h"

RectShapeVisualization::RectShapeVisualization(GameObject* object)
	:ShapeVisualization(object)
{
}
RectShapeVisualization::~RectShapeVisualization()
{

}

Rect2D RectShapeVisualization::getBoundingBox() const
{
	return Rect2D::empty;
}
