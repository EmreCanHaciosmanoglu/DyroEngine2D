#include "Rendering/Objects/RenderItems/Shapes/PolygonShape.h"

#include "Rendering/Renderer.h"

#include "Core/Defines/assert.h"

PolygonShape::PolygonShape(const std::tstring& name)
	:Shape(name)
{}
PolygonShape::PolygonShape(PolygonShapeDescription* description, const std::tstring& name)
	: Shape(description, name)
{
}
PolygonShape::~PolygonShape()
{}

void PolygonShape::render(Renderer* renderer)
{
	//Renderer cannot be null
	assert(renderer != nullptr);

	PolygonShapeDescription* desc = getPolygonShapeDescription();

	renderer->setColor(desc->getColor());

	desc->getFill()
		? renderer->fillPolygon(desc->getPoints())
		: renderer->drawPolygon(desc->getPoints(), desc->getClose(), desc->getLineWidth());
}

PolygonShapeDescription* PolygonShape::getPolygonShapeDescription() const
{
	return dynamic_cast<PolygonShapeDescription*>(getDescription());
}

//Rect2D PolygonShape::getBoundingBox() const
//{
//	std::vector<Vector2D>::const_iterator min_x_it = std::min_element(this->vec_points.begin(), this->vec_points.end(),
//		[](const Vector2D& v1, const Vector2D& v2)
//	{
//		return v1.x < v2.x;
//	});
//	std::vector<Vector2D>::const_iterator max_x_it = std::max_element(this->vec_points.begin(), this->vec_points.end(),
//		[](const Vector2D& v1, const Vector2D& v2)
//	{
//		return v1.x < v2.x;
//	});
//
//	std::vector<Vector2D>::const_iterator min_y_it = std::min_element(this->vec_points.begin(), this->vec_points.end(),
//		[](const Vector2D& v1, const Vector2D& v2)
//	{
//		return v1.y < v2.y;
//	});
//	std::vector<Vector2D>::const_iterator max_y_it = std::max_element(this->vec_points.begin(), this->vec_points.end(),
//		[](const Vector2D& v1, const Vector2D& v2)
//	{
//		return v1.y < v2.y;
//	});
//
//	Vector2D min_x = (*min_x_it);
//	Vector2D max_x = (*max_x_it);
//	Vector2D min_y = (*min_y_it);
//	Vector2D max_y = (*max_y_it);
//
//	Rect2D bounding_rect;
//
//	bounding_rect.left = 0;
//	bounding_rect.top = 0;
//	bounding_rect.right = max_x.x - min_x.x;
//	bounding_rect.bottom = max_y.y - min_y.y;
//
//	return bounding_rect;
//}