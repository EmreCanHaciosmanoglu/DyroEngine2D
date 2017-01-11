#include "Rendering/Manager/GeometryManager.h"
#include "Rendering/Factory/GeometryFactory.h"

#ifndef _2DUTILL_H
#include "Core/Defines/d2dutill.h"
#endif

#include "Core/Types/GeometryType.h"

GeometryManager::GeometryManager()
{}
GeometryManager::~GeometryManager()
{}

bool GeometryManager::initialize()
{
	return true;
}
bool GeometryManager::shutdown()
{
	std::vector<ID2D1Geometry*> geometry;
	getObjects(geometry);

	for (ID2D1Geometry* g : geometry)
		g->Release();

	return true;
}

void GeometryManager::removeGeometry(ID2D1Geometry* geometry)
{
	removeObject(geometry);
}
void GeometryManager::removeGeometry(unsigned int id)
{
	removeObject(id);
}

ID2D1Geometry* GeometryManager::getGeometry(GeometryType type)
{
	ID2D1Geometry* geometry = getObject((int)type);

	if (geometry != nullptr)
		return geometry;

	GeometryFactory factory;
	geometry = factory.createGeometry(type);

	addObject((int)type, geometry);

	return geometry;
}