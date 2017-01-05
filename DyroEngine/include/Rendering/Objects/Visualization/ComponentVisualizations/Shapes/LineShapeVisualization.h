#ifndef _LINEVISUALIZATION_H
#define _LINESHAPEVISUALIZATION_H

#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/ShapeVisualization.h"

class Component;

class LineShapeVisualization : public ShapeVisualization
{
public:
	LineShapeVisualization(Component* object, const std::tstring& name = _T("LineVisualization"));
	virtual ~LineShapeVisualization();

protected:

	virtual void generateRenderItems(std::vector<RenderItem*>& items);
};

#endif