#ifndef _POLYGONSHAPEVISUALIZATION_H
#define _POLYGONSHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Objects/Shapes/ShapeVisualization.h"

class Component;

class PolygonShapeVisualization : public ShapeVisualization
{
public:
	PolygonShapeVisualization(Component* object, const std::tstring& name = _T("PolygonVisualization"));
	virtual ~PolygonShapeVisualization();

protected:

	virtual void generateRenderItems(std::vector<RenderItem*>& items);
};

#endif