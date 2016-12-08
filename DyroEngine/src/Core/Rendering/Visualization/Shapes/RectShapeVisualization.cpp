#include "Core/Rendering/Visualization/Shapes/RectShapeVisualization.h"

#include "Core/Data/DataObjects/Shapes/RectShape.h"

RectShapeVisualization::RectShapeVisualization(DataObject* object)
	:ShapeVisualization(object)
{

}
RectShapeVisualization::~RectShapeVisualization()
{

}

Rect2D RectShapeVisualization::getBoundingBox() const
{
	DataObject* object = getDataObject();

	return dynamic_cast<RectShape*>(object)->getBoundingBox();
}
