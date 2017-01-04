#include "Core/Rendering/Visualization/Objects//Shapes/PolygonShapeVisualization.h"
#include "Core/Rendering/Visualization/Objects/SceneObjectVisualization.h"

#include "SceneGraph\GameObjects\SceneObject.h"
#include "SceneGraph\Component\Shapes\PolygonShapeComponent.h"

#include "Core/Data/Objects/Shapes/PolygonShape.h"

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

	SceneObjectVisualization* parent = dynamic_cast<SceneObjectVisualization*>(getParent());

	PolygonShape* shape = new PolygonShape(component->getPolygonDescription());
	if (parent != nullptr)
	{
		SceneObject* parent_object = dynamic_cast<SceneObject*>(parent->getObject());

		shape->setTransform(parent->getTransform());
		shape->setLayer(parent_object->getLayer());
	}

	items.push_back(shape);
}