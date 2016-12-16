#include "Core/Rendering/Visualization/Manager/VisualizationFactory.h"

#include "Core/Rendering/Visualization/ShapeVisualization.h"

#include "SceneGraph\Component/Shapes/ShapeComponent.h"
#include "SceneGraph\Component\ImageComponent.h"

#include "SceneGraph\GameObjects\GameObject.h"
#include "SceneGraph\Component\Component.h"

#include "Interfaces\IRenderable.h"

#include "SceneGraph\GameObjects\SceneObject.h"
#include "SceneGraph/GameObjects/GameObject.h"

#include "SceneGraph/Component/Component.h"

#include "Interfaces\IRenderable.h"

VisualizationFactory::VisualizationFactory()
{

}
VisualizationFactory::~VisualizationFactory()
{

}

Visualization* VisualizationFactory::createVisualization(GameObject* object, bool generateChildVisualizations)
{
	Visualization* root = nullptr;

	//A normal game object will never have any visualization.
	//That's why we check if it's a scene object or not, if not we don't need to go through all the steps to check if there are any visualizations.
	SceneObject* scene_object = dynamic_cast<SceneObject*>(object);
	if (scene_object == nullptr)
		return root;

	root = new Visualization(object);

	for (Component* component : object->getComponents())
	{
		IRenderable* renderable = dynamic_cast<IRenderable*>(component);
		if (renderable == nullptr)
			continue;

		for (Component* component : object->getComponents())
		{
			IRenderable* renderable = dynamic_cast<IRenderable*>(component);
			if (renderable == nullptr)
				continue;

			if (component->getTypeId() == ShapeComponent::getClassTypeId())
			{
				root->addVisualizationChildNode(new ShapeVisualization(component));
			}
			else if (component->getTypeId() == ImageComponent::getClassTypeId())
			{
				//root->addVisualizationChildNode(new ImageVisualization(component));
			}
		}
	}

	if (generateChildVisualizations)
	{
		for (GameObject* child : object->getChilderen())
			root->addVisualizationChildNode(createVisualization(child, child->hasChilderen()));
	}

	return root;
}
