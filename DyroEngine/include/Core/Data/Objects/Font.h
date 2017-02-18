#ifndef _FONT_H
#define _FONT_H

#include "Core/Helpers/TaggedObject.h"

#ifndef _2DUTILL_H
#include "Core/Defines/d2dutill.h"
#endif

class Font : public TaggedObject<Font>
{
public:
	Font(const std::tstring& name);
	virtual ~Font();

	bool create(IDWriteFactory* factory);

	void setFontCollection(IDWriteFontCollection* collection);
	void setFontWeight(const DWRITE_FONT_WEIGHT& weight);
	void setFontStyle(const DWRITE_FONT_STYLE& style);
	void setFontStretch(const DWRITE_FONT_STRETCH& stretch);
	void setFontSize(float size);
	void setFontLocalization(const std::tstring& local);

	IDWriteFontCollection* getFontCollection() const;
	const DWRITE_FONT_WEIGHT& getFontWeight() const;
	const DWRITE_FONT_STYLE& getFontStyle() const;
	const DWRITE_FONT_STRETCH& getFontStretch() const;
	float getFontSize() const;
	const std::tstring& getFontLocalization() const;

	IDWriteTextFormat* getTextFormat() const;

private:
	IDWriteFontCollection* collection;

	DWRITE_FONT_WEIGHT weight;
	DWRITE_FONT_STYLE style;
	DWRITE_FONT_STRETCH stretch;

	float size;
	
	std::tstring local;
	
	IDWriteTextFormat* format;
};

#endif 
