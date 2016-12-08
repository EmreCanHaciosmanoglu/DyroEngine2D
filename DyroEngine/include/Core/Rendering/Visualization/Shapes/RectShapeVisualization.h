#ifndef _RECTSHAPEVISUALIZATION_H
#define _RECTSHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Shapes/ShapeVisualization.h"
#include "Interfaces/IBoundingBox.h"

class DataObject;

class RectShapeVisualization : public ShapeVisualization, public IBoundingBox
{
public:
	RectShapeVisualization(DataObject* object);
	virtual ~RectShapeVisualization();

	virtual Rect2D getBoundingBox() const;
};

#endif