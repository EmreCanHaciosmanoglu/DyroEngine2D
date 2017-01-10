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
Rect2D ComponentVisualization::getBoundingBox()
{
	std::vector<RenderItem*> items;
	getRenderItems(items);

	RangeVector2D range;

	for (RenderItem* item : items)
	{
		if (range.min_value > item->getPosition())
			range.min_value = item->getPosition();
		if (range.min_value < item->getPosition())
			range.max_value = item->getPosition();
	}

	Rect2D bounds;

	bounds.left = range.min_value.x;
	bounds.top = range.min_value.y;
	bounds.right = range.max_value.x;
	bounds.bottom = range.max_value.y;

	return bounds;
}

Component* ComponentVisualization::getComponent() const
{
	return dynamic_cast<Component*>(getObject());
}