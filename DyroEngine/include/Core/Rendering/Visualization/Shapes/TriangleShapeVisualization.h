#ifndef _TRIANGLESHAPEVISUALIZATION_H
#define _TRIANGLESHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Shapes/ShapeVisualization.h"
#include "Interfaces/IBoundingBox.h"

class DataObject;

class TriangleShapeVisualization : public ShapeVisualization, public IBoundingBox
{
public:
	TriangleShapeVisualization(DataObject* object);
	virtual ~TriangleShapeVisualization();

	virtual Rect2D getBoundingBox() const;
};

#endif