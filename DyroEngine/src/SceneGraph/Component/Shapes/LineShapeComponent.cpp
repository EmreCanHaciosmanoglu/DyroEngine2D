#include "SceneGraph\Component\Shapes\LineShapeComponent.h"
#include "Core\Data\Objects\Descriptions\Shapes\LineShapeDescription.h"

LineShapeComponent::LineShapeComponent(LineShapeDescription* description, const std::tstring& name)
	:ShapeComponent(description, name)
{
	OBJECT_INIT(_T("LineShapeComponent"));
}
LineShapeComponent::~LineShapeComponent()
{}

void LineShapeComponent::setStartPosition(const Vector2D& start)
{
	getLineDescription()->setStartPosition(start);
}
void LineShapeComponent::setEndPosition(const Vector2D& end)
{
	getLineDescription()->setEndPosition(end);
}

const Vector2D& LineShapeComponent::getStartPosition() const
{
	return getLineDescription()->getStartPosition();
}
const Vector2D& LineShapeComponent::getEndPosition() const
{
	return getLineDescription()->getEndPosition();
}

LineShapeDescription* LineShapeComponent::getLineDescription() const
{
	return dynamic_cast<LineShapeDescription*>(getDescription());
}