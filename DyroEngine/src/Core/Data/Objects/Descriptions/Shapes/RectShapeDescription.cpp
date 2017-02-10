#include "Core\Data\Objects\Descriptions\Shapes\RectShapeDescription.h"
#include "Core\Types\GeometryType.h"

RectShapeDescription::RectShapeDescription()
	:FillableShapeDescription(GeometryType::RECTANGLE_GEOMETRY)
	, rect(Rect2D())
{}
RectShapeDescription::RectShapeDescription(const RectShapeDescription& ref)
	: FillableShapeDescription(ref)
	, rect(ref.rect)
{}
RectShapeDescription::RectShapeDescription(double left, double top, double width, double height, bool fill, const Color& color, float lineWidth)
	: FillableShapeDescription(GeometryType::RECTANGLE_GEOMETRY, fill, color, lineWidth)
	, rect(left, top, left + width, top + height)
{}
RectShapeDescription::RectShapeDescription(const Vector2D& lefttop, const Vector2D& rightbottom, bool fill, const Color& color, float lineWidth)
	: FillableShapeDescription(GeometryType::RECTANGLE_GEOMETRY, fill, color, lineWidth)
	, rect(lefttop, rightbottom)
{}
RectShapeDescription::RectShapeDescription(const Rect2D& rect, bool fill, const Color& color, float lineWidth)
	: FillableShapeDescription(GeometryType::RECTANGLE_GEOMETRY, fill, color, lineWidth)
	, rect(rect)
{}
RectShapeDescription::~RectShapeDescription()
{}

bool RectShapeDescription::operator==(const RectShapeDescription& ref) const
{
	bool value = ShapeDescription::operator==(ref);
	if (value == false)
		return false;

	return getRect() == ref.getRect();
}
bool RectShapeDescription::operator!=(const RectShapeDescription& ref) const
{
	bool value = ShapeDescription::operator!=(ref);
	if (value == false)
		return false;

	return getRect() != ref.getRect();
}

RectShapeDescription& RectShapeDescription::operator=(const RectShapeDescription& ref)
{
	ShapeDescription::operator=(ref);

	setRect(ref.getRect());

	return *this;
}

void RectShapeDescription::setRect(const Rect2D& rect)
{
	this->rect = rect;
}
const Rect2D& RectShapeDescription::getRect() const
{
	return this->rect;
}