#include "Core/Rendering/Visualization/Shapes/ShapeVisualization.h"
#include "SceneGraph\Component\Shapes\ShapeComponent.h"

#include "Core/Data/Shapes/Shape.h"

ShapeVisualization::ShapeVisualization(Object* object, const std::tstring& name)
	:Visualization(object, name)
{

}
ShapeVisualization::~ShapeVisualization()
{

}

void ShapeVisualization::generateRenderItems(std::vector<RenderItem*>& items)
{
	ShapeComponent* component = dynamic_cast<ShapeComponent*>(getObject());
	if (component == nullptr)
		return;

	items.push_back(component->getShape());
}