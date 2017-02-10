#include "Core\Data\Objects\Descriptions\Shapes\FillableShapeDescription.h"

FillableShapeDescription::FillableShapeDescription(GeometryType type)
	:ShapeDescription(type)
	, fill(true)
{}
FillableShapeDescription::FillableShapeDescription(const FillableShapeDescription& ref)
	: ShapeDescription(ref)
	, fill(ref.fill)
{}
FillableShapeDescription::FillableShapeDescription(GeometryType type, bool fill, const Color& color, float lineWidth)
	: ShapeDescription(type, color, lineWidth)
	, fill(fill)
{}
FillableShapeDescription::~FillableShapeDescription()
{}

bool FillableShapeDescription::operator==(const FillableShapeDescription& ref) const
{
	ShapeDescription::operator==(ref);

	return getFill() == ref.getFill();
}
bool FillableShapeDescription::operator!=(const FillableShapeDescription& ref) const
{
	ShapeDescription::operator!=(ref);

	return getFill() != ref.getFill();
}

FillableShapeDescription& FillableShapeDescription::operator=(const FillableShapeDescription& ref)
{
	ShapeDescription::operator=(ref);

	setFill(ref.getFill());

	return *this;
}

void FillableShapeDescription::setFill(bool fill)
{
	this->fill = fill;
}
bool FillableShapeDescription::getFill() const
{
	return this->fill;
}