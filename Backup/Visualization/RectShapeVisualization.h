#ifndef _RECTSHAPEVISUALIZATION_H
#define _RECTSHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Shapes/ShapeVisualization.h"
#include "Interfaces/IBoundingBox.h"

class Object;

class RectShapeVisualization : public ShapeVisualization, public IBoundingBox
{
public:
	RectShapeVisualization(Object* object, const std::tstring& name = _T("RectVisualization"));
	virtual ~RectShapeVisualization();

	virtual Rect2D getBoundingBox() const;

protected:

	virtual void generateRenderItems(std::vector<RenderItem*>& items);
};

#endif