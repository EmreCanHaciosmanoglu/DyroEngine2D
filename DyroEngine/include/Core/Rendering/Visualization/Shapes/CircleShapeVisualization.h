#ifndef _CIRLCESHAPEVISUALIZATION_H
#define _CIRLCESHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Shapes/ShapeVisualization.h"
#include "Interfaces/IBoundingBox.h"

class GameObject;

class CircleShapeVisualization : public ShapeVisualization , public IBoundingBox
{
public:
	CircleShapeVisualization(GameObject* object);
	virtual ~CircleShapeVisualization();

	virtual Rect2D getBoundingBox() const;
};

#endif