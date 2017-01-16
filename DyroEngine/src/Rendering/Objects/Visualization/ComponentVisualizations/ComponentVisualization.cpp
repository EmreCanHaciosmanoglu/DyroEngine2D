#include "Rendering/Objects/Visualization/ComponentVisualizations/ComponentVisualization.h"
#include "Rendering\Manager\VisualizationManager.h"
#include "Rendering\Objects\RenderItems\RenderItem.h"

#include "SceneGraph\Objects\Components\Component.h"

#include "Math\Objects\Range.h"

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