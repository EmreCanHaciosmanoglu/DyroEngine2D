#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/ShapeVisualization.h"
#include "Rendering/Objects/RenderItems/Shapes/Shape.h"

#include "SceneGraph\Objects\Components\Component.h"

#include "Core/Defines/deletemacros.h"

ShapeVisualization::ShapeVisualization(Component* object, const std::tstring& name)
	:ComponentVisualization(object, name)
{
}
ShapeVisualization::~ShapeVisualization()
{
	SafeDelete(this->shape);
}

void ShapeVisualization::setShape(Shape* shape)
{
	this->shape = shape;
}
Shape* ShapeVisualization::getShape() const
{
	return this->shape;
}