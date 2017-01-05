#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/ShapeVisualization.h"

#include "SceneGraph\Objects\Components\Component.h"

ShapeVisualization::ShapeVisualization(Component* object, const std::tstring& name)
	:ComponentVisualization(object, name)
{
}
ShapeVisualization::~ShapeVisualization()
{
}