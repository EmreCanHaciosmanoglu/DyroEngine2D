#include "Core/Rendering/Visualization/Shapes/CircleShapeVisualization.h"

#include "Core/Data/DataObjects/Shapes/CircleShape.h"

CircleShapeVisualization::CircleShapeVisualization(GameObject* object)
	:ShapeVisualization(object)
{

}
CircleShapeVisualization::~CircleShapeVisualization()
{

}

Rect2D CircleShapeVisualization::getBoundingBox() const
{
	GameObject* object = getDataObject();

	return dynamic_cast<CircleShape*>(object)->getBoundingBox();
}
