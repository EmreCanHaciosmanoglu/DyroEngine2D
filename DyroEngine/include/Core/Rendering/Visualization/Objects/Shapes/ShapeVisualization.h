#ifndef _SHAPEVISUALIZATION_H
#define _SHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Objects/ComponentVisualization.h"

class Component;

class ShapeVisualization : public ComponentVisualization
{
public:
	ShapeVisualization(Component* object, const std::tstring& name = _T("ShapeVisualization"));
	virtual ~ShapeVisualization();

protected:

	virtual void generateRenderItems(std::vector<RenderItem*>& items) = 0;
};

#endif