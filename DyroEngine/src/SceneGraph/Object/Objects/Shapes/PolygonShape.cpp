#include "SceneGraph/Object/Objects/Shapes/PolygonShape.h"

#include "Core/Rendering/Renderer.h"

#include "Defines/assert.h"

PolygonShape::PolygonShape(Vector2D* points, int size, bool close, float lineWidth)
	:PolygonShape(std::vector<Vector2D>(points,points + size),close,lineWidth)
{}
PolygonShape::PolygonShape(const std::vector<Vector2D>& vecPoints, bool close, float lineWidth)
	:vec_points(vecPoints)
	,close(close)
	,line_width(lineWidth)
{}
PolygonShape::~PolygonShape()
{}

void PolygonShape::render(Renderer* renderer)
{
	//Renderer cannot be null
	assert(renderer != nullptr);

	renderer->setColor(getColor());

	getFill()
		? renderer->fillPolygon(this->vec_points)
		: renderer->drawPolygon(this->vec_points, this->close, this->line_width);
}

void PolygonShape::setFill(bool fill)
{
	this->fill = fill;
}
bool PolygonShape::getFill() const
{
	return this->fill;
}