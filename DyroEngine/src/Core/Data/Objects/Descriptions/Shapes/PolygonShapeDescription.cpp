#include "Core\Data\Objects\Descriptions\Shapes\PolygonShapeDescription.h"
#include "Core\Types\GeometryType.h"

PolygonShapeDescription::PolygonShapeDescription(GeometryType type)
	:FillableShapeDescription(type)
	,vec_points(std::vector<Vector2D> { Vector2D(-0.5f, 0.0f),
		Vector2D(0.5f, -0.5f),
		Vector2D(0.5f, 0.5f)})
	,close(true)
{}
PolygonShapeDescription::PolygonShapeDescription(const PolygonShapeDescription& ref)
	:FillableShapeDescription(ref)
	,vec_points(ref.vec_points)
	,close(ref.close)
{}
PolygonShapeDescription::PolygonShapeDescription(GeometryType type, Vector2D* points, unsigned int size, bool close, bool fill, const Color& color, float lineWidth)
	: FillableShapeDescription(type,fill,color, lineWidth)
	,vec_points(size, Vector2D())
	,close(close)
{
	for (unsigned int i = 0; i < size; ++i)
		vec_points[i] = points[i];
}
PolygonShapeDescription::PolygonShapeDescription(GeometryType type, const std::vector<Vector2D>& vecPoints, bool close, bool fill, const Color& color, float lineWidth)
	:FillableShapeDescription(type, fill,color, lineWidth)
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