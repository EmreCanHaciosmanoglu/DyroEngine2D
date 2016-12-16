#ifndef _LINEVISUALIZATION_H
#define _LINESHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Shapes/ShapeVisualization.h"

class Object;

class LineShapeVisualization : public ShapeVisualization
{
public:
	LineShapeVisualization(Object* object, const std::tstring& name = _T("LineVisualization"));
	virtual ~LineShapeVisualization();

protected:

	virtual void generateRenderItems(std::vector<RenderItem*>& items);
};

#endif