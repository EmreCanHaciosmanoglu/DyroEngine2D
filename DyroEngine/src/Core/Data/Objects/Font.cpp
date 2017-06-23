#include "Core/Data/Objects/Font.h"

#include "Core/Data/Objects/Direct2D/Text/TextFormat.h"
#include "Core/Data/Objects/Direct2D/Text/TextLayout.h"

#include "Core/Defines/deletemacros.h"
#include "Core/Defines/d2dutill.h"

Font::Font(const std::tstring& fontName, const std::tstring& name)
	:TaggedObject(name)
	, format(new TextFormat(fontName))
	, layout(new TextLayout())

	, factory(nullptr)
{
}
Font::~Font()
{
	SafeDelete(this->format);
	SafeDelete(this->layout);
}

bool Font::createTextFormat(IDWriteFactory* factory)
{
	HRESULT hr = S_OK;

	this->factory = factory;

	hr = this->format->create(factory);
	if (FAILED(hr))
		return false;

	return true;
}
bool Font::createTextLayout(const std::tstring& text, const Rect2D& layoutBox)
{
	HRESULT hr = S_OK;

	hr = this->layout->create(this->factory, text, format, layoutBox);
	if (FAILED(hr))
		return false;

	return true;
}

void Font::setFontCollection(IDWriteFontCollection* collection)
{
	this->format->setFontCollection(collection);
}
void Font::setFontWeight(const DWRITE_FONT_WEIGHT& weight)
{
	this->format->setFontWeight(weight);
}
void Font::setFontStyle(const DWRITE_FONT_STYLE& style)
{
	this->format->setFontStyle(style);
}
void Font::setFontStretch(const DWRITE_FONT_STRETCH& stretch)
{
	this->format->setFontStretch(stretch);
}
void Font::setFontSize(float size)
{
	this->format->setFontSize(size);
}
void Font::setFontLocalization(const std::tstring& local)
{
	this->format->setFontLocalization(local);
}

IDWriteFontCollection* Font::getFontCollection() const
{
	return this->format->getFontCollection();
}
const DWRITE_FONT_WEIGHT& Font::getFontWeight() const
{
	return this->format->getFontWeight();
}
const DWRITE_FONT_STYLE& Font::getFontStyle() const
{
	return this->format->getFontStyle();
}
const DWRITE_FONT_STRETCH& Font::getFontStretch() const
{
	return this->format->getFontStretch();
}
float Font::getFontSize() const
{
	return this->format->getFontSize();
}
const std::tstring& Font::getFontLocalization() const
{
	return this->format->getFontLocalization();
}

TextLayout* Font::getTextLayout() const
{
	return this->layout;
}
TextFormat* Font::getTextFormat() const
{
	return this->format;

}