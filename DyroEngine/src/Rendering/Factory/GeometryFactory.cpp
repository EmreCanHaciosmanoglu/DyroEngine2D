#include "Rendering/Factory/GeometryFactory.h"

#ifndef _2DUTILL_H
#include "Core/Defines/d2dutill.h"
#endif

#include "Core/Types/GeometryType.h"

GeometryFactory::GeometryFactory()
{}
GeometryFactory::~GeometryFactory()
{}

ID2D1Geometry* GeometryFactory::createGeometry(GeometryType type)
{
	switch (type)
	{
	case GeometryType::LINE_GEOMETRY:
		break;
	case GeometryType::CIRCLE_GEOMETRY:
		break;
	case GeometryType::POLYGON_GEOMETRY:
		break;
	case GeometryType::RECTANGLE_GEOMETRY:
		break;
	case GeometryType::TRIANGLE_GEOMETRY:
		break;
	}

	return nullptr;
}