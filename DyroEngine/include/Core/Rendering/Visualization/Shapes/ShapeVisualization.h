#ifndef _SHAPEVISUALIZATION_H
#define _SHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Visualization.h"

class GameObject;
class Component;

class ShapeVisualization : public Visualization
{
public:
	ShapeVisualization(GameObject* object, Component* component, const std::tstring& name = _T("ShapeVisualization"));
	virtual ~ShapeVisualization();
};

#endif