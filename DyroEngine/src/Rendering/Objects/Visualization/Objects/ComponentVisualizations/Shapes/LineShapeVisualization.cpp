#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/LineShapeVisualization.h"
#include "Rendering/Objects/Visualization/GameObjectVisualizations/GameObjectVisualization.h"

#include "SceneGraph\Objects\GameObjects\SceneObject.h"
#include "SceneGraph\Objects\Components\Shapes\LineShapeComponent.h"

#include "Rendering/Objects/RenderItems/Shapes/LineShape.h"

LineShapeVisualization::LineShapeVisualization(Component* object, const std::tstring& name)
	:ShapeVisualization(object, name)
{

}
LineShapeVisualization::~LineShapeVisualization()
{

}

void LineShapeVisualization::generateRenderItems(std::vector<RenderItem*>& items)
{
	LineShapeComponent* component = dynamic_cast<LineShapeComponent*>(getObject());
	if (component == nullptr)
		return;

	GameObjectVisualization* parent = dynamic_cast<GameObjectVisualization*>(getParent());

	LineShape* shape = new LineShape(component->getLineDescription());
	if (parent != nullptr)
	{
		SceneObject* parent_object = dynamic_cast<SceneObject*>(parent->getObject());

		shape->setTransform(parent->getTransform());
		shape->setLayer(parent_object->getLayer());
	}

	items.push_back(shape);
}