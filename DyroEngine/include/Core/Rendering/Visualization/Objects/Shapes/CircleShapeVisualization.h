#ifndef _CIRLCESHAPEVISUALIZATION_H
#define _CIRLCESHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Objects/Shapes/ShapeVisualization.h"

class Component;

class CircleShapeVisualization : public ShapeVisualization
{
public:
	CircleShapeVisualization(Component* object, const std::tstring& name = _T("CircleVisualization"));
	virtual ~CircleShapeVisualization();

protected:

	virtual void generateRenderItems(std::vector<RenderItem>& items);
};

#endif