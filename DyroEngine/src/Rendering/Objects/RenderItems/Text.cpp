#include "Rendering\Objects\RenderItems\Text.h"
#include "Rendering\Renderer.h"

#include "Core/Data/Objects/Font.h"
#include "Core/Data/Objects/Descriptions/Text/TextDescription.h"
#include "Core/Data/Objects/Direct2D/Text/TextLayout.h"

Text::Text(TextDescription* description, const std::tstring& name)
	:RenderItem(name)
	, description(description)
{}
Text::~Text()
{}

void Text::render(Renderer* renderer)
{
	renderer->setColor(this->description->getColor());
	renderer->drawText(this->description);
}

bool Text::isTransparant() const
{
	return this->description->getColor().alpha != 1.0f;
}
Rect2D Text::getBounds() const
{
	Rect2D untransformed_bounds = this->description->getFont()->getTextLayout()->getTextBounds();
	Matrix2D transform = getTransform();

	Vector2D left_top = transform.transformPoint(Vector2D((float)untransformed_bounds.left, (float)untransformed_bounds.top));
	Vector2D right_bottom = transform.transformPoint(Vector2D((float)untransformed_bounds.right, (float)untransformed_bounds.bottom));

	return Rect2D(left_top,right_bottom);
}

float Text::getWidth() const
{
	return (float)this->description->getFont()->getTextLayout()->getTextBounds().getWidth();
}
float Text::getHeight() const
{
	return (float)this->description->getFont()->getTextLayout()->getTextBounds().getHeight();
}

TextDescription* Text::getTextDescription() const
{
	return this->description;
}