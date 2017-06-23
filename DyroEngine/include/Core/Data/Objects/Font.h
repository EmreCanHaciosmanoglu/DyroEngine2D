#ifndef _FONT_H
#define _FONT_H

#include "Core/Helpers/TaggedObject.h"

#ifndef _RECT2D_H
#include "Math\Objects\Rect2D.h"
#endif

class TextLayout;
class TextFormat;

struct IDWriteFactory;

class Font : public TaggedObject<Font>
{
public:
	Font(const std::tstring& fontName, const std::tstring& name);
	virtual ~Font();

	bool createTextFormat(IDWriteFactory* factory);
	bool createTextLayout(const std::tstring& text, const Rect2D& bounds);

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

	TextLayout* getTextLayout() const;
	TextFormat* getTextFormat() const;

private:	
	TextFormat* format;
	TextLayout* layout;

	IDWriteFactory* factory;
};

#endif 
