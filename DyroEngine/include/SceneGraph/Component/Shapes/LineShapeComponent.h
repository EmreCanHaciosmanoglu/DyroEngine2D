#ifndef _LINESHAPECOMPONENT_H
#define _LINESHAPECOMPONENT_H

#include "SceneGraph\Component\Shapes\ShapeComponent.h"

#ifndef _VECTOR2D_H
#include "Helpers\Math\Vector2D.h"
#endif

class LineShapeDescription;

class LineShapeComponent : public ShapeComponent
{
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