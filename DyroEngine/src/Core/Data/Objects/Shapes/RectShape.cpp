#include "Core/Data/Shapes/RectShape.h"

#include "Core/Rendering/Renderer.h"

#include "Defines/assert.h"

RectShape::RectShape(double left, double top, double width, double height, float lineWidth, const std::tstring& name)
	:RectShape(Rect2D(left, top, left + width, top + height), lineWidth, name)
{}
RectShape::RectShape(const Vector2D& lefttop, const Vector2D& rightbottom, float lineWidth, const std::tstring& name)
	: RectShape(Rect2D(lefttop, rightbottom), lineWidth, name)
{}
RectShape::RectShape(const Rect2D& rect, float lineWidth, const std::tstring& name)
	: Shape(name)
	, rect(rect)
	, line_width(lineWidth)
{
}
RectShape::~RectShape()
{}

void RectShape::render(Renderer* renderer)
{
	//Renderer cannot be null
	assert(renderer != nullptr);

	renderer->setColor(getColor());

	getFill()
		? renderer->fillRect(this->rect)
		: renderer->drawRect(this->rect, this->line_width);
}

void RectShape::setFill(bool fill)
{
	this->fill = fill;
}
bool RectShape::getFill() const
{
	return this->fill;
}

Rect2D RectShape::getBoundingBox() const
{
	Rect2D bounding_rect;

	bounding_rect.left = 0;
	bounding_rect.top = 0;
	bounding_rect.right = this->rect.right - this->rect.left;
	bounding_rect.bottom = this->rect.bottom - this->rect.top;

	return bounding_rect;
}