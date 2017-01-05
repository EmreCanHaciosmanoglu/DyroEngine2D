#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/PolygonShapeVisualization.h"
#include "Rendering/Objects/Visualization/GameObjectVisualizations/GameObjectVisualization.h"

#include "SceneGraph\Objects\GameObjects\SceneObject.h"
#include "SceneGraph\Objects\Components\Shapes\PolygonShapeComponent.h"

#include "Rendering/Objects/RenderItems/Shapes/PolygonShape.h"

PolygonShapeVisualization::PolygonShapeVisualization(Component* object, const std::tstring& name)
	:ShapeVisualization(object, name)
{

}
PolygonShapeVisualization::~PolygonShapeVisualization()
{

}

void PolygonShapeVisualization::generateRenderItems(std::vector<RenderItem*>& items)
{
	PolygonShapeComponent* component = dynamic_cast<PolygonShapeComponent*>(getObject());
	if (component == nullptr)
		return;

	GameObjectVisualization* parent = dynamic_cast<GameObjectVisualization*>(getParent());

	PolygonShape* shape = new PolygonShape(component->getPolygonDescription());
	if (parent != nullptr)
	{
		SceneObject* parent_object = dynamic_cast<SceneObject*>(parent->getObject());

		shape->setTransform(parent->getTransform());
		shape->setLayer(parent_object->getLayer());
	}

	items.push_back(shape);
}