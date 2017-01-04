#ifndef _RECTSHAPEVISUALIZATION_H
#define _RECTSHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Objects/Shapes/ShapeVisualization.h"

class Component;

class RectShapeVisualization : public ShapeVisualization
{
public:
	RectShapeVisualization(Component* object, const std::tstring& name = _T("RectVisualization"));
	virtual ~RectShapeVisualization();

protected:

	virtual void generateRenderItems(std::vector<RenderItem*>& items);
};

#endif