#include "Core/Rendering/Visualization/Shapes/RectShapeVisualization.h"

#include "Core/Data/DataObjects/Shapes/RectShape.h"

RectShapeVisualization::RectShapeVisualization(GameObject* object)
	:ShapeVisualization(object)
{

}
RectShapeVisualization::~RectShapeVisualization()
{

}

Rect2D RectShapeVisualization::getBoundingBox() const
{
	GameObject* object = getDataObject();

	return dynamic_cast<RectShape*>(object)->getBoundingBox();
}
