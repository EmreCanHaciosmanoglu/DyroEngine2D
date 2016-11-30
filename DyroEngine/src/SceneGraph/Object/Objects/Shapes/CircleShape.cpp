#include "SceneGraph/Object/Objects/Shapes/CircleShape.h"

#include "Core/Rendering/Renderer.h"

#include "Defines/assert.h"

CircleShape::CircleShape(float xcenter, float ycenter, float r, float lineWidth)
	:CircleShape(Vector2D(xcenter,ycenter),r,lineWidth)
{}
CircleShape::CircleShape(const Vector2D& center, float r, float lineWidth)
	:center(center)
	,radius(r)
	,line_width(lineWidth)
{}
CircleShape::~CircleShape()
{}

void CircleShape::render(Renderer* renderer)
{
	//Renderer cannot be null
	assert(renderer != nullptr);

	renderer->setColor(getColor());

	getFill()
		? renderer->fillCircle(this->center, this->radius)
		: renderer->drawCircle(this->center, this->radius, this->line_width);
}

void CircleShape::setFill(bool fill)
{
	this->fill = fill;
}
bool CircleShape::getFill() const
{
	return this->fill;
}

Rect2D CircleShape::getBoundingBox() const
{
	Rect2D bounding_rect;

	bounding_rect.left = 0;
	bounding_rect.top = 0;
	bounding_rect.right = this->radius * 2;
	bounding_rect.bottom = this->radius * 2;

	return bounding_rect;
}