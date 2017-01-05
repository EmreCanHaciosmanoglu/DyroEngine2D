#include "Core\Data\Factory\ShapeFactory.h"

#include "Rendering\Objects\RenderItems\Shapes\CircleShape.h"
#include "Rendering\Objects\RenderItems\Shapes\LineShape.h"
#include "Rendering\Objects\RenderItems\Shapes\PolygonShape.h"
#include "Rendering\Objects\RenderItems\Shapes\RectShape.h"
#include "Rendering\Objects\RenderItems\Shapes\TriangleShape.h"

#include "Core\Types\ShapeType.h"

ShapeFactory::ShapeFactory()
{}
ShapeFactory::~ShapeFactory()
{}

Shape* ShapeFactory::createShape(ShapeType type)
{
	switch (type)
	{
	case ShapeType::CIRCLE_SHAPE:
		return new CircleShape();
	case ShapeType::LINE_SHAPE:
		return new LineShape();
	case ShapeType::POLYGON_SHAPE:
		return new PolygonShape();
	case ShapeType::RECTANGLE_SHAPE:
		return new RectShape();
	case ShapeType::TRIANGLE_SHAPE:
		return new TriangleShape();
	}

	return nullptr;
}