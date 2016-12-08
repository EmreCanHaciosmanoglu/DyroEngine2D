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

VisualizationFactory::VisualizationFactory()
{

}
VisualizationFactory::~VisualizationFactory()
{

}

Visualization* VisualizationFactory::createVisualization(DataObject* object)
{
	Visualization* visualization = nullptr;

	if (object == nullptr)
		return visualization;

	//Generate visualization
	if (object->getTypeId() == CircleShape::getClassTypeId())
	{
		visualization = new CircleShapeVisualization(object);
	}
	else if (object->getTypeId() == LineShape::getClassTypeId())
	{
		visualization = new LineShapeVisualization(object);
	}
	else if (object->getTypeId() == PolygonShape::getClassTypeId())
	{
		visualization = new PolygonShapeVisualization(object);
	}
	else if (object->getTypeId() == RectShape::getClassTypeId())
	{
		visualization = new RectShapeVisualization(object);
	}
	else if (object->getTypeId() == TriangleShape::getClassTypeId())
	{
		visualization = new TriangleShapeVisualization(object);
	}

	return visualization;
}
