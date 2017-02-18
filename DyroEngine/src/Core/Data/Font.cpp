#include "Core/Data/Objects/Font.h"

Font::Font(const std::tstring& name)
	:TaggedObject(name)
	, collection(nullptr)

	, weight(DWRITE_FONT_WEIGHT_BOLD)
	, style(DWRITE_FONT_STYLE_NORMAL)
	, stretch(DWRITE_FONT_STRETCH_NORMAL)

	, size(12.0f)
	, local(_T("en-us")) // TODO Localize

	, format(nullptr)
{
}
Font::~Font()
{}

bool Font::create(IDWriteFactory* factory)
{
	HRESULT hr = factory->CreateTextFormat(getName().c_str(), this->collection, this->weight, this->style, this->stretch, this->size, this->local.c_str(), &this->format);
	return hr == S_OK;
}

void Font::setFontCollection(IDWriteFontCollection* collection)
{
	this->collection = collection;
}
void Font::setFontWeight(const DWRITE_FONT_WEIGHT& weight)
{
	this->weight = weight;
}
void Font::setFontStyle(const DWRITE_FONT_STYLE& style)
{
	this->style = style;
}
void Font::setFontStretch(const DWRITE_FONT_STRETCH& stretch)
{
	this->stretch = stretch;
}
void Font::setFontSize(float size)
{
	this->size = size;
}
void Font::setFontLocalization(const std::tstring& local)
{
	this->local = local;
}

IDWriteFontCollection* Font::getFontCollection() const
{
	return this->collection;
}
const DWRITE_FONT_WEIGHT& Font::getFontWeight() const
{
	return this->weight;
}
const DWRITE_FONT_STYLE& Font::getFontStyle() const
{
	return this->style;
}
const DWRITE_FONT_STRETCH& Font::getFontStretch() const
{
	return this->stretch;
}
float Font::getFontSize() const
{
	return this->size;
}
const std::tstring& Font::getFontLocalization() const
{
	return this->local;
}

IDWriteTextFormat* Font::getTextFormat() const
{
	return this->format;
}