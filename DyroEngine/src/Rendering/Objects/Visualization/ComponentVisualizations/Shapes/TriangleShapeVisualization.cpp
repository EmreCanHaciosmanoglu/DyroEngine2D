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

bool TriangleShapeVisualization::initialize()
{
	TriangleShapeComponent* component = dynamic_cast<TriangleShapeComponent*>(getObject());
	if (component != nullptr)
		setShape(new TriangleShape(this, component->getTriangleDescription()));

	assert(getShape() != nullptr);

	//Create the requested shape
	getShape()->create();

	return true;
}
bool TriangleShapeVisualization::shutdown()
{
	return true;
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