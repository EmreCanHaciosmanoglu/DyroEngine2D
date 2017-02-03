#include "Rendering/Objects/Visualization/ComponentVisualizations/Shapes/ShapeVisualization.h"
#include "Rendering/Objects/RenderItems/Shapes/Shape.h"

#include "SceneGraph\Objects\Components\Component.h"

#include "Core/Data/Objects/Geometry.h"

#include "Core/Defines/deletemacros.h"

ShapeVisualization::ShapeVisualization(Component* object, const std::tstring& name)
	:ConcreteComponentVisualization(object, name)
{
}
ShapeVisualization::~ShapeVisualization()
{
	SafeDelete(this->shape);
}

Rect2D ShapeVisualization::getBoundingBox() const
{
	return getShape()->getBounds();
}

void ShapeVisualization::setShape(Shape* shape)
{
	this->shape = shape;
}
Shape* ShapeVisualization::getShape() const
{
	return this->shape;
}