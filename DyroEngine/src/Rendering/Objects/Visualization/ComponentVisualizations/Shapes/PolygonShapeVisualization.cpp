#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/PolygonShapeVisualization.h"
#include "Rendering/Objects/Visualization/GameObjectVisualizations/GameObjectVisualization.h"
#include "Rendering/Objects/RenderItems/Shapes/PolygonShape.h"

#include "SceneGraph\Objects\GameObjects\SceneObject.h"
#include "SceneGraph\Objects\Components\Shapes\PolygonShapeComponent.h"
#include "SceneGraph\Objects\Scenes\Scene.h"

#include "Core\Data\Manager\GeometryManager.h"

PolygonShapeVisualization::PolygonShapeVisualization(Component* object, const std::tstring& name)
	:ShapeVisualization(object, name)
{
}
PolygonShapeVisualization::~PolygonShapeVisualization()
{
}

bool PolygonShapeVisualization::initialize()
{
	PolygonShapeComponent* component = dynamic_cast<PolygonShapeComponent*>(getObject());
	if (component == nullptr)
		return false;

	PolygonShapeDescription* description = component->getPolygonDescription();
	Geometry* geometry = getScene()->getManager<GeometryManager>()->getGeometry(description);

	setShape(new PolygonShape(description, geometry));

	assert(getShape() != nullptr);

	return true;
}
bool PolygonShapeVisualization::shutdown()
{
	return true;
}

void PolygonShapeVisualization::generateRenderItems(std::vector<RenderItem*>& items)
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