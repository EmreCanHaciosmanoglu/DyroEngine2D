#include "Rendering/Objects/RenderItems/Shapes/Shape.h"

#include "Core\Data\Objects\Descriptions\Shapes\ShapeDescription.h"
#include "Core\Data\Objects\Geometry.h"

#include "Core\System\Manager\SystemManager.h"
#include "Core\System\Objects\Graphics.h"

#include "Core\Helpers\Patterns\Singleton.h"

#include "Core\Types\SystemType.h"

#ifndef _2DUTILL_H
#include "Core/Defines/d2dutill.h"
#endif

Shape::Shape(const std::tstring& name)
	:RenderItem(name)
	, description(nullptr)
	, geometry(nullptr)
{}
Shape::Shape(ShapeDescription* description, Geometry* geometry, const std::tstring& name)
	:RenderItem(name)
	, description(description)
	, geometry(geometry)
{}
Shape::~Shape()
{}

bool Shape::isTransparant() const
{
	return this->description->getColor().alpha != 1.0f;
}
Rect2D Shape::getBounds() const
{
	return this->geometry->getBounds(getTransform());
}

void Shape::setDescription(ShapeDescription* description)
{
	this->description = description;
}
ShapeDescription* Shape::getDescription() const
{
	return this->description;
}
Geometry* Shape::getGeometry() const
{
	return this->geometry;
}
Graphics* Shape::getGraphics() const
{
	return dynamic_cast<Graphics*>(SystemManager::getInstance().getSystem(SystemType::GRAPHICS_SYSTEM));
}