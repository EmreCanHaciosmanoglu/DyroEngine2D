#ifndef _TRIANGLESHAPEVISUALIZATION_H
#define _TRIANGLESHAPEVISUALIZATION_H

#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/PolygonShapeVisualization.h"

class Component;

class TriangleShapeVisualization : public PolygonShapeVisualization
{
public:
	TriangleShapeVisualization(Component* object, const std::tstring& name = _T("TriangleShapeVisualization"));
	virtual ~TriangleShapeVisualization();

protected:

	virtual void generateRenderItems(std::vector<RenderItem*>& items);
};

#endif