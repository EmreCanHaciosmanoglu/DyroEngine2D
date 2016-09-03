#include "SceneGraph/Object/Objects/Shapes/LineShape.h"

#include "Core/Rendering/Renderer.h"

#include "Defines/assert.h"

LineShape::LineShape(float x1, float y1, float x2, float y2, float lineWidth)
	:LineShape(Vector2D(x1,y1),Vector2D(x2,y2),lineWidth)
{}
LineShape::LineShape(const Vector2D& v1, const Vector2D& v2, float lineWidth)
	:v1(v1)
	,v2(v2)
	,line_width(lineWidth)
{}
LineShape::~LineShape()
{}

void LineShape::render(Renderer* renderer)
{
	//Renderer cannot be null
	assert(renderer != nullptr);

	renderer->setColor(getColor());

	renderer->drawLine(this->v1, this->v2, this->line_width);
}