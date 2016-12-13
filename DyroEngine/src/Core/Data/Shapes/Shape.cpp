#include "Core/Data/Shapes/Shape.h"

Shape::Shape(const std::tstring& name)
	:TaggedObject(name)
	,color(1,1,1,1)
{
}
Shape::~Shape()
{}

void Shape::setColor(const Color& c)
{
	this->color = c;
}
const Color& Shape::getColor() const
{
	return this->color;
}

bool Shape::isTransparant() const
{
	return this->color.alpha != 1.0f;
}