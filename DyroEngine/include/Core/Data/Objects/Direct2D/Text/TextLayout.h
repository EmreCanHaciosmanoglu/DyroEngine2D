#ifndef _TEXTLAYOUT_H
#define _TEXTLAYOUT_H

#ifndef _STRING_H
#include "Core/Defines/string.h"
#endif
#ifndef _2DUTILL_H
#include "Core/Defines/d2dutill.h"
#endif

#ifndef _RECT2D_H
#include "Math\Objects\Rect2D.h"
#endif

class TextFormat;

class TextLayout
{
public:
	TextLayout();
	~TextLayout();

	bool create(IDWriteFactory* factory, const std::tstring& text, TextFormat* format, const Rect2D& layoutBox);

	float getMaxWidth() const;
	float getMaxHeight() const;

	Rect2D getTextBounds(bool includeWhitespace = false) const;
	Rect2D getLayoutBounds() const;

	UINT32 getNumberOfLines() const;

	IDWriteTextLayout* getLayout() const;

private:
	IDWriteTextLayout* layout;
};

#endif