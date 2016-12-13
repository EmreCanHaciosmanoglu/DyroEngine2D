#ifndef _POLYGONSHAPE_H
#define _POLYGONSHAPE_H

#include "Core/Data/Shapes/Shape.h"

#ifndef _IFILLABLESHAPE_H
#include "Interfaces/IFillableShape.h"
#endif
#ifndef _IBOUNDINGBOX_H
#include "Interfaces\IBoundingBox.h"
#endif

#ifndef _VECTOR2D_H
#include "Helpers/Math/Vector2D.h"
#endif

#ifndef _VECTOR_
#include <vector>
#endif

class Renderer;

class PolygonShape : public Shape, public IFillableShape, public IBoundingBox
{
public:
	PolygonShape(Vector2D* points, int size, bool close = true, float lineWidth = 0.5f, const std::tstring& name = _T(""));
	PolygonShape(const std::vector<Vector2D>& vecPoints, bool close = true, float lineWidth = 0.5f, const std::tstring& name = _T(""));
	virtual ~PolygonShape();

	virtual void setFill(bool fill);
	virtual bool getFill() const;

	virtual void render(Renderer* renderer);

	virtual Rect2D getBoundingBox() const;
private:
	std::vector<Vector2D> vec_points;
	bool close;
	float line_width;
};

#endif
