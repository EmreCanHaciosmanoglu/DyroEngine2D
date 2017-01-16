#ifndef _GEOMETRYFACTORY_H
#define _GEOMETRYFACTORY_H

class Geometry;
class ShapeDescription;
enum class GeometryType;

class GeometryFactory
{
public:
	GeometryFactory();
	~GeometryFactory();

	Geometry* createGeometry(ShapeDescription* description);

private:
	Geometry* createRectangleGeometry(ShapeDescription* description);
	Geometry* createCircleGeometry(ShapeDescription* description);
	Geometry* createLineGeometry(ShapeDescription* description);
	Geometry* createPolygonGeometry(ShapeDescription* description);
};

#endif