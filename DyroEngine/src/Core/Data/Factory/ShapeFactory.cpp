#include "Core\Data\Factory\ShapeFactory.h"

#include "Core\Data\Objects\Shapes\CircleShape.h"
#include "Core\Data\Objects\Shapes\LineShape.h"
#include "Core\Data\Objects\Shapes\PolygonShape.h"
#include "Core\Data\Objects\Shapes\RectShape.h"
#include "Core\Data\Objects\Shapes\TriangleShape.h"

#include "Defines\Types\ShapeType.h"

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