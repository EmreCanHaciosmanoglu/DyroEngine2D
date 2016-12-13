#ifndef _TRIANGLESHAPECOMPONENT_H
#define _TRIANGLESHAPECOMPONENT_H

#include "SceneGraph\Component\Shapes\PolygonShapeComponent.h"

class TriangleShape;

class TriangleShapeComponent : public PolygonShapeComponent
{
public:
	TriangleShapeComponent(TriangleShape* shape, const std::tstring& name = _T(""));
	virtual ~TriangleShapeComponent();

	TriangleShape* getTriangleShape() const;
};

#endif