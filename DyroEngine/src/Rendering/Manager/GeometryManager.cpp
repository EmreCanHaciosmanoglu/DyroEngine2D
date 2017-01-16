#include "Rendering/Manager/GeometryManager.h"
#include "Rendering/Factory/GeometryFactory.h"

#include "Core/Data/Objects/Descriptions/Shapes/ShapeDescription.h"
#include "Core/Data/Objects//Geometry.h"

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
	std::vector<Geometry*> geometry;
	getObjects(geometry);

	for (Geometry* g : geometry)
		delete g;

	return true;
}

void GeometryManager::removeGeometry(Geometry* geometry)
{
	removeObject(geometry);
}
void GeometryManager::removeGeometry(unsigned int id)
{
	removeObject(id);
}

Geometry* GeometryManager::getGeometry(ShapeDescription* description)
{
	GeometryFactory factory;
	Geometry* geometry = factory.createGeometry(description);

	addObject((int)description->getGeometryType(), geometry);

	return geometry;
}