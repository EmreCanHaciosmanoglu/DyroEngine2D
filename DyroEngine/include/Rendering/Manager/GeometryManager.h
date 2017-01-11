#ifndef _GEOMETRYMANAGER_H
#define _GEOMETRYMANAGER_H

#include "Core/Helpers/Patterns/Manager.h"

class ID2D1Geometry;
enum class GeometryType;

class GeometryManager : public Manager<ID2D1Geometry>
{
public:
	GeometryManager();
	virtual ~GeometryManager();

	virtual bool initialize();
	virtual bool shutdown();

	void removeGeometry(ID2D1Geometry* geometry);
	void removeGeometry(unsigned int id);

	ID2D1Geometry* getGeometry(GeometryType type);
};

#endif