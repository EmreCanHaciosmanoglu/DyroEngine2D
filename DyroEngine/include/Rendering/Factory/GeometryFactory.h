#ifndef _GEOMETRYFACTORY_H
#define _GEOMETRYFACTORY_H

class ID2D1Geometry;
enum class GeometryType;

class GeometryFactory
{
public:
	GeometryFactory();
	~GeometryFactory();

	ID2D1Geometry* createGeometry(GeometryType type);
};

#endif