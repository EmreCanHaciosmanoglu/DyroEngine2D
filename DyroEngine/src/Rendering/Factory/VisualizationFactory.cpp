#include "Rendering/Factory/VisualizationFactory.h"

#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/CircleShapeVisualization.h"
#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/LineShapeVisualization.h"
#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/PolygonShapeVisualization.h"
#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/RectShapeVisualization.h"
#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/TriangleShapeVisualization.h"
#include "Rendering/Objects/Visualization/ComponentVisualizations/EmitterComponentVisualization.h"
//#include "RenderingVisualization/ComponentVisualizations/ImageVisualization.h"
//#include "RenderingVisualization/ComponentVisualizations/TextVisualization.h"

#include "Rendering/Objects/Visualization/GameObjectVisualizations/GameObjectVisualization.h"

#include "SceneGraph\Objects/Components/Shapes/CircleShapeComponent.h"
#include "SceneGraph\Objects/Components/Shapes/LineShapeComponent.h"
#include "SceneGraph\Objects/Components/Shapes/PolygonShapeComponent.h"
#include "SceneGraph\Objects/Components/Shapes/RectShapeComponent.h"
#include "SceneGraph\Objects/Components/Shapes/TriangleShapeComponent.h"
#include "SceneGraph\Objects/Components/EmitterComponent.h"
//#include "SceneGraph\Objects\Components\ImageComponent.h"
//#include "SceneGraph\Objects\Components\TextComponent.h"

#include "SceneGraph\Objects\GameObjects\SceneObject.h"
#include "SceneGraph\Objects\GameObjects\GameObject.h"
#include "SceneGraph\Objects\Components\Component.h"

VisualizationFactory::VisualizationFactory()
{
}
VisualizationFactory::~VisualizationFactory()
{
}

Visualization* VisualizationFactory::createVisualization(GameObject* object, bool generateChildVisualizations)
{
	GameObjectVisualization* root = nullptr;

	//A normal game object will never have any visualization.
	//That's why we check if it's a scene object or not, if not; we don't need to go through all the steps to check if there are any visualizations.
	SceneObject* scene_object = dynamic_cast<SceneObject*>(object);
	if (scene_object == nullptr)
		return root;

	root = new GameObjectVisualization(scene_object);
	root->setRoot(true);

	std::vector<Component*> components;
	object->getComponents(components);

	for (Component* component : components)
	{
		Visualization* new_visualization = nullptr;

		if (component->getTypeId() == CircleShapeComponent::getClassTypeId())
		{
			new_visualization = new CircleShapeVisualization(component);
		}
		else if (component->getTypeId() == RectShapeComponent::getClassTypeId())
		{
			new_visualization = new RectShapeVisualization(component);
		}
		else if (component->getTypeId() == TriangleShapeComponent::getClassTypeId())
		{
			new_visualization = new TriangleShapeVisualization(component);
		}
		else if (component->getTypeId() == LineShapeComponent::getClassTypeId())
		{
			new_visualization = new LineShapeVisualization(component);
		}
		else if (component->getTypeId() == PolygonShapeComponent::getClassTypeId())
		{
			new_visualization = new PolygonShapeVisualization(component);
		}
		else if (component->getTypeId() == EmitterComponent::getClassTypeId())
		{
			new_visualization = new EmitterComponentVisualization(component);
		}
		//else if (component->getTypeId() == ImageComponent::getClassTypeId())
		//{
		//	root->addVisualizationChildNode(new ImageVisualization(component));
		//}
		//else if (component->getTypeId() == TextComponent::getClassTypeId())
		//{
		//	root->addVisualizationChildNode(new TextVisualization(component));
		//}

		if (new_visualization == nullptr)
			continue;

		root->addVisualizationChildNode(new_visualization);		
	}

	if (generateChildVisualizations)
	{
		std::vector<GameObject*> childeren;
		object->getChilderen(childeren);

		for (GameObject* child : childeren)
		{
			SceneObject* child_scene_object = dynamic_cast<SceneObject*>(child);
			if (child_scene_object == nullptr)
				continue;

			GameObjectVisualization* visualization = dynamic_cast<GameObjectVisualization*>(createVisualization(child_scene_object, child_scene_object->hasChilderen()));
			visualization->setRoot(false);

			root->addVisualizationChildNode(visualization);
		}
	}

	return root;
}