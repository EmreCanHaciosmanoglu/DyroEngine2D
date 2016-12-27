#include "Core/Rendering/Visualization/Objects//Shapes/RectShapeVisualization.h"
#include "Core/Rendering/Visualization/Objects/SceneObjectVisualization.h"

#include "SceneGraph\Component\Shapes\RectShapeComponent.h"

#include "Core/Data//Objects/Shapes/RectShape.h"

RectShapeVisualization::RectShapeVisualization(Component* object, const std::tstring& name)
	:ShapeVisualization(object, name)
{
}
RectShapeVisualization::~RectShapeVisualization()
{

}

void RectShapeVisualization::generateRenderItems(std::vector<RenderItem>& items)
{
	RectShapeComponent* component = dynamic_cast<RectShapeComponent*>(getObject());
	if (component == nullptr)
		return;

	SceneObjectVisualization* parent = dynamic_cast<SceneObjectVisualization*>(getParent());

	RectShape shape(component->getRectDescription());
	if (parent != nullptr)
		shape.setTransform(parent->getTransform());

	items.push_back(shape);
}