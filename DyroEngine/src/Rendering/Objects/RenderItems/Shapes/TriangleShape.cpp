#include "Rendering\Objects\RenderItems\Shapes\TriangleShape.h"

TriangleShape::TriangleShape(const std::tstring& name)
	:PolygonShape(name)
{}
TriangleShape::TriangleShape(TriangleShapeDescription* desc, const std::tstring& name)
	:PolygonShape(desc, name)
{}
TriangleShape::~TriangleShape()
{}

void TriangleShape::render(Renderer* renderer)
{
	PolygonShape::render(renderer);
}

TriangleShapeDescription* TriangleShape::getTriangleShapeDescription() const
{
	return dynamic_cast<TriangleShapeDescription*>(getDescription());
}