#include "Core/Rendering/Visualization/Objects//Shapes/CircleShapeVisualization.h"
#include "Core/Rendering/Visualization/Objects/SceneObjectVisualization.h"

#include "SceneGraph\GameObjects\SceneObject.h"
#include "SceneGraph\Component\Shapes\CircleShapeComponent.h"

#include "Core/Data/Objects/Shapes/CircleShape.h"

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

	SceneObjectVisualization* parent = dynamic_cast<SceneObjectVisualization*>(getParent());

	CircleShape* shape = new CircleShape(component->getCircleDescription());
	if (parent != nullptr)
	{
		SceneObject* parent_object = dynamic_cast<SceneObject*>(parent->getObject());

		shape->setTransform(parent->getTransform());
		shape->setLayer(parent_object->getLayer());
	}

	items.push_back(shape);
}