#include "Core/Rendering/Visualization/Factory/VisualizationFactory.h"

#include "Core/Rendering/Visualization/Objects/Shapes/CircleShapeVisualization.h"
#include "Core/Rendering/Visualization/Objects/Shapes/LineShapeVisualization.h"
#include "Core/Rendering/Visualization/Objects/Shapes/PolygonShapeVisualization.h"
#include "Core/Rendering/Visualization/Objects/Shapes/RectShapeVisualization.h"
#include "Core/Rendering/Visualization/Objects/Shapes/TriangleShapeVisualization.h"
//#include "Core/Rendering/Visualization/ImageVisualization.h"
//#include "Core/Rendering/Visualization/TextVisualization.h"

#include "Core\Rendering\Visualization\Objects\SceneObjectVisualization.h"

#include "SceneGraph\Component/Shapes/CircleShapeComponent.h"
#include "SceneGraph\Component/Shapes/LineShapeComponent.h"
#include "SceneGraph\Component/Shapes/PolygonShapeComponent.h"
#include "SceneGraph\Component/Shapes/RectShapeComponent.h"
#include "SceneGraph\Component/Shapes/TriangleShapeComponent.h"
//#include "SceneGraph\Component\ImageComponent.h"
//#include "SceneGraph\Component\TextComponent.h"

#include "SceneGraph\GameObjects\SceneObject.h"
#include "SceneGraph\GameObjects\GameObject.h"
#include "SceneGraph\Component\Component.h"

#include "Interfaces\IRenderable.h"

VisualizationFactory::VisualizationFactory()
{
}
VisualizationFactory::~VisualizationFactory()
{
}

Visualization* VisualizationFactory::createVisualization(GameObject* object, bool generateChildVisualizations)
{
	SceneObjectVisualization* root = nullptr;

	//A normal game object will never have any visualization.
	//That's why we check if it's a scene object or not, if not; we don't need to go through all the steps to check if there are any visualizations.
	SceneObject* scene_object = dynamic_cast<SceneObject*>(object);
	if (scene_object == nullptr)
		return root;

	root = new SceneObjectVisualization(scene_object);
	root->setRoot(true);

	std::vector<Component*> components;
	object->getComponents(components);

	for (Component* component : components)
	{
		if (component->getTypeId() == CircleShapeComponent::getClassTypeId())
		{
			root->addVisualizationChildNode(new CircleShapeVisualization(component));
		}
		else if (component->getTypeId() == RectShapeComponent::getClassTypeId())
		{
			root->addVisualizationChildNode(new RectShapeVisualization(component));
		}
		else if (component->getTypeId() == PolygonShapeComponent::getClassTypeId())
		{
			root->addVisualizationChildNode(new PolygonShapeVisualization(component));
		}
		else if (component->getClassTypeId() == TriangleShapeComponent::getClassTypeId())
		{
			root->addVisualizationChildNode(new TriangleShapeVisualization(component));
		}
		else if (component->getClassTypeId() == LineShapeComponent::getClassTypeId())
		{
			root->addVisualizationChildNode(new LineShapeVisualization(component));
		}
		//else if (component->getTypeId() == ImageComponent::getClassTypeId())
		//{
		//	root->addVisualizationChildNode(new ImageVisualization(component));
		//}
		//else if (component->getTypeId() == TextComponent::getClassTypeId())
		//{
		//	root->addVisualizationChildNode(new TextVisualization(component));
		//}
	}

	if (generateChildVisualizations)
	{
		std::vector<GameObject*> childeren;
		object->getChilderen(childeren);

		for (GameObject* child : childeren)
		{
			SceneObject* child_scene_object = dynamic_cast<SceneObject*>(object);
			if (child_scene_object == nullptr)
				continue;

			SceneObjectVisualization* visualization = dynamic_cast<SceneObjectVisualization*>(createVisualization(child_scene_object, child_scene_object->hasChilderen()));
			visualization->setRoot(false);

			root->addVisualizationChildNode(visualization);
		}
	}

	return root;
}