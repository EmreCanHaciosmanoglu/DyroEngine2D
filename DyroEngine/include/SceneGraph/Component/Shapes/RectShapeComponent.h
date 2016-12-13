#ifndef _RECTSHAPECOMPONENT_H
#define _RECTSHAPECOMPONENT_H

#include "SceneGraph\Component\Shapes\ShapeComponent.h"
#ifndef _IBOUNDINGBOX_H
#include "Interfaces\IBoundingBox.h"
#endif

class RectShape;

class RectShapeComponent : public ShapeComponent , public IBoundingBox
{
public:
	RectShapeComponent(RectShape* shape, const std::tstring& name = _T(""));
	virtual ~RectShapeComponent();

	RectShape* getRectShape() const;

	Rect2D getBoundingBox() const;
};

#endif