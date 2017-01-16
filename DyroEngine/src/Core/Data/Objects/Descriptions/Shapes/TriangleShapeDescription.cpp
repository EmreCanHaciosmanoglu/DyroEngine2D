#include "Core\Data\Objects\Descriptions\Shapes\TriangleShapeDescription.h"
#include "Core\Types\GeometryType.h"

TriangleShapeDescription::TriangleShapeDescription()
	:PolygonShapeDescription(GeometryType::TRIANGLE_GEOMETRY, std::vector<Vector2D> { Vector2D(-1.0f, 0.0f), 
														Vector2D(1.0f, -1.0f),
														Vector2D(1.0f, 1.0f)})
	,x_scale(1.0f)
	,y_scale(1.0f)
{}
TriangleShapeDescription::TriangleShapeDescription(const TriangleShapeDescription& ref)
	:PolygonShapeDescription(ref)
	,x_scale(ref.x_scale)
	,y_scale(ref.y_scale)
{}
TriangleShapeDescription::TriangleShapeDescription(float xScale, float yScale, bool fill, const Color& color, float lineWidth)
	: PolygonShapeDescription(GeometryType::TRIANGLE_GEOMETRY, std::vector<Vector2D> { Vector2D(-1.0f * xScale, 0.0f),
		Vector2D(1.0f * xScale, -1.0f * yScale),
		Vector2D(1.0f * xScale, 1.0f * yScale)}, true, fill, color, lineWidth)
	, x_scale(xScale)
	, y_scale(yScale)
{}
TriangleShapeDescription::~TriangleShapeDescription()
{}

bool TriangleShapeDescription::operator==(const TriangleShapeDescription& ref) const
{
	bool value = PolygonShapeDescription::operator==(ref);
	if (value == false)
		return false;

	return getXScale() == ref.getXScale() && getYScale() == ref.getYScale();
}
bool TriangleShapeDescription::operator!=(const TriangleShapeDescription& ref) const
{
	bool value = PolygonShapeDescription::operator!=(ref);
	if (value == false)
		return false;

	return getXScale() != ref.getXScale() || getYScale() != ref.getYScale();
}

TriangleShapeDescription& TriangleShapeDescription::operator=(const TriangleShapeDescription& ref)
{
	PolygonShapeDescription::operator=(ref);

	setXScale(ref.getXScale());
	setYScale(ref.getYScale());

	return *this;
}

void TriangleShapeDescription::setXScale(float scale)
{
	this->x_scale = scale;
}
void TriangleShapeDescription::setYScale(float scale)
{
	this->y_scale = scale;
}

float TriangleShapeDescription::getXScale() const
{
	return this->x_scale;
}
float TriangleShapeDescription::getYScale() const
{
	return this->y_scale;
}