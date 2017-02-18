#include "SceneGraph\Objects\Components\TextComponent.h"

#include "Core/Data/Objects/Font.h"
#include "Core/Defines/assert.h"

TextComponent::TextComponent(const std::tstring& text, Font* font,const std::tstring& name)
	:Component(name)

	, flow_direction(DWRITE_FLOW_DIRECTION_LEFT_TO_RIGHT)
	, paragraph_alignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER)
	, reading_direction(DWRITE_READING_DIRECTION_LEFT_TO_RIGHT)
	, text_alignment(DWRITE_TEXT_ALIGNMENT_CENTER)
	, text_wrapping(DWRITE_WORD_WRAPPING_CHARACTER)
	, line_spacing_method(DWRITE_LINE_SPACING_METHOD_DEFAULT)
	, line_spacing(1.0f)
	, line_spacing_baseline(0.0f)

	, text(text)
	, font(font)
{}
TextComponent::~TextComponent()
{}

bool TextComponent::initialize()
{
	assert(this->font != nullptr);

	this->font->getTextFormat()->SetFlowDirection(this->flow_direction);
	this->font->getTextFormat()->SetParagraphAlignment(this->paragraph_alignment);
	this->font->getTextFormat()->SetReadingDirection(this->reading_direction);
	this->font->getTextFormat()->SetTextAlignment(this->text_alignment);
	this->font->getTextFormat()->SetWordWrapping(this->text_wrapping);
	this->font->getTextFormat()->SetLineSpacing(this->line_spacing_method, this->line_spacing, this->line_spacing_baseline);

	return true;
}
bool TextComponent::shutdown()
{
	return true;
}

void TextComponent::setFontFlowDirection(const DWRITE_FLOW_DIRECTION& flowDirection)
{
	this->flow_direction = flowDirection;
}
void TextComponent::setFontLineSpacing(const DWRITE_LINE_SPACING_METHOD& spacingMethod, float lineSpacing, float baseLine)
{
	this->line_spacing_method = spacingMethod;
	this->line_spacing = lineSpacing;
	this->line_spacing_baseline = baseLine;
}
void TextComponent::setFontParagraphAlignment(const DWRITE_PARAGRAPH_ALIGNMENT& alignment)
{
	this->paragraph_alignment = alignment;
}
void TextComponent::setFontReadingDirection(const DWRITE_READING_DIRECTION& direction)
{
	this->reading_direction = direction;
}
void TextComponent::setFontTextAlignment(const DWRITE_TEXT_ALIGNMENT& alignment)
{
	this->text_alignment = alignment;
}
void TextComponent::setFontWordWrapping(const DWRITE_WORD_WRAPPING& wrapping)
{
	this->text_wrapping = wrapping;
}

void TextComponent::setText(const std::tstring& text)
{
	this->text = text;
}
void TextComponent::setFont(Font* font)
{
	this->font = font;
}

const DWRITE_FLOW_DIRECTION& TextComponent::getFontFlowDirection() const
{
	return this->flow_direction;
}
void TextComponent::getFontLineSpacing(DWRITE_LINE_SPACING_METHOD& spacingMethod, float& lineSpacing, float& baseLine) const
{
	spacingMethod = this->line_spacing_method;
	lineSpacing = this->line_spacing;
	baseLine = this->line_spacing_baseline;
}
const DWRITE_PARAGRAPH_ALIGNMENT& TextComponent::getParagraphAlignment() const
{
	return this->paragraph_alignment;
}
const DWRITE_READING_DIRECTION& TextComponent::getReadingDirection() const
{
	return this->reading_direction;
}
const DWRITE_TEXT_ALIGNMENT& TextComponent::getTextAlignment() const
{
	return this->text_alignment;
}
const DWRITE_WORD_WRAPPING& TextComponent::getWordWrapping() const
{
	return this->text_wrapping;
}

const std::tstring& TextComponent::getText() const
{
	return this->text;
}
Font* TextComponent::getFont() const
{
	return this->font;
}