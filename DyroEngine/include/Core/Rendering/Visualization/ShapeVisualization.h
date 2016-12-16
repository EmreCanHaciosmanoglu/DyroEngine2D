#ifndef _SHAPEVISUALIZATION_H
#define _SHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Visualization.h"

class Object;

class ShapeVisualization : public Visualization
{
public:
	ShapeVisualization(Object* object, const std::tstring& name = _T("ShapeVisualization"));
	virtual ~ShapeVisualization();

protected:

	virtual void generateRenderItems(std::vector<RenderItem*>& items);
};

#endif