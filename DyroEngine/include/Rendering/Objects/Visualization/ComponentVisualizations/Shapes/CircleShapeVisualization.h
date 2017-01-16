#ifndef _CIRLCESHAPEVISUALIZATION_H
#define _CIRLCESHAPEVISUALIZATION_H

#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/ShapeVisualization.h"

class Component;

class CircleShapeVisualization : public ShapeVisualization
{
public:
	CircleShapeVisualization(Component* object, const std::tstring& name = _T("CircleVisualization"));
	virtual ~CircleShapeVisualization();

	virtual bool initialize();
	virtual bool shutdown();

protected:

	virtual void generateRenderItems(std::vector<RenderItem*>& items);
};

#endif