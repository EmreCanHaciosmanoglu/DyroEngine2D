#include "Core/Rendering/Visualization/Shapes/RectShapeVisualization.h"

#include "Core/Data/Shapes/RectShape.h"

RectShapeVisualization::RectShapeVisualization(GameObject* object, Component* component)
	:ShapeVisualization(object, component, _T("RectVisualization"))
{
}
RectShapeVisualization::~RectShapeVisualization()
{

}

Rect2D RectShapeVisualization::getBoundingBox() const
{
	return Rect2D::empty;
}
