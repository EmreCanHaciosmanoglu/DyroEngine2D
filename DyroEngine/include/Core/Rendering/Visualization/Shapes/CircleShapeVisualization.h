#ifndef _CIRLCESHAPEVISUALIZATION_H
#define _CIRLCESHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Shapes/ShapeVisualization.h"
#include "Interfaces/IBoundingBox.h"

class DataObject;

class CircleShapeVisualization : public ShapeVisualization , public IBoundingBox
{
public:
	CircleShapeVisualization(DataObject* object);
	virtual ~CircleShapeVisualization();

	virtual Rect2D getBoundingBox() const;
};

#endif