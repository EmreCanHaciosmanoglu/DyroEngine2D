#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/LineShapeVisualization.h"
#include "Rendering/Objects/Visualization/GameObjectVisualizations/GameObjectVisualization.h"

#include "SceneGraph\Objects\GameObjects\SceneObject.h"
#include "SceneGraph\Objects\Components\Shapes\LineShapeComponent.h"

#include "Rendering/Objects/RenderItems/Shapes/LineShape.h"

LineShapeVisualization::LineShapeVisualization(Component* object, const std::tstring& name)
	:ShapeVisualization(object, name)
{
	LineShapeComponent* component = dynamic_cast<LineShapeComponent*>(object);
	if (component != nullptr)
		setShape(new LineShape(component->getLineDescription()));

	assert(getShape() != nullptr);
}
LineShapeVisualization::~LineShapeVisualization()
{

}

void LineShapeVisualization::generateRenderItems(std::vector<RenderItem*>& items)
{
	GameObjectVisualization* parent = dynamic_cast<GameObjectVisualization*>(getParent());
	if (parent != nullptr)
	{
		SceneObject* parent_object = dynamic_cast<SceneObject*>(parent->getObject());

		getShape()->setTransform(parent->getPosition(), parent->getScale(), parent->getRotation());
		getShape()->setLayer(parent_object->getLayer());
	}

	items.push_back(getShape());
}