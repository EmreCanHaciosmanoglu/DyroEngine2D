#ifndef _POLYGONSHAPE_H
#define _POLYGONSHAPE_H

#include "SceneGraph/Object/Objects/Shapes/Shape.h"
#include "Interfaces/IFillableShape.h"

#ifndef _VECTOR2D_H
#include "Helpers/Math/Vector2D.h"
#endif

#ifndef _VECTOR_
#include <vector>
#endif

class Renderer;

class PolygonShape : public Shape, public IFillableShape
{
public:
	PolygonShape(Vector2D* points, int size, bool close = true, float lineWidth = 0.5f);
	PolygonShape(const std::vector<Vector2D>& vecPoints, bool close = true, float lineWidth = 0.5f);
	virtual ~PolygonShape();

	virtual void setFill(bool fill);
	virtual bool getFill() const;

	virtual void render(Renderer* renderer);
private:
	std::vector<Vector2D> vec_points;
	bool close;
	float line_width;
};

#endif
