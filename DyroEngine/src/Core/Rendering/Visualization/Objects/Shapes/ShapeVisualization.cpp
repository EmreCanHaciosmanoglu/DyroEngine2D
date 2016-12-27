#include "Core/Rendering/Visualization/Objects/Shapes/ShapeVisualization.h"

#include "SceneGraph\Component\Component.h"

ShapeVisualization::ShapeVisualization(Component* object, const std::tstring& name)
	:ComponentVisualization(object, name)
{
}
ShapeVisualization::~ShapeVisualization()
{
}