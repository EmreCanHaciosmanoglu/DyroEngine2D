#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/PolygonShapeVisualization.h"
#include "Rendering/Objects/Visualization/GameObjectVisualizations/GameObjectVisualization.h"

#include "SceneGraph\Objects\GameObjects\SceneObject.h"
#include "SceneGraph\Objects\Components\Shapes\PolygonShapeComponent.h"

#include "Rendering/Objects/RenderItems/Shapes/PolygonShape.h"

PolygonShapeVisualization::PolygonShapeVisualization(Component* object, const std::tstring& name)
	:ShapeVisualization(object, name)
{
	PolygonShapeComponent* component = dynamic_cast<PolygonShapeComponent*>(object);
	if (component != nullptr)
		setShape(new PolygonShape(this, component->getPolygonDescription()));

	assert(getShape() != nullptr);

	//Create the requested shape
	getShape()->create();
}
PolygonShapeVisualization::~PolygonShapeVisualization()
{

}

void PolygonShapeVisualization::generateRenderItems(std::vector<RenderItem*>& items)
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