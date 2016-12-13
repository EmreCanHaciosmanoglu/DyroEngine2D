#include "Core/Rendering/Visualization/Shapes/LineShapeVisualization.h"

#include "Core/Data/Shapes/Shape.h"

LineShapeVisualization::LineShapeVisualization(GameObject* object, Component* component)
	:ShapeVisualization(object, component, _T("LineVisualization"))
{

}
LineShapeVisualization::~LineShapeVisualization()
{

}
