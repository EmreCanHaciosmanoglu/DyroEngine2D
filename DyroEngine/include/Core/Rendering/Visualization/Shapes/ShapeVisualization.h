#ifndef _SHAPEVISUALIZATION_H
#define _SHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Visualization.h"

class GameObject;

class ShapeVisualization : public Visualization
{
public:
	ShapeVisualization(GameObject* object);
	virtual ~ShapeVisualization();
};

#endif