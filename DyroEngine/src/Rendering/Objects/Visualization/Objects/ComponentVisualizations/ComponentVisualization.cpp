#include "Rendering/Objects/Visualization/ComponentVisualizations/ComponentVisualization.h"
#include "Rendering\Manager\VisualizationManager.h"

#include "SceneGraph\Objects\Components\Component.h"

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