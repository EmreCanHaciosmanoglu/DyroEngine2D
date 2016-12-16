#include "Core/Rendering/Visualization/Shapes/RectShapeVisualization.h"
#include "SceneGraph\Component\Shapes\RectShapeComponent.h"

#include "Core/Data/Shapes/RectShape.h"

RectShapeVisualization::RectShapeVisualization(Object* object, const std::tstring& name)
	:ShapeVisualization(object, name)
{
}
RectShapeVisualization::~RectShapeVisualization()
{

}

Rect2D RectShapeVisualization::getBoundingBox() const
{
	return Rect2D::empty;
}

void RectShapeVisualization::generateRenderItems(std::vector<RenderItem>& items)
{
	RectShapeComponent* component = dynamic_cast<RectShapeComponent*>(getObject());
	if (component == nullptr)
		return;
}