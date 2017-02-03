#include "Core/Data/Objects/Geometry.h"

#ifndef _2DUTILL_H
#include "Core/Defines/d2dutill.h"
#endif

Geometry::Geometry(ID2D1Geometry* geometry, const std::tstring& name)
	:TaggedObject(name)
	,geometry(geometry)
{}
Geometry::~Geometry()
{
	this->geometry->Release();
}

ID2D1Geometry* Geometry::getGeometry() const
{
	return this->geometry;
}
Rect2D Geometry::getBounds(const Matrix2D& transform) const
{
	D2D1_RECT_F bounds;
	this->geometry->GetBounds(transform.toMatrix3x2F(), &bounds);

	return Rect2D(bounds.left, bounds.top, bounds.right, bounds.bottom);
}