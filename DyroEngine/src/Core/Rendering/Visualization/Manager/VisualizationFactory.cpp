#include "Core/Rendering/Visualization/Manager/VisualizationFactory.h"

#include "Core/Rendering/Visualization/Shapes/CircleShapeVisualization.h"
#include "Core/Rendering/Visualization/Shapes/LineShapeVisualization.h"
#include "Core/Rendering/Visualization/Shapes/PolygonShapeVisualization.h"
#include "Core/Rendering/Visualization/Shapes/RectShapeVisualization.h"
#include "Core/Rendering/Visualization/Shapes/TriangleShapeVisualization.h"

#include "SceneGraph\Component/Shapes/CircleShapeComponent.h"
#include "SceneGraph\Component/Shapes/LineShapeComponent.h"
#include "SceneGraph\Component/Shapes/PolygonShapeComponent.h"
#include "SceneGraph\Component/Shapes/RectShapeComponent.h"
#include "SceneGraph\Component/Shapes/TriangleShapeComponent.h"

#include "SceneGraph\GameObjects\GameObject.h"
#include "SceneGraph\Component\Component.h"

#include "Interfaces\IRenderable.h"

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

	if (object == nullptr)
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

			if (component->getTypeId() == CircleShapeComponent::getClassTypeId())
			{
				root->addVisualizationChildNode(new CircleShapeVisualization(object));
			}
			else if (component->getTypeId() == LineShapeComponent::getClassTypeId())
			{
				root->addVisualizationChildNode(new LineShapeVisualization(object));
			}
			else if (component->getTypeId() == PolygonShapeComponent::getClassTypeId())
			{
				root->addVisualizationChildNode(new PolygonShapeVisualization(object));
			}
			else if (component->getTypeId() == RectShapeComponent::getClassTypeId())
			{
				root->addVisualizationChildNode(new RectShapeVisualization(object));
			}
			else if (component->getTypeId() == TriangleShapeComponent::getClassTypeId())
			{
				root->addVisualizationChildNode(new TriangleShapeVisualization(object));
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
