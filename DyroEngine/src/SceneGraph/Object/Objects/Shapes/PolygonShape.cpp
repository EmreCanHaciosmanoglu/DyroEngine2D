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

Rect2D PolygonShape::getBoundingBox() const
{
	std::vector<Vector2D>::const_iterator minIt = std::min_element(this->vec_points.begin(), this->vec_points.end());
	std::vector<Vector2D>::const_iterator maxIt = std::max_element(this->vec_points.begin(), this->vec_points.end());

	Vector2D min = (*minIt);
	Vector2D max = (*maxIt);

	Rect2D bounding_rect;

	bounding_rect.left = 0;
	bounding_rect.top = 0;
	bounding_rect.right = max.x - min.x;
	bounding_rect.bottom = max.y - min.y;

	return bounding_rect;
}