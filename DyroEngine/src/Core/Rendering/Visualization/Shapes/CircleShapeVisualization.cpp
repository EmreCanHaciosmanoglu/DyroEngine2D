#include "Core/Rendering/Visualization/Shapes/CircleShapeVisualization.h"

#include "Core/Data/DataObjects/Shapes/CircleShape.h"

CircleShapeVisualization::CircleShapeVisualization(DataObject* object)
	:ShapeVisualization(object)
{

}
CircleShapeVisualization::~CircleShapeVisualization()
{

}

Rect2D CircleShapeVisualization::getBoundingBox() const
{
	DataObject* object = getDataObject();

	return dynamic_cast<CircleShape*>(object)->getBoundingBox();
}
