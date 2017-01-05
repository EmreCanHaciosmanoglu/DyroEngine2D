#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/CircleShapeVisualization.h"
#include "Rendering/Objects/Visualization/GameObjectVisualizations/GameObjectVisualization.h"

#include "SceneGraph\Objects\GameObjects\SceneObject.h"
#include "SceneGraph\Objects\Components\Shapes\CircleShapeComponent.h"

#include "Rendering/Objects/RenderItems/Shapes/CircleShape.h"

CircleShapeVisualization::CircleShapeVisualization(Component* object, const std::tstring& name)
	:ShapeVisualization(object, name)
{
}
CircleShapeVisualization::~CircleShapeVisualization()
{
}

void CircleShapeVisualization::generateRenderItems(std::vector<RenderItem*>& items)
{
	CircleShapeComponent* component = dynamic_cast<CircleShapeComponent*>(getObject());
	if (component == nullptr)
		return;

	GameObjectVisualization* parent = dynamic_cast<GameObjectVisualization*>(getParent());

	CircleShape* shape = new CircleShape(component->getCircleDescription());
	if (parent != nullptr)
	{
		SceneObject* parent_object = dynamic_cast<SceneObject*>(parent->getObject());

		shape->setTransform(parent->getTransform());
		shape->setLayer(parent_object->getLayer());
	}

	items.push_back(shape);
}