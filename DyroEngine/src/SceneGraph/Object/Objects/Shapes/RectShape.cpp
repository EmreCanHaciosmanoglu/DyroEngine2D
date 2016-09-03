#include "SceneGraph/Object/Objects/Shapes/RectShape.h"

#include "Core/Rendering/Renderer.h"

#include "Defines/assert.h"

RectShape::RectShape(double left, double top, double width, double height, float lineWidth)
	:RectShape(Rect2D(left, top, left + width, top + height), lineWidth)
{}
RectShape::RectShape(const Vector2D& lefttop, const Vector2D& rightbottom, float lineWidth)
	: RectShape(Rect2D(lefttop, rightbottom), lineWidth)
{}
RectShape::RectShape(const Rect2D& rect, float lineWidth)
	:rect(rect)
	,line_width(lineWidth)
{}
RectShape::~RectShape()
{}

void RectShape::render(Renderer* renderer)
{
	//Renderer cannot be null
	assert(renderer != nullptr);

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