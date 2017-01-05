#include "Rendering/Objects/RenderItems/Shapes/CircleShape.h"

#include "Rendering/Renderer.h"

#include "Core/Defines/assert.h"

CircleShape::CircleShape(const std::tstring& name)
	:Shape(name)
{}
CircleShape::CircleShape(CircleShapeDescription* descripion, const std::tstring& name)
	: Shape(descripion, name)
{
}
CircleShape::~CircleShape()
{}

void CircleShape::render(Renderer* renderer)
{
	//Renderer cannot be null
	assert(renderer != nullptr);

	CircleShapeDescription* desc = getCirlceShapeDescription();

	renderer->setColor(desc->getColor());

	desc->getFill()
		? renderer->fillCircle(desc->getCenter(), desc->getRadius())
		: renderer->drawCircle(desc->getCenter(), desc->getRadius(), desc->getLineWidth());
}

CircleShapeDescription* CircleShape::getCirlceShapeDescription() const
{
	return dynamic_cast<CircleShapeDescription*>(getDescription());
}

//Rect2D CircleShape::getBoundingBox() const
//{
//	Rect2D bounding_rect;
//
//	bounding_rect.left = 0;
//	bounding_rect.top = 0;
//	bounding_rect.right = this->radius * 2;
//	bounding_rect.bottom = this->radius * 2;
//
//	return bounding_rect;
//}