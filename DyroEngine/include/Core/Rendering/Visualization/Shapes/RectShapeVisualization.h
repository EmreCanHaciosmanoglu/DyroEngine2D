#ifndef _RECTSHAPEVISUALIZATION_H
#define _RECTSHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Shapes/ShapeVisualization.h"
#include "Interfaces/IBoundingBox.h"

class GameObject;
class Component;

class RectShapeVisualization : public ShapeVisualization, public IBoundingBox
{
public:
	RectShapeVisualization(GameObject* object, Component* component);
	virtual ~RectShapeVisualization();

	virtual Rect2D getBoundingBox() const;
};

#endif