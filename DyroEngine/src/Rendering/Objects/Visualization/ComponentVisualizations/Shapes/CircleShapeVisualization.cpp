#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/CircleShapeVisualization.h"
#include "Rendering/Objects/Visualization/GameObjectVisualizations/GameObjectVisualization.h"

#include "SceneGraph\Objects\GameObjects\SceneObject.h"
#include "SceneGraph\Objects\Components\Shapes\CircleShapeComponent.h"

#include "Rendering/Objects/RenderItems/Shapes/CircleShape.h"

#include "Core/Defines/assert.h"

CircleShapeVisualization::CircleShapeVisualization(Component* object, const std::tstring& name)
	:ShapeVisualization(object, name)
{

}
CircleShapeVisualization::~CircleShapeVisualization()
{
}

bool CircleShapeVisualization::initialize()
{
	CircleShapeComponent* component = dynamic_cast<CircleShapeComponent*>(getObject());
	if (component != nullptr)
		setShape(new CircleShape(this, component->getCircleDescription()));

	assert(getShape() != nullptr);

	//Create the requested shape
	getShape()->create();

	return true;
}
bool CircleShapeVisualization::shutdown()
{
	return true;
}

void CircleShapeVisualization::generateRenderItems(std::vector<RenderItem*>& items)
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