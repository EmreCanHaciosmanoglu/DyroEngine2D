#include "Core/Data/Objects/Direct2D/Text/TextFormat.h"
#include "Core/Defines/deletemacros.h"

TextFormat::TextFormat(const std::tstring& fontName)
	:font_name(fontName)
	, collection(nullptr)

	, weight(DWRITE_FONT_WEIGHT_NORMAL)
	, style(DWRITE_FONT_STYLE_NORMAL)
	, stretch(DWRITE_FONT_STRETCH_NORMAL)

	, size(12.0f)
	, local(_T("")) // TODO Localize

	, format(nullptr)
{}
TextFormat::~TextFormat()
{
	SafeRelease(this->format);
}

bool TextFormat::create(IDWriteFactory* factory)
{
	HRESULT hr = factory->CreateTextFormat(
		this->font_name.c_str(), 
		this->collection, 
		this->weight, 
		this->style, 
		this->stretch, 
		this->size, 
		this->local.c_str(), 
		&this->format
		);

	//this->format->SetFlowDirection(DWRITE_FLOW_DIRECTION_LEFT_TO_RIGHT);
	this->format->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
	this->format->SetReadingDirection(DWRITE_READING_DIRECTION_LEFT_TO_RIGHT);
	this->format->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
	this->format->SetWordWrapping(DWRITE_WORD_WRAPPING_WHOLE_WORD);
	this->format->SetLineSpacing(DWRITE_LINE_SPACING_METHOD_DEFAULT, 1.0f, 0.0f);

	return hr == S_OK;
}

void TextFormat::setFontCollection(IDWriteFontCollection* collection)
{
	this->collection = collection;
}
void TextFormat::setFontWeight(const DWRITE_FONT_WEIGHT& weight)
{
	this->weight = weight;
}
void TextFormat::setFontStyle(const DWRITE_FONT_STYLE& style)
{
	this->style = style;
}
void TextFormat::setFontStretch(const DWRITE_FONT_STRETCH& stretch)
{
	this->stretch = stretch;
}
void TextFormat::setFontSize(float size)
{
	this->size = size;
}
void TextFormat::setFontLocalization(const std::tstring& local)
{
	this->local = local;
}

void TextFormat::setFlowDirection(const DWRITE_FLOW_DIRECTION& flowDirection)
{
	if(this->format)
		this->format->SetFlowDirection(flowDirection);
}
void TextFormat::setLineSpacing(const LineSpacingData& data)
{
	if (this->format)
		this->format->SetLineSpacing(data.method, data.spacing, data.baseline);
}
void TextFormat::setParagraphAlignment(const DWRITE_PARAGRAPH_ALIGNMENT& alignment)
{
	if (this->format)
		this->format->SetParagraphAlignment(alignment);
}
void TextFormat::setReadingDirection(const DWRITE_READING_DIRECTION& direction)
{
	if (this->format)
		this->format->SetReadingDirection(direction);
}
void TextFormat::setTextAlignment(const DWRITE_TEXT_ALIGNMENT& alignment)
{
	if (this->format)
		this->format->SetTextAlignment(alignment);
}
void TextFormat::setWordWrapping(const DWRITE_WORD_WRAPPING& wrapping)
{
	if (this->format)
		this->format->SetWordWrapping(wrapping);
}

IDWriteFontCollection* TextFormat::getFontCollection() const
{
	return this->collection;
}
const DWRITE_FONT_WEIGHT& TextFormat::getFontWeight() const
{
	return this->weight;
}
const DWRITE_FONT_STYLE& TextFormat::getFontStyle() const
{
	return this->style;
}
const DWRITE_FONT_STRETCH& TextFormat::getFontStretch() const
{
	return this->stretch;
}
float TextFormat::getFontSize() const
{
	return this->size;
}
const std::tstring& TextFormat::getFontLocalization() const
{
	return this->local;
}

const DWRITE_FLOW_DIRECTION TextFormat::getFlowDirection() const
{
	if (this->format)
		return this->format->GetFlowDirection();

	return DWRITE_FLOW_DIRECTION_LEFT_TO_RIGHT;
}
const LineSpacingData TextFormat::getLineSpacing() const
{
	if (this->format)
	{
		DWRITE_LINE_SPACING_METHOD method;
		float line_spacing;
		float line_spacing_baseline;

		this->format->GetLineSpacing(&method, &line_spacing, &line_spacing_baseline);

		return LineSpacingData{ method,line_spacing,line_spacing_baseline };
	}
	
	return LineSpacingData { DWRITE_LINE_SPACING_METHOD_DEFAULT, 1.0f, 0.0f };
}
const DWRITE_PARAGRAPH_ALIGNMENT TextFormat::getParagraphAlignment() const
{
	if (this->format)
		return this->format->GetParagraphAlignment();

	return DWRITE_PARAGRAPH_ALIGNMENT_CENTER;
}
const DWRITE_READING_DIRECTION TextFormat::getReadingDirection() const
{
	if (this->format)
		return this->format->GetReadingDirection();

	return DWRITE_READING_DIRECTION_LEFT_TO_RIGHT;
}
const DWRITE_TEXT_ALIGNMENT TextFormat::getTextAlignment() const
{
	if (this->format)
		return this->format->GetTextAlignment();

	return DWRITE_TEXT_ALIGNMENT_CENTER;
}
const DWRITE_WORD_WRAPPING TextFormat::getWordWrapping() const
{
	if (this->format)
		return this->format->GetWordWrapping();

	return DWRITE_WORD_WRAPPING_WHOLE_WORD;
}

IDWriteTextFormat* TextFormat::getFormat() const
{
	return this->format;
}