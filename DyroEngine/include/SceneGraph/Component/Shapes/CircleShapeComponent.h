#ifndef _CIRCLESHAPCOMPONENT_H
#define _CIRCLESHAPCOMPONENT_H

#include "SceneGraph\Component\Shapes\ShapeComponent.h"
#ifndef _IBOUNDINGBOX_H
#include "Interfaces\IBoundingBox.h"
#endif

class CircleShape;

class CircleShapeComponent : public ShapeComponent , public IBoundingBox
{
public:
	CircleShapeComponent(CircleShape* shape, const std::tstring& name = _T(""));
	virtual ~CircleShapeComponent();

	CircleShape* getCircleShape() const;

	Rect2D getBoundingBox() const;
};

#endif