#include "Core/Rendering/Visualization/Manager/VisualizationFactory.h"

#include "Core/Rendering/Visualization/Shapes/CircleShapeVisualization.h"
#include "Core/Rendering/Visualization/Shapes/LineShapeVisualization.h"
#include "Core/Rendering/Visualization/Shapes/PolygonShapeVisualization.h"
#include "Core/Rendering/Visualization/Shapes/RectShapeVisualization.h"
#include "Core/Rendering/Visualization/Shapes/TriangleShapeVisualization.h"

#include "Core/Data/DataObjects/Shapes/CircleShape.h"
#include "Core/Data/DataObjects/Shapes/LineShape.h"
#include "Core/Data/DataObjects/Shapes/PolygonShape.h"
#include "Core/Data/DataObjects/Shapes/RectShape.h"
#include "Core/Data/DataObjects/Shapes/TriangleShape.h"

#include "SceneGraph/GameObjects/GameObject.h"
#include "SceneGraph/Component/Component.h"

#include "Interfaces\IRenderable.h"

VisualizationFactory::VisualizationFactory()
{

}
VisualizationFactory::~VisualizationFactory()
{

}

Visualization* VisualizationFactory::createVisualization(GameObject* object)
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

		if (object->getTypeId() == CircleShape::getClassTypeId())
		{
			root->addVisualizationChildNode(new CircleShapeVisualization(object));
		}
		else if (object->getTypeId() == LineShape::getClassTypeId())
		{
			root->addVisualizationChildNode(new LineShapeVisualization(object));
		}
		else if (object->getTypeId() == PolygonShape::getClassTypeId())
		{
			root->addVisualizationChildNode(new PolygonShapeVisualization(object));
		}
		else if (object->getTypeId() == RectShape::getClassTypeId())
		{
			root->addVisualizationChildNode(new RectShapeVisualization(object));
		}
		else if (object->getTypeId() == TriangleShape::getClassTypeId())
		{
			root->addVisualizationChildNode(new TriangleShapeVisualization(object));
		}
	}

	return root;
}
