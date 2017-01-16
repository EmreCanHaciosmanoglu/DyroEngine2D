#include "Core/Data/Manager/GeometryManager.h"
#include "Core/Data/Factory/GeometryFactory.h"

#include "Core/Data/Objects/Descriptions/Shapes/ShapeDescription.h"
#include "Core/Data/Objects//Geometry.h"

#include "Core/Types/GeometryType.h"

#include "Core/Defines/deletemacros.h"

GeometryManager::GeometryManager()
	:factory(nullptr)
{
	this->factory = new GeometryFactory();
}
GeometryManager::~GeometryManager()
{
	SafeDelete(this->factory);
}

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

void GeometryManager::addGeometry(Geometry* geometry)
{
	addObject(geometry->getID(), geometry);
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
	Geometry* geometry = this->factory->createGeometry(description);

	addObject((int)description->getGeometryType(), geometry);

	return geometry;
}