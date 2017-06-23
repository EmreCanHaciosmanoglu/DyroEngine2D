#include "Core/Data/Objects/Descriptions/Text/TextDescription.h"

TextDescription::TextDescription(const std::tstring& text, Font* font, const Rect2D& layoutBox)
	:text(text)
	,font(font)
	,layout_box(layoutBox)
	,color(Color(1.0f,1.0f,1.0f,1.0f))
	,origin_offset(0.0f,0.0f)
{}
TextDescription::~TextDescription()
{}

void TextDescription::setText(const std::tstring& text)
{
	this->text = text;
}
void TextDescription::setFont(Font* font)
{
	this->font = font;
}
void TextDescription::setColor(const Color& color)
{
	this->color = color;
}
void TextDescription::setLayoutBox(const Rect2D& layoutBox)
{
	this->layout_box = layoutBox;
}
void TextDescription::setOriginOffset(const Vector2D& offset)
{
	this->origin_offset = offset;
}

const std::tstring& TextDescription::getText() const
{
	return this->text;
}
Font* TextDescription::getFont()
{
	return this->font;
}
const Color& TextDescription::getColor() const
{
	return this->color;
}
const Rect2D& TextDescription::getLayoutBox() const
{
	return this->layout_box;
}
const Vector2D& TextDescription::getOriginOffset() const
{
	return this->origin_offset;
}