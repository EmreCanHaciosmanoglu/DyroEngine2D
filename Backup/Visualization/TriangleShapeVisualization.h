#ifndef _TRIANGLESHAPEVISUALIZATION_H
#define _TRIANGLESHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Shapes/PolygonShapeVisualization.h"
#include "Interfaces/IBoundingBox.h"

class Object;

class TriangleShapeVisualization : public PolygonShapeVisualization, public IBoundingBox
{
public:
	TriangleShapeVisualization(Object* object, const std::tstring& name = _T("TriangleShapeVisualization"));
	virtual ~TriangleShapeVisualization();

	virtual Rect2D getBoundingBox() const;

protected:

	virtual void generateRenderItems(std::vector<RenderItem*>& items);
};

#endif