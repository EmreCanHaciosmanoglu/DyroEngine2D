#ifndef _POLYGONSHAPECOMPONENT_H
#define _POLYGONSHAPECOMPONENT_H

#include "SceneGraph\Objects\Components\Shapes\ShapeComponent.h"

#ifndef _VECTOR2D_H
#include "Math/Objects/Vector2D.h"
#endif

class PolygonShapeDescription;

class PolygonShapeComponent : public ShapeComponent
{
	/**
	\note Must be present in every subclass definition.
	*/
	OBJECT_STATICS("PolygonShapeComponent")

public:
	PolygonShapeComponent(PolygonShapeDescription* description, const std::tstring& name = _T(""));
	virtual ~PolygonShapeComponent();

	void setPoints(const std::vector<Vector2D>& points);
	void setPoints(Vector2D* points, unsigned int size);
	void setClose(bool close);

	const std::vector<Vector2D>& getPoints() const;
	bool getClose() const;

	PolygonShapeDescription* getPolygonDescription() const;
};

#endif