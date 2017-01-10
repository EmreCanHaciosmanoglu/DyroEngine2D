#include "Rendering/Objects/RenderItems/Shapes/RectShape.h"

#include "Rendering/Renderer.h"

#include "Core/Defines/assert.h"

RectShape::RectShape(const std::tstring& name)
	:Shape(name)
{}
RectShape::RectShape(RectShapeDescription* desc, const std::tstring& name)
	: Shape(desc, name)
{
}
RectShape::~RectShape()
{}

void RectShape::render(Renderer* renderer)
{
	//Renderer cannot be null
	assert(renderer != nullptr);

	RectShapeDescription* desc = getRectShapeDescription();

	renderer->setColor(desc->getColor());

	desc->getFill()
		? renderer->fillRect(desc->getRect())
		: renderer->drawRect(desc->getRect(), desc->getLineWidth());
}

float RectShape::getWidth() const
{
	return (float)getRectShapeDescription()->getRect().getWidth();
}
float RectShape::getHeight() const
{
	return (float)getRectShapeDescription()->getRect().getHeight();
}

RectShapeDescription* RectShape::getRectShapeDescription() const
{
	return dynamic_cast<RectShapeDescription*>(getDescription());
}