#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/TriangleShapeVisualization.h"
#include "Rendering/Objects/Visualization/GameObjectVisualizations/GameObjectVisualization.h"

#include "SceneGraph\Objects\GameObjects\SceneObject.h"
#include "SceneGraph\Objects\Components\Shapes\TriangleShapeComponent.h"

#include "Rendering/Objects/RenderItems/Shapes/TriangleShape.h"

TriangleShapeVisualization::TriangleShapeVisualization(Component* object, const std::tstring& name)
	:PolygonShapeVisualization(object, name)
{

}
TriangleShapeVisualization::~TriangleShapeVisualization()
{

}

void TriangleShapeVisualization::generateRenderItems(std::vector<RenderItem*>& items)
{
	TriangleShapeComponent* component = dynamic_cast<TriangleShapeComponent*>(getObject());
	if (component == nullptr)
		return;

	GameObjectVisualization* parent = dynamic_cast<GameObjectVisualization*>(getParent());

	TriangleShape* shape = new TriangleShape(component->getTriangleDescription());
	if (parent != nullptr)
	{
		SceneObject* parent_object = dynamic_cast<SceneObject*>(parent->getObject());

		shape->setTransform(parent->getTransform());
		shape->setLayer(parent_object->getLayer());
	}

	items.push_back(shape);
}