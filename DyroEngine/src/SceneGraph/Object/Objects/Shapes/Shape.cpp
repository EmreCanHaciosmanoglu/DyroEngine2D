#include "SceneGraph/Object/Objects/Shapes/Shape.h"

Shape::Shape()
	:color(1,1,1,1)
{}
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