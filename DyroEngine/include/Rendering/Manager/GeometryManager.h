#ifndef _GEOMETRYMANAGER_H
#define _GEOMETRYMANAGER_H

#include "Core/Helpers/Patterns/Manager.h"

class Geometry;
class ShapeDescription;

class GeometryManager : public Manager<Geometry>
{
public:
	GeometryManager();
	virtual ~GeometryManager();

	virtual bool initialize();
	virtual bool shutdown();

	void removeGeometry(Geometry* geometry);
	void removeGeometry(unsigned int id);

	Geometry* getGeometry(ShapeDescription* description);
};

#endif