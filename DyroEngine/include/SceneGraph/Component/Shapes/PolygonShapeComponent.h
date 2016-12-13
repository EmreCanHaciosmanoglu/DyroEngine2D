#ifndef _POLYGONSHAPECOMPONENT_H
#define _POLYGONSHAPECOMPONENT_H

#include "SceneGraph\Component\Shapes\ShapeComponent.h"
#ifndef _IBOUNDINGBOX_H
#include "Interfaces\IBoundingBox.h"
#endif

class PolygonShape;

class PolygonShapeComponent : public ShapeComponent , public IBoundingBox
{
public:
	PolygonShapeComponent(PolygonShape* shape, const std::tstring& name = _T(""));
	virtual ~PolygonShapeComponent();

	PolygonShape* getPolygonShape() const;

	Rect2D getBoundingBox() const;
};

#endif