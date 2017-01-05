#ifndef _LINESHAPECOMPONENT_H
#define _LINESHAPECOMPONENT_H

#include "SceneGraph\Objects\Components\Shapes\ShapeComponent.h"

#ifndef _VECTOR2D_H
#include "Math/Objects/Vector2D.h"
#endif

class LineShapeDescription;

class LineShapeComponent : public ShapeComponent
{
	/**
	\note Must be present in every subclass definition.
	*/
	OBJECT_STATICS("LineShapeComponent")

public:
	LineShapeComponent(LineShapeDescription* description, const std::tstring& name = _T(""));
	virtual ~LineShapeComponent();

	void setStartPosition(const Vector2D& start);
	void setEndPosition(const Vector2D& end);

	const Vector2D& getStartPosition() const;
	const Vector2D& getEndPosition() const;

	LineShapeDescription* getLineDescription() const;
};

#endif