#ifndef _CIRLCESHAPEVISUALIZATION_H
#define _CIRLCESHAPEVISUALIZATION_H

#include "Core/Rendering/Visualization/Shapes/ShapeVisualization.h"
#include "Interfaces/IBoundingBox.h"

class Object;

class CircleShapeVisualization : public ShapeVisualization , public IBoundingBox
{
public:
	CircleShapeVisualization(Object* object, const std::tstring& name = _T("CircleVisualization"));
	virtual ~CircleShapeVisualization();

	virtual Rect2D getBoundingBox() const;

protected:

	virtual void generateRenderItems(std::vector<RenderItem*>& items);
};

#endif