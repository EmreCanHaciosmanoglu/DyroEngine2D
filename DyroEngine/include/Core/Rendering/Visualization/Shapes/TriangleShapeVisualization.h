#ifndef _TRIANGLESHAPEVISUALIZATION_H
#define _TRIANGLESHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Shapes/ShapeVisualization.h"
#include "Interfaces/IBoundingBox.h"

class GameObject;

class TriangleShapeVisualization : public ShapeVisualization, public IBoundingBox
{
public:
	TriangleShapeVisualization(GameObject* object);
	virtual ~TriangleShapeVisualization();

	virtual Rect2D getBoundingBox() const;
};

#endif