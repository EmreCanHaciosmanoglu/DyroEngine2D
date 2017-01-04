#include "Core/Rendering/Visualization/Objects//Shapes/RectShapeVisualization.h"
#include "Core/Rendering/Visualization/Objects/SceneObjectVisualization.h"

#include "SceneGraph\GameObjects\SceneObject.h"
#include "SceneGraph\Component\Shapes\RectShapeComponent.h"

#include "Core/Data//Objects/Shapes/RectShape.h"

RectShapeVisualization::RectShapeVisualization(Component* object, const std::tstring& name)
	:ShapeVisualization(object, name)
{
}
RectShapeVisualization::~RectShapeVisualization()
{

}

void RectShapeVisualization::generateRenderItems(std::vector<RenderItem*>& items)
{
	RectShapeComponent* component = dynamic_cast<RectShapeComponent*>(getObject());
	if (component == nullptr)
		return;

	SceneObjectVisualization* parent = dynamic_cast<SceneObjectVisualization*>(getParent());

	RectShape* shape = new RectShape(component->getRectDescription());
	if (parent != nullptr)
	{
		SceneObject* parent_object = dynamic_cast<SceneObject*>(parent->getObject());

		shape->setTransform(parent->getTransform());
		shape->setLayer(parent_object->getLayer());
	}

	items.push_back(shape);
}