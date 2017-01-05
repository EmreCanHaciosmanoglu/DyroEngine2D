#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/RectShapeVisualization.h"
#include "Rendering/Objects/Visualization/GameObjectVisualizations/GameObjectVisualization.h"

#include "SceneGraph\Objects\GameObjects\SceneObject.h"
#include "SceneGraph\Objects\Components\Shapes\RectShapeComponent.h"

#include "Rendering/Objects/RenderItems/Shapes/RectShape.h"

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

	GameObjectVisualization* parent = dynamic_cast<GameObjectVisualization*>(getParent());

	RectShape* shape = new RectShape(component->getRectDescription());
	if (parent != nullptr)
	{
		SceneObject* parent_object = dynamic_cast<SceneObject*>(parent->getObject());

		shape->setTransform(parent->getTransform());
		shape->setLayer(parent_object->getLayer());
	}

	items.push_back(shape);
}