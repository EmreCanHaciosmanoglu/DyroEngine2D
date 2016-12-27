#include "Core\Data\Objects\Descriptions\Shapes\LineShapeDescription.h"

LineShapeDescription::LineShapeDescription()
	:ShapeDescription()
	,v1(0,0)
	,v2(0,0)
{}
LineShapeDescription::LineShapeDescription(const LineShapeDescription& ref)
	:ShapeDescription(ref)
	,v1(ref.v1)
	,v2(ref.v2)
{}
LineShapeDescription::LineShapeDescription(float x1, float y1, float x2, float y2, float lineWidth = 0.5f)
	:ShapeDescription(Color(),lineWidth)
	,v1(x1,y1)
	,v2(x2,y2)
{}
LineShapeDescription::LineShapeDescription(const Vector2D& v1, const Vector2D& v2, float lineWidth = 0.5f)
	:ShapeDescription(Color(),lineWidth)
	,v1(v1)
	,v2(v2)
{}
LineShapeDescription::~LineShapeDescription()
{}

bool LineShapeDescription::operator==(const LineShapeDescription& ref) const
{
	bool value = ShapeDescription::operator==(ref);
	if (value == false)
		return false;

	return getStartPosition() == ref.getStartPosition() && getEndPosition() == ref.getEndPosition();
}
bool LineShapeDescription::operator!=(const LineShapeDescription& ref) const
{
	bool value = ShapeDescription::operator!=(ref);
	if (value == false)
		return false;

	return getStartPosition() != ref.getStartPosition() || getEndPosition() != ref.getEndPosition();
}

LineShapeDescription& LineShapeDescription::operator=(const LineShapeDescription& ref)
{
	ShapeDescription::operator=(ref);

	setStartPosition(ref.getStartPosition());
	setEndPosition(ref.getEndPosition());

	return *this;
}

void LineShapeDescription::setStartPosition(const Vector2D& start)
{
	this->v1 == start;
}
void LineShapeDescription::setEndPosition(const Vector2D& end)
{
	this->v2 = end;
}

const Vector2D& LineShapeDescription::getStartPosition() const
{
	return this->v1;
}
const Vector2D& LineShapeDescription::getEndPosition() const
{
	return this->v2;
}