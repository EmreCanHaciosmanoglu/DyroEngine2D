#ifndef _TEXTFORMAT_H
#define _TEXTFORMAT_H

#ifndef _STRING_H
#include "Core/Defines/string.h"
#endif
#ifndef _2DUTILL_H
#include "Core/Defines/d2dutill.h"
#endif

struct LineSpacingData
{
	DWRITE_LINE_SPACING_METHOD method;
	float spacing;
	float baseline;
};

class TextFormat
{
public:
	TextFormat(const std::tstring& fontName);
	~TextFormat();

	bool create(IDWriteFactory* factory);

	void setFontCollection(IDWriteFontCollection* collection);
	void setFontWeight(const DWRITE_FONT_WEIGHT& weight);
	void setFontStyle(const DWRITE_FONT_STYLE& style);
	void setFontStretch(const DWRITE_FONT_STRETCH& stretch);
	void setFontSize(float size);
	void setFontLocalization(const std::tstring& local);

	void setFlowDirection(const DWRITE_FLOW_DIRECTION& flowDirection);
	void setLineSpacing(const LineSpacingData& data);
	void setParagraphAlignment(const DWRITE_PARAGRAPH_ALIGNMENT& alignment);
	void setReadingDirection(const DWRITE_READING_DIRECTION& direction);
	void setTextAlignment(const DWRITE_TEXT_ALIGNMENT& alignment);
	void setWordWrapping(const DWRITE_WORD_WRAPPING& wrapping);

	IDWriteFontCollection* getFontCollection() const;
	const DWRITE_FONT_WEIGHT& getFontWeight() const;
	const DWRITE_FONT_STYLE& getFontStyle() const;
	const DWRITE_FONT_STRETCH& getFontStretch() const;
	float getFontSize() const;
	const std::tstring& getFontLocalization() const;

	const DWRITE_FLOW_DIRECTION getFlowDirection() const;
	const LineSpacingData getLineSpacing() const;
	const DWRITE_PARAGRAPH_ALIGNMENT getParagraphAlignment() const;
	const DWRITE_READING_DIRECTION getReadingDirection() const;
	const DWRITE_TEXT_ALIGNMENT getTextAlignment() const;
	const DWRITE_WORD_WRAPPING getWordWrapping() const;

	IDWriteTextFormat* getFormat() const;

private:
	std::tstring font_name;
	std::tstring local;

	IDWriteFontCollection* collection;
	IDWriteTextFormat* format;

	DWRITE_FONT_WEIGHT weight;
	DWRITE_FONT_STYLE style;
	DWRITE_FONT_STRETCH stretch;

	float size;
};

#endif