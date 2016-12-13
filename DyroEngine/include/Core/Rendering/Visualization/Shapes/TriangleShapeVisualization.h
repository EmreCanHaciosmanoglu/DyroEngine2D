#ifndef _TRIANGLESHAPEVISUALIZATION_H
#define _TRIANGLESHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Shapes/ShapeVisualization.h"
#include "Interfaces/IBoundingBox.h"

class GameObject;
class Component;

class TriangleShapeVisualization : public ShapeVisualization, public IBoundingBox
{
public:
	TriangleShapeVisualization(GameObject* object, Component* component);
	virtual ~TriangleShapeVisualization();

	virtual Rect2D getBoundingBox() const;
};

#endif