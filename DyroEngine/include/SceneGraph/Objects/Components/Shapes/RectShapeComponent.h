#ifndef _RECTSHAPECOMPONENT_H
#define _RECTSHAPECOMPONENT_H

#include "SceneGraph\Objects\Components\Shapes\ShapeComponent.h"

#ifndef _VECTOR2D_H
#include "Math/Objects/Vector2D.h"
#endif
#ifndef _RECT2D_H
#include "Math/Objects/Rect2D.h"
#endif

class RectShapeDescription;

class RectShapeComponent : public ShapeComponent
{
	/**
	\note Must be present in every subclass definition.
	*/
	OBJECT_STATICS("RectShapeComponent")

public:
	RectShapeComponent(RectShapeDescription* description, const std::tstring& name = _T(""));
	virtual ~RectShapeComponent();

	void setRect(const Rect2D& rect);

	const Rect2D& getRect();

	RectShapeDescription* getRectDescription() const;
};

#endif