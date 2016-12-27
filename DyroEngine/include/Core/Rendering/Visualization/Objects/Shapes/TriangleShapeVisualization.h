#ifndef _TRIANGLESHAPEVISUALIZATION_H
#define _TRIANGLESHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Objects/Shapes/PolygonShapeVisualization.h"

class Component;

class TriangleShapeVisualization : public PolygonShapeVisualization
{
public:
	TriangleShapeVisualization(Component* object, const std::tstring& name = _T("TriangleShapeVisualization"));
	virtual ~TriangleShapeVisualization();

protected:

	virtual void generateRenderItems(std::vector<RenderItem>& items);
};

#endif