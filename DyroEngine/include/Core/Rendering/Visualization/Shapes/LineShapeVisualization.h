#ifndef _LINEVISUALIZATION_H
#define _LINESHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Shapes/ShapeVisualization.h"

class GameObject;
class Component;

class LineShapeVisualization : public ShapeVisualization
{
public:
	LineShapeVisualization(GameObject* object, Component* component);
	virtual ~LineShapeVisualization();
};

#endif