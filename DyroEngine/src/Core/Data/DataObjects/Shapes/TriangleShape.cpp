#include "Core\Data\DataObjects\Shapes\TriangleShape.h"

TriangleShape::TriangleShape(float xScale, float yScale, float lineWidth, const std::tstring& name)
	:PolygonShape(std::vector<Vector2D>() = { Vector2D(-1 * xScale,0), Vector2D(1 * xScale,1 * yScale), Vector2D(1 * xScale, -1 * yScale) }, true, lineWidth,name)
{
	DATA_OBJECT_INIT(_T("TriangleShape"));
}
TriangleShape::~TriangleShape()
{}