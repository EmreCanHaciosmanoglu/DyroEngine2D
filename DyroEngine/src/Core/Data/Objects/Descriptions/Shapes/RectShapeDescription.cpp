#include "Core\Data\Objects\Descriptions\Shapes\RectShapeDescription.h"

RectShapeDescription::RectShapeDescription()
	:ShapeDescription()
	,rect(Rect2D())
{}
RectShapeDescription::RectShapeDescription(const RectShapeDescription& ref)
	:ShapeDescription(ref)
	,rect(ref.rect)
{}
RectShapeDescription::RectShapeDescription(double left, double top, double width, double height, float lineWidth = 0.5f)
	:ShapeDescription(Color(),lineWidth)
	,rect(left,top,left + width, top + height)
{}
RectShapeDescription::RectShapeDescription(const Vector2D& lefttop, const Vector2D& rightbottom, float lineWidth = 0.5f)
	:ShapeDescription(Color(),lineWidth)
	,rect(lefttop, rightbottom)
{}
RectShapeDescription::RectShapeDescription(const Rect2D& rect, float lineWidth = 0.5f)
	:ShapeDescription(Color(),lineWidth)
	,rect(rect)
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