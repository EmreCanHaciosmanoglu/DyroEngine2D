#ifndef _POLYGONSHAPEDESCRIPTION_H
#define _POLYGONSHAPEDESCRIPTION_H

#include "Core\Data\Objects\Descriptions\Shapes\ShapeDescription.h"

#ifndef _VECTOR2D_H
#include "Helpers\Math/Vector2D.h"
#endif

#ifndef _VECTOR_
#include <vector>
#endif

class PolygonShapeDescription : public ShapeDescription
{
public:
	PolygonShapeDescription();
	PolygonShapeDescription(const PolygonShapeDescription& ref);
	PolygonShapeDescription(Vector2D* points, unsigned int size, bool close = true, float lineWidth = 0.5f);
	PolygonShapeDescription(const std::vector<Vector2D>& vecPoints, bool close = true, float lineWidth = 0.5f);
	virtual ~PolygonShapeDescription();

	bool operator==(const PolygonShapeDescription& ref) const;
	bool operator!=(const PolygonShapeDescription& ref) const;

	PolygonShapeDescription& operator=(const PolygonShapeDescription& ref);

	void setPoints(const std::vector<Vector2D>& points);
	void setPoints(Vector2D* points, unsigned int size);
	void setClose(bool close);

	const std::vector<Vector2D>& getPoints() const;
	bool getClose() const;
private:
	std::vector<Vector2D> vec_points;
	bool close;
};

#endif