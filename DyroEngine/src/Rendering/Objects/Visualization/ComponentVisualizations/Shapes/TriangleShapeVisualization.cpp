#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/TriangleShapeVisualization.h"
#include "Rendering/Objects/Visualization/GameObjectVisualizations/GameObjectVisualization.h"

#include "SceneGraph\Objects\GameObjects\SceneObject.h"
#include "SceneGraph\Objects\Components\Shapes\TriangleShapeComponent.h"

#include "Rendering/Objects/RenderItems/Shapes/TriangleShape.h"

TriangleShapeVisualization::TriangleShapeVisualization(Component* object, const std::tstring& name)
	:PolygonShapeVisualization(object, name)
{
	TriangleShapeComponent* component = dynamic_cast<TriangleShapeComponent*>(object);
	if (component != nullptr)
		setShape(new TriangleShape(component->getTriangleDescription()));

	assert(getShape() != nullptr);
}
TriangleShapeVisualization::~TriangleShapeVisualization()
{

}

void TriangleShapeVisualization::generateRenderItems(std::vector<RenderItem*>& items)
{
	GameObjectVisualization* parent = dynamic_cast<GameObjectVisualization*>(getParent());
	if (parent != nullptr)
	{
		SceneObject* parent_object = dynamic_cast<SceneObject*>(parent->getObject());

		getShape()->setTransform(parent->getPosition(),parent->getScale(),parent->getRotation());
		getShape()->setLayer(parent_object->getLayer());
	}

	items.push_back(getShape());
}