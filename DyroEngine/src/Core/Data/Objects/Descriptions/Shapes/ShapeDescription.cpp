#include "Core\Data\Objects\Descriptions\Shapes\ShapeDescription.h"

#include "Core\Defines\color.h"

ShapeDescription::ShapeDescription()
	:color(0,0,0,1)
	,line_width(0.5f)
{}
ShapeDescription::ShapeDescription(const ShapeDescription& ref)
	:color(ref.getColor())
	,line_width(ref.getLineWidth())
{}
ShapeDescription::ShapeDescription(const Color& color, float lineWidth)
	:color(color)
	,line_width(lineWidth)
{}
ShapeDescription::~ShapeDescription()
{}

bool ShapeDescription::operator==(const ShapeDescription& ref) const
{
	return this->getColor() == ref.getColor() && this->line_width == ref.line_width;
}
bool ShapeDescription::operator!=(const ShapeDescription& ref) const
{
	return this->getColor() != ref.getColor() || this->line_width != ref.line_width;
}

ShapeDescription& ShapeDescription::operator=(const ShapeDescription& ref)
{
	setColor(ref.getColor());
	setLineWidth(ref.getLineWidth());

	return *this;
}

void ShapeDescription::setColor(const Color& color)
{
	this->color = color;
}
void ShapeDescription::setLineWidth(float lineWidth)
{
	this->line_width = lineWidth;
}

const Color& ShapeDescription::getColor() const
{
	return this->color;
}
float ShapeDescription::getLineWidth() const
{
	return this->line_width;
}