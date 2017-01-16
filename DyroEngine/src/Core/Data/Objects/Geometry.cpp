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