#ifndef _TRIANGLESHAPECOMPONENT_H
#define _TRIANGLESHAPECOMPONENT_H

#include "SceneGraph\Component\Shapes\PolygonShapeComponent.h"

class TriangleShapeDescription;

class TriangleShapeComponent : public PolygonShapeComponent
{
	/**
	\note Must be present in every subclass definition.
	*/
	OBJECT_STATICS("TriangleShapeComponent")

public:
	TriangleShapeComponent(TriangleShapeDescription* shape, const std::tstring& name = _T(""));
	virtual ~TriangleShapeComponent();

	void setXScale(float scale);
	void setYScale(float scale);

	float getXScale() const;
	float getYScale() const;

	TriangleShapeDescription* getTriangleDescription() const;
};

#endif