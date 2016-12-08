#include "Core\Data\DataObjects\Shapes\TriangleShape.h"

TriangleShape::TriangleShape(float xScale, float yScale, float lineWidth)
	:PolygonShape(std::vector<Vector2D>() = { Vector2D(-1 * xScale,0), Vector2D(1 * xScale,1 * yScale), Vector2D(1 * xScale, -1 * yScale) }, true, lineWidth)
{}
TriangleShape::~TriangleShape()
{}