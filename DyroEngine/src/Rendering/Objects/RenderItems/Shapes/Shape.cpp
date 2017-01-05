#include "Rendering/Objects/RenderItems/Shapes/Shape.h"
#include "Core\Data\Objects\Descriptions\Shapes\ShapeDescription.h"

Shape::Shape(const std::tstring& name)
	:RenderItem(name)
	, description(nullptr)
{}
Shape::Shape(ShapeDescription* description, const std::tstring& name)
	:RenderItem(name)
	, description(description)
{}
Shape::~Shape()
{}

void Shape::setDescription(ShapeDescription* description)
{
	this->description = description;
}
ShapeDescription* Shape::getDescription() const
{
	return this->description;
}

bool Shape::isTransparant() const
{
	return this->description->getColor().alpha != 1.0f;
} 