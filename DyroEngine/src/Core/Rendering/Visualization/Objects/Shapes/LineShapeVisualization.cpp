#include "Core/Rendering/Visualization/Objects//Shapes/LineShapeVisualization.h"
#include "Core/Rendering/Visualization/Objects/SceneObjectVisualization.h"

#include "SceneGraph\Component\Shapes\LineShapeComponent.h"

#include "Core/Data/Objects/Shapes/LineShape.h"

LineShapeVisualization::LineShapeVisualization(Component* object, const std::tstring& name)
	:ShapeVisualization(object, name)
{

}
LineShapeVisualization::~LineShapeVisualization()
{

}

void LineShapeVisualization::generateRenderItems(std::vector<RenderItem>& items)
{
	LineShapeComponent* component = dynamic_cast<LineShapeComponent*>(getObject());
	if (component == nullptr)
		return;

	SceneObjectVisualization* parent = dynamic_cast<SceneObjectVisualization*>(getParent());

	LineShape shape(component->getLineDescription());
	if (parent != nullptr)
		shape.setTransform(parent->getTransform());

	items.push_back(shape);
}