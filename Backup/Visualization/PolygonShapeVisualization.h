#ifndef _POLYGONSHAPEVISUALIZATION_H
#define _POLYGONSHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Shapes/ShapeVisualization.h"
#include "Interfaces/IBoundingBox.h"

class Object;

class PolygonShapeVisualization : public ShapeVisualization, public IBoundingBox
{
public:
	PolygonShapeVisualization(Object* object, const std::tstring& name = _T("PolygonVisualization"));
	virtual ~PolygonShapeVisualization();

	virtual Rect2D getBoundingBox() const;

protected:

	virtual void generateRenderItems(std::vector<RenderItem*>& items);
};

#endif