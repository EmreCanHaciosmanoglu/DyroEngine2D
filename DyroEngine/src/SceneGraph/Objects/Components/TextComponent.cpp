#include "SceneGraph\Objects\Components\TextComponent.h"

#include "Core/Data/Objects/Descriptions/Text/TextDescription.h"
#include "Core/Data/Objects/Font.h"

#include "Core/Defines/assert.h"
#include "Core/Defines/deletemacros.h"

TextComponent::TextComponent(TextDescription* description,const std::tstring& name)
	:Component(name)
	, description(description)
{
	setExecutionOrder(500);
}
TextComponent::~TextComponent()
{}

bool TextComponent::initialize()
{
	assert(this->description->getFont() != nullptr);

	this->description->getFont()->createTextLayout(this->description->getText(), this->description->getLayoutBox());

	return true;
}
bool TextComponent::shutdown()
{
	SafeDelete(this->description);

	return true;
}

void TextComponent::setFlowDirection(const DWRITE_FLOW_DIRECTION& flowDirection)
{
	this->description->getFont()->getTextFormat()->setFlowDirection(flowDirection);
}
void TextComponent::setLineSpacing(const LineSpacingData& data)
{
	this->description->getFont()->getTextFormat()->setLineSpacing(data);
}
void TextComponent::setParagraphAlignment(const DWRITE_PARAGRAPH_ALIGNMENT& alignment)
{
	this->description->getFont()->getTextFormat()->setParagraphAlignment(alignment);
}
void TextComponent::setReadingDirection(const DWRITE_READING_DIRECTION& direction)
{
	this->description->getFont()->getTextFormat()->setReadingDirection(direction);
}
void TextComponent::setTextAlignment(const DWRITE_TEXT_ALIGNMENT& alignment)
{
	this->description->getFont()->getTextFormat()->setTextAlignment(alignment);
}
void TextComponent::setWordWrapping(const DWRITE_WORD_WRAPPING& wrapping)
{
	this->description->getFont()->getTextFormat()->setWordWrapping(wrapping);
}

void TextComponent::setOriginOffset(const Vector2D& offset)
{
	this->description->setOriginOffset(offset);
}
void TextComponent::setLayoutBox(const Rect2D& layoutBox)
{
	this->description->setLayoutBox(layoutBox);
}
void TextComponent::setColor(const Color& color)
{
	this->description->setColor(color);
}
void TextComponent::setDescription(TextDescription* description)
{
	if (this->description != nullptr)
		SafeDelete(this->description);

	this->description = description;
}

void TextComponent::setText(const std::tstring& text)
{
	this->description->setText(text);
}
void TextComponent::setFont(Font* font)
{
	this->description->setFont(font);
}

const DWRITE_FLOW_DIRECTION& TextComponent::getFlowDirection() const
{
	return this->description->getFont()->getTextFormat()->getFlowDirection();
}
const LineSpacingData& TextComponent::getLineSpacing() const
{
	return this->description->getFont()->getTextFormat()->getLineSpacing();
}
const DWRITE_PARAGRAPH_ALIGNMENT& TextComponent::getParagraphAlignment() const
{
	return this->description->getFont()->getTextFormat()->getParagraphAlignment();
}
const DWRITE_READING_DIRECTION& TextComponent::getReadingDirection() const
{
	return this->description->getFont()->getTextFormat()->getReadingDirection();
}
const DWRITE_TEXT_ALIGNMENT& TextComponent::getTextAlignment() const
{
	return this->description->getFont()->getTextFormat()->getTextAlignment();
}
const DWRITE_WORD_WRAPPING& TextComponent::getWordWrapping() const
{
	return this->description->getFont()->getTextFormat()->getWordWrapping();
}

const Vector2D& TextComponent::getOriginOffset() const
{
	return this->description->getOriginOffset();
}
const Rect2D& TextComponent::getLayoutBox() const
{
	return this->description->getLayoutBox();
}
const Color& TextComponent::getColor() const
{
	return this->description->getColor();
}
TextDescription* TextComponent::getDescription() const
{
	return this->description;
}

const std::tstring& TextComponent::getText() const
{
	return this->description->getText();
}
Font* TextComponent::getFont() const
{
	return this->description->getFont();
}