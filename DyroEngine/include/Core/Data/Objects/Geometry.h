#ifndef _GEOMETRY_H
#define _GEOMETRY_H

#include "Core/Helpers/TaggedObject.h"

struct ID2D1Geometry;

class Geometry : public TaggedObject<Geometry>
{
public:
	Geometry(ID2D1Geometry* geometry, const std::tstring& name = _T("Geometry"));
	virtual ~Geometry();

	ID2D1Geometry* getGeometry() const;

private:
	ID2D1Geometry* geometry;
};

#endif