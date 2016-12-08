#include "SceneGraph/Object/DataObjects/Shapes/PolygonShape.h"

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
	std::vector<Vector2D>::const_iterator min_x_it = std::min_element(this->vec_points.begin(), this->vec_points.end(),
		[](const Vector2D& v1, const Vector2D& v2)
	{
		return v1.x < v2.x;
	});
	std::vector<Vector2D>::const_iterator max_x_it = std::max_element(this->vec_points.begin(), this->vec_points.end(),
		[](const Vector2D& v1, const Vector2D& v2)
	{
		return v1.x < v2.x;
	});

	std::vector<Vector2D>::const_iterator min_y_it = std::min_element(this->vec_points.begin(), this->vec_points.end(),
		[](const Vector2D& v1, const Vector2D& v2)
	{
		return v1.y < v2.y;
	});
	std::vector<Vector2D>::const_iterator max_y_it = std::max_element(this->vec_points.begin(), this->vec_points.end(),
		[](const Vector2D& v1, const Vector2D& v2)
	{
		return v1.y < v2.y;
	});

	Vector2D min_x = (*min_x_it);
	Vector2D max_x = (*max_x_it);
	Vector2D min_y = (*min_y_it);
	Vector2D max_y = (*max_y_it);

	Rect2D bounding_rect;

	bounding_rect.left = 0;
	bounding_rect.top = 0;
	bounding_rect.right = max_x.x - min_x.x;
	bounding_rect.bottom = max_y.y - min_y.y;

	return bounding_rect;
}