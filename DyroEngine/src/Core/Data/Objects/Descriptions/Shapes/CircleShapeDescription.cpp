#include "Core\Data\Objects\Descriptions\Shapes\CircleShapeDescription.h"

CircleShapeDescription::CircleShapeDescription()
	:FillableShapeDescription()
	,center(0,0)
	,radius(1.0f)
{}
CircleShapeDescription::CircleShapeDescription(const CircleShapeDescription& ref)
	: FillableShapeDescription(ref)
	,center(ref.getCenter())
	,radius(ref.getRadius())
{}
CircleShapeDescription::CircleShapeDescription(float xcenter, float ycenter, float r, bool fill, float lineWidth)
	: FillableShapeDescription(fill,lineWidth)
	,center(xcenter,ycenter)
	,radius(r)
{}
CircleShapeDescription::CircleShapeDescription(const Vector2D& center, float r, bool fill, float lineWidth)
	: FillableShapeDescription(fill, lineWidth)
	,center(center)
	,radius(r)
{}
CircleShapeDescription::~CircleShapeDescription()
{}

bool CircleShapeDescription::operator==(const CircleShapeDescription& ref) const
{
	bool value = ShapeDescription::operator==(ref);
	if (value == false)
		return false;

	return getCenter() == ref.getCenter() && getRadius() == ref.getRadius();
}
bool CircleShapeDescription::operator!=(const CircleShapeDescription& ref) const
{
	bool value = ShapeDescription::operator!=(ref);
	if (value == false)
		return false;

	return getCenter() != ref.getCenter() || getRadius() != ref.getRadius();
}

CircleShapeDescription& CircleShapeDescription::operator=(const CircleShapeDescription& ref)
{
	ShapeDescription::operator=(ref);

	setCenter(ref.getCenter());
	setRadius(ref.getRadius());

	return *this;
}

void CircleShapeDescription::setCenter(const Vector2D& center)
{
	this->center = center;
}
void CircleShapeDescription::setRadius(float radius)
{
	this->radius = radius;
}

const Vector2D& CircleShapeDescription::getCenter() const
{
	return this->center;
}
float CircleShapeDescription::getRadius() const
{
	return this->radius;
}