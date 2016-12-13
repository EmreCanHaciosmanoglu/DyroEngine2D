#ifndef _LINESHAPECOMPONENT_H
#define _LINESHAPECOMPONENT_H

#include "SceneGraph\Component\Shapes\ShapeComponent.h"

class LineShape;

class LineShapeComponent : public ShapeComponent
{
public:
	LineShapeComponent(LineShape* shape, const std::tstring& name = _T(""));
	virtual ~LineShapeComponent();

	LineShape* getLineShape() const;
};

#endif