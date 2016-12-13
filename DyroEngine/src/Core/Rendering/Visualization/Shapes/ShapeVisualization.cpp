#include "Core/Rendering/Visualization/Shapes/ShapeVisualization.h"

#include "Core/Data/Shapes/Shape.h"

ShapeVisualization::ShapeVisualization(GameObject* object, Component* component, const std::tstring& name)
	:Visualization(object, component, name)
{

}
ShapeVisualization::~ShapeVisualization()
{

}
