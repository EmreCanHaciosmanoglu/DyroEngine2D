#include "Rendering/Objects/RenderItems/Shapes/LineShape.h"

#include "Rendering/Renderer.h"

#include "Core/Defines/assert.h"

LineShape::LineShape(const std::tstring& name)
	:Shape(name)
{}
LineShape::LineShape(LineShapeDescription* description, const std::tstring& name)
	:Shape(description, name)
{}
LineShape::~LineShape()
{}

void LineShape::render(Renderer* renderer)
{
	//Renderer cannot be null
	assert(renderer != nullptr);

	LineShapeDescription* desc = getLineShapeDescription();

	renderer->setColor(desc->getColor());
	renderer->drawLine(desc->getStartPosition(), desc->getEndPosition(), desc->getLineWidth());
}

LineShapeDescription* LineShape::getLineShapeDescription() const
{
	return dynamic_cast<LineShapeDescription*>(getDescription());
}