#include "Core/Data/DataObjects/Shapes/Shape.h"

Shape::Shape(const std::tstring& name)
	:GameObject(name)
	,color(1,1,1,1)
{
	DATA_OBJECT_INIT(_T("Shape"));
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