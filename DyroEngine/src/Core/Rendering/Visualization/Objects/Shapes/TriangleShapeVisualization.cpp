#include "Core/Rendering/Visualization/Objects/Shapes/TriangleShapeVisualization.h"
#include "Core/Rendering/Visualization/Objects/SceneObjectVisualization.h"

#include "SceneGraph\GameObjects\SceneObject.h"
#include "SceneGraph\Component\Shapes\TriangleShapeComponent.h"

#include "Core/Data/Objects/Shapes/TriangleShape.h"

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

	SceneObjectVisualization* parent = dynamic_cast<SceneObjectVisualization*>(getParent());

	TriangleShape* shape = new TriangleShape(component->getTriangleDescription());
	if (parent != nullptr)
	{
		SceneObject* parent_object = dynamic_cast<SceneObject*>(parent->getObject());

		shape->setTransform(parent->getTransform());
		shape->setLayer(parent_object->getLayer());
	}

	items.push_back(shape);
}