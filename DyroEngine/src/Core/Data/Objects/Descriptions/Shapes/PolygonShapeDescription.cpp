#include "Core\Data\Objects\Descriptions\Shapes\PolygonShapeDescription.h"
#include "Core\Types\GeometryType.h"

PolygonShapeDescription::PolygonShapeDescription()
	:FillableShapeDescription(GeometryType::POLYGON_GEOMETRY)
	, vec_points(std::vector<Vector2D> { Vector2D(-0.5f, 0.0f),
		Vector2D(0.5f, -0.5f),
		Vector2D(0.5f, 0.5f)})
	, close(true)
{}
PolygonShapeDescription::PolygonShapeDescription(const PolygonShapeDescription& ref)
	:FillableShapeDescription(ref)
	, vec_points(ref.vec_points)
	, close(ref.close)
{}
PolygonShapeDescription::PolygonShapeDescription(Vector2D* points, unsigned int size, bool close, bool fill, const Color& color, float lineWidth)
	: FillableShapeDescription(GeometryType::POLYGON_GEOMETRY, fill, color, lineWidth)
	, vec_points(size, Vector2D())
	, close(close)
{
	for (unsigned int i = 0; i < size; ++i)
		vec_points[i] = points[i];
}
PolygonShapeDescription::PolygonShapeDescription(const std::vector<Vector2D>& vecPoints, bool close, bool fill, const Color& color, float lineWidth)
	:FillableShapeDescription(GeometryType::POLYGON_GEOMETRY, fill, color, lineWidth)
	, vec_points(vecPoints)
	, close(close)
{}
PolygonShapeDescription::~PolygonShapeDescription()
{}

bool PolygonShapeDescription::operator==(const PolygonShapeDescription& ref) const
{
	bool value = ShapeDescription::operator==(ref);
	if (value == false)
		return false;

	return getPoints() == ref.getPoints() && getClose() == ref.getClose();
}
bool PolygonShapeDescription::operator!=(const PolygonShapeDescription& ref) const
{
	bool value = ShapeDescription::operator!=(ref);
	if (value == false)
		return false;

	return getPoints() != ref.getPoints() || getClose() != ref.getClose();
}

PolygonShapeDescription& PolygonShapeDescription::operator=(const PolygonShapeDescription& ref)
{
	ShapeDescription::operator=(ref);

	setPoints(ref.getPoints());
	setClose(ref.getClose());

	return *this;
}

void PolygonShapeDescription::setPoints(const std::vector<Vector2D>& points)
{
	this->vec_points.clear();

	this->vec_points = points;
}
void PolygonShapeDescription::setPoints(Vector2D* points, unsigned int size)
{
	this->vec_points.clear();

	for (unsigned int i = 0; i < size; ++i)
		this->vec_points.push_back(points[i]);
}
void PolygonShapeDescription::setClose(bool close)
{
	this->close = close;
}

const std::vector<Vector2D>& PolygonShapeDescription::getPoints() const
{
	return this->vec_points;
}
bool PolygonShapeDescription::getClose() const
{
	return this->close;
}

float PolygonShapeDescription::getWidth() const
{
	std::vector<Vector2D> points = getPoints();

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
float PolygonShapeDescription::getHeight() const
{
	std::vector<Vector2D> points = getPoints();

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