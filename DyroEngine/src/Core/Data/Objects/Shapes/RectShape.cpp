#include "Core/Data/Objects/Shapes/RectShape.h"

#include "Core/Rendering/Renderer.h"

#include "Defines/assert.h"

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

RectShapeDescription* RectShape::getRectShapeDescription() const
{
	return dynamic_cast<RectShapeDescription*>(getDescription());
}

//Rect2D RectShape::getBoundingBox() const
//{
//	Rect2D bounding_rect;
//
//	bounding_rect.left = 0;
//	bounding_rect.top = 0;
//	bounding_rect.right = this->rect.right - this->rect.left;
//	bounding_rect.bottom = this->rect.bottom - this->rect.top;
//
//	return bounding_rect;
//}