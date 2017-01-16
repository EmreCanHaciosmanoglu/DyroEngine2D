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

bool RectShapeVisualization::initialize()
{
	RectShapeComponent* component = dynamic_cast<RectShapeComponent*>(getObject());
	if (component != nullptr)
		setShape(new RectShape(this, component->getRectDescription()));

	assert(getShape() != nullptr);

	//Create the requested shape
	getShape()->create();

	return true;
}
bool RectShapeVisualization::shutdown()
{
	return true;
}

void RectShapeVisualization::generateRenderItems(std::vector<RenderItem*>& items)
{
	GameObjectVisualization* parent = dynamic_cast<GameObjectVisualization*>(getParent());
	if (parent != nullptr)
	{
		SceneObject* parent_object = dynamic_cast<SceneObject*>(parent->getObject());

		getShape()->setTransform(parent->getPosition(), parent->getScale(), parent->getRotation());
		getShape()->setLayer(parent_object->getLayer());
	}

	items.push_back(getShape());
}