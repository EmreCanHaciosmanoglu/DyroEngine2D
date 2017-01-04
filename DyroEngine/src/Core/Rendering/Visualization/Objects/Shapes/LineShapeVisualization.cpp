#include "Core/Rendering/Visualization/Objects//Shapes/LineShapeVisualization.h"
#include "Core/Rendering/Visualization/Objects/SceneObjectVisualization.h"

#include "SceneGraph\GameObjects\SceneObject.h"
#include "SceneGraph\Component\Shapes\LineShapeComponent.h"

#include "Core/Data/Objects/Shapes/LineShape.h"

LineShapeVisualization::LineShapeVisualization(Component* object, const std::tstring& name)
	:ShapeVisualization(object, name)
{

}
LineShapeVisualization::~LineShapeVisualization()
{

}

void LineShapeVisualization::generateRenderItems(std::vector<RenderItem*>& items)
{
	LineShapeComponent* component = dynamic_cast<LineShapeComponent*>(getObject());
	if (component == nullptr)
		return;

	SceneObjectVisualization* parent = dynamic_cast<SceneObjectVisualization*>(getParent());

	LineShape* shape = new LineShape(component->getLineDescription());
	if (parent != nullptr)
	{
		SceneObject* parent_object = dynamic_cast<SceneObject*>(parent->getObject());

		shape->setTransform(parent->getTransform());
		shape->setLayer(parent_object->getLayer());
	}

	items.push_back(shape);
}