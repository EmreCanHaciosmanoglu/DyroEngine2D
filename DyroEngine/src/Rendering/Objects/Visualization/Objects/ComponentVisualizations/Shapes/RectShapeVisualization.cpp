#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/RectShapeVisualization.h"
#include "Rendering/Objects/Visualization/GameObjectVisualizations/GameObjectVisualization.h"

#include "SceneGraph\Objects\GameObjects\SceneObject.h"
#include "SceneGraph\Objects\Components\Shapes\RectShapeComponent.h"

#include "Rendering/Objects/RenderItems/Shapes/RectShape.h"

RectShapeVisualization::RectShapeVisualization(Component* object, const std::tstring& name)
	:ShapeVisualization(object, name)
{
	RectShapeComponent* component = dynamic_cast<RectShapeComponent*>(object);
	if (component != nullptr)
		setShape(new RectShape(component->getRectDescription()));

	assert(getShape() != nullptr);
}
RectShapeVisualization::~RectShapeVisualization()
{

}

void RectShapeVisualization::generateRenderItems(std::vector<RenderItem*>& items)
{
	GameObjectVisualization* parent = dynamic_cast<GameObjectVisualization*>(getParent());
	if (parent != nullptr)
	{
		SceneObject* parent_object = dynamic_cast<SceneObject*>(parent->getObject());

		getShape()->setTransform(parent->getTransform());
		getShape()->setLayer(parent_object->getLayer());
	}

	items.push_back(getShape());
}