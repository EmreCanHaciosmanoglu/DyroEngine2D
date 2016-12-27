#ifndef _POLYGONSHAPECOMPONENT_H
#define _POLYGONSHAPECOMPONENT_H

#include "SceneGraph\Component\Shapes\ShapeComponent.h"

#ifndef _VECTOR2D_H
#include "Helpers\Math\Vector2D.h"
#endif

class PolygonShapeDescription;

class PolygonShapeComponent : public ShapeComponent
{
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