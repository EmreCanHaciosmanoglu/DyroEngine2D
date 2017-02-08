#include "Rendering/Objects/RenderItems/Shapes/PolygonShape.h"
#include "Rendering/Objects/Visualization/Visualization.h"

#include "Core\Data/Manager/GeometryManager.h"

#include "Rendering/Renderer.h"

#include "Core/System/Objects/Graphics.h"

#include "Core/Defines/assert.h"
#include "Core/Defines/d2dutill.h"
#include "Core/Defines/deletemacros.h"

#include "SceneGraph\Objects\Scenes\Scene.h"

PolygonShape::PolygonShape(const std::tstring& name)
	:Shape(name)
{}
PolygonShape::PolygonShape(PolygonShapeDescription* description, Geometry* geometry, const std::tstring& name)
	: Shape(description, geometry, name)
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
		? renderer->fillGeometry(this->geometry)
		: renderer->drawGeometry(this->geometry, desc->getLineWidth());
}

float PolygonShape::getWidth() const
{
	std::vector<Vector2D> points = getPolygonShapeDescription()->getPoints();

	std::vector<Vector2D>::const_iterator min_x_it = std::min_element(points.begin(), points.end(),
		[](const Vector2D& v1, const Vector2D& v2)
	{
		return v1.x < v2.x;
	});
	std::vector<Vector2D>::const_iterator max_x_it = std::max_element(points.begin(), points.end(),
		[](const Vector2D& v1, const Vector2D& v2)
	{
		return v1.x < v2.x;
	});

	Vector2D min_x = (*min_x_it);
	Vector2D max_x = (*max_x_it);

	return max_x.x - min_x.x;
}
float PolygonShape::getHeight() const
{
	std::vector<Vector2D> points = getPolygonShapeDescription()->getPoints();

	std::vector<Vector2D>::const_iterator min_y_it = std::min_element(points.begin(), points.end(),
		[](const Vector2D& v1, const Vector2D& v2)
	{
		return v1.y < v2.y;
	});
	std::vector<Vector2D>::const_iterator max_y_it = std::max_element(points.begin(), points.end(),
		[](const Vector2D& v1, const Vector2D& v2)
	{
		return v1.y < v2.y;
	});

	Vector2D min_y = (*min_y_it);
	Vector2D max_y = (*max_y_it);

	return max_y.y - min_y.y;
}

PolygonShapeDescription* PolygonShape::getPolygonShapeDescription() const
{
	return dynamic_cast<PolygonShapeDescription*>(getDescription());
}