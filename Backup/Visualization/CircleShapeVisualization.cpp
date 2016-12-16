#include "Core/Rendering/Visualization/Shapes/CircleShapeVisualization.h"
#include "SceneGraph\Component\Shapes\CircleShapeComponent.h"

#include "Core/Data/Shapes/CircleShape.h"

CircleShapeVisualization::CircleShapeVisualization(Object* object, const std::tstring& name)
	:ShapeVisualization(object, name)
{
}
CircleShapeVisualization::~CircleShapeVisualization()
{
}

Rect2D CircleShapeVisualization::getBoundingBox() const
{
	return Rect2D::empty;
}

void CircleShapeVisualization::generateRenderItems(std::vector<RenderItem>& items)
{
	CircleShapeComponent* component = dynamic_cast<CircleShapeComponent*>(getObject());
	if (component == nullptr)
		return;
}