#include "Core/Rendering/Visualization/Objects//Shapes/PolygonShapeVisualization.h"
#include "Core/Rendering/Visualization/Objects/SceneObjectVisualization.h"

#include "SceneGraph\Component\Shapes\PolygonShapeComponent.h"

#include "Core/Data/Objects/Shapes/PolygonShape.h"

PolygonShapeVisualization::PolygonShapeVisualization(Component* object, const std::tstring& name)
	:ShapeVisualization(object, name)
{

}
PolygonShapeVisualization::~PolygonShapeVisualization()
{

}

void PolygonShapeVisualization::generateRenderItems(std::vector<RenderItem>& items)
{
	PolygonShapeComponent* component = dynamic_cast<PolygonShapeComponent*>(getObject());
	if (component == nullptr)
		return;

	SceneObjectVisualization* parent = dynamic_cast<SceneObjectVisualization*>(getParent());

	PolygonShape shape(component->getPolygonDescription());
	if (parent != nullptr)
		shape.setTransform(parent->getTransform());

	items.push_back(shape);
}