#include "Core\Rendering\Visualization\Objects\ComponentVisualization.h"
#include "Core\Rendering\Visualization\Manager\VisualizationManager.h"

#include "SceneGraph\Component\Component.h"

ComponentVisualization::ComponentVisualization(Component* component, const std::tstring& name)
	:Visualization(component, name)
{}
ComponentVisualization::~ComponentVisualization()
{}

void ComponentVisualization::getRenderItems(std::vector<RenderItem*>& items)
{
	generateRenderItems(items);
}

Component* ComponentVisualization::getComponent() const
{
	return dynamic_cast<Component*>(getObject());
}