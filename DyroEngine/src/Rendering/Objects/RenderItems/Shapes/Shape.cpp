#include "Rendering/Objects/RenderItems/Shapes/Shape.h"

#include "Core\Data\Objects\Descriptions\Shapes\ShapeDescription.h"

#include "Core\System\Manager\SystemManager.h"
#include "Core\System\Objects\Graphics.h"

#include "Core\Helpers\Patterns\Singleton.h"

#include "Core\Types\SystemType.h"

#ifndef _2DUTILL_H
#include "Core/Defines/d2dutill.h"
#endif

Shape::Shape(Visualization* parent, const std::tstring& name)
	:RenderItem(parent, name)
	, description(nullptr)
	, geometry(nullptr)
{}
Shape::Shape(Visualization* parent, ShapeDescription* description, const std::tstring& name)
	:RenderItem(parent, name)
	, description(description)
	, geometry(nullptr)
{}
Shape::~Shape()
{}

bool Shape::isTransparant() const
{
	return this->description->getColor().alpha != 1.0f;
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