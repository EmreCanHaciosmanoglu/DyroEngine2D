#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/CircleShapeVisualization.h"
#include "Rendering/Objects/Visualization/GameObjectVisualizations/GameObjectVisualization.h"

#include "SceneGraph\Objects\GameObjects\SceneObject.h"
#include "SceneGraph\Objects\Components\Shapes\CircleShapeComponent.h"

#include "Rendering/Objects/RenderItems/Shapes/CircleShape.h"

#include "Core/Defines/assert.h"

CircleShapeVisualization::CircleShapeVisualization(Component* object, const std::tstring& name)
	:ShapeVisualization(object, name)
{
	CircleShapeComponent* component = dynamic_cast<CircleShapeComponent*>(object);
	if (component != nullptr)
		setShape(new CircleShape(component->getCircleDescription()));

	assert(getShape() != nullptr);
}
CircleShapeVisualization::~CircleShapeVisualization()
{
}

void CircleShapeVisualization::generateRenderItems(std::vector<RenderItem*>& items)
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