#include "Core/Rendering/Visualization/Shapes/CircleShapeVisualization.h"

#include "Core/Data/Shapes/CircleShape.h"

CircleShapeVisualization::CircleShapeVisualization(GameObject* object, Component* component)
	:ShapeVisualization(object, component, _T("CircleVisualization"))
{
}
CircleShapeVisualization::~CircleShapeVisualization()
{
}

Rect2D CircleShapeVisualization::getBoundingBox() const
{
	return Rect2D::empty;
}
