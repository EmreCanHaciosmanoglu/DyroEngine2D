#ifndef _GEOMETRY_H
#define _GEOMETRY_H

#include "Core/Helpers/TaggedObject.h"

#ifndef _RECT2D_H
#include "Math/Objects/Rect2D.h"
#endif
#ifndef _MATRIX2D_H
#include "Math\Objects\Matrix2D.h"
#endif

struct ID2D1Geometry;

class Geometry : public TaggedObject<Geometry>
{
public:
	Geometry(ID2D1Geometry* geometry, const std::tstring& name = _T("Geometry"));
	virtual ~Geometry();

	ID2D1Geometry* getGeometry() const;
	Rect2D getBounds(const Matrix2D& transform) const;

private:
	ID2D1Geometry* geometry;
};

#endif