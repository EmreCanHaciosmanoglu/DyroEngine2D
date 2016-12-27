#include "Core/Rendering/Visualization/Objects/Shapes/TriangleShapeVisualization.h"
#include "Core/Rendering/Visualization/Objects/SceneObjectVisualization.h"

#include "SceneGraph\Component\Shapes\TriangleShapeComponent.h"

#include "Core/Data/Objects/Shapes/TriangleShape.h"

TriangleShapeVisualization::TriangleShapeVisualization(Component* object, const std::tstring& name)
	:PolygonShapeVisualization(object, name)
{

}
TriangleShapeVisualization::~TriangleShapeVisualization()
{

}

void TriangleShapeVisualization::generateRenderItems(std::vector<RenderItem>& items)
{
	TriangleShapeComponent* component = dynamic_cast<TriangleShapeComponent*>(getObject());
	if (component == nullptr)
		return;

	SceneObjectVisualization* parent = dynamic_cast<SceneObjectVisualization*>(getParent());

	TriangleShape shape(component->getTriangleDescription());
	if (parent != nullptr)
		shape.setTransform(parent->getTransform());

	items.push_back(shape);
}