#ifndef _TEXTCOMPONENT_H
#define _TEXTCOMPONENT_H

#include "SceneGraph\Objects\Components\Component.h"

#ifndef _2DUTILL_H
#include "Core/Defines/d2dutill.h"
#endif

class Font;

class TextComponent : public Component
{
public:
	TextComponent(const std::tstring& text, Font* font, const std::tstring& name = _T("TextComponnet"));
	virtual ~TextComponent();

	virtual bool initialize();
	virtual bool shutdown();

	void setFontFlowDirection(const DWRITE_FLOW_DIRECTION& flowDirection);
	void setFontLineSpacing(const DWRITE_LINE_SPACING_METHOD& spacingMethod, float lineSpacing, float baseLine);
	void setFontParagraphAlignment(const DWRITE_PARAGRAPH_ALIGNMENT& alignment);
	void setFontReadingDirection(const DWRITE_READING_DIRECTION& direction);
	void setFontTextAlignment(const DWRITE_TEXT_ALIGNMENT& alignment);
	void setFontWordWrapping(const DWRITE_WORD_WRAPPING& wrapping);

	void setText(const std::tstring& text);
	void setFont(Font* font);

	const DWRITE_FLOW_DIRECTION& getFontFlowDirection() const;
	void getFontLineSpacing(DWRITE_LINE_SPACING_METHOD& spacingMethod, float& lineSpacing, float& baseLine) const;
	const DWRITE_PARAGRAPH_ALIGNMENT& getParagraphAlignment() const;
	const DWRITE_READING_DIRECTION& getReadingDirection() const;
	const DWRITE_TEXT_ALIGNMENT& getTextAlignment() const;
	const DWRITE_WORD_WRAPPING& getWordWrapping() const;

	const std::tstring& getText() const;
	Font* getFont() const;

private:
	DWRITE_FLOW_DIRECTION flow_direction;
	DWRITE_PARAGRAPH_ALIGNMENT paragraph_alignment;
	DWRITE_READING_DIRECTION reading_direction;
	DWRITE_TEXT_ALIGNMENT text_alignment;
	DWRITE_WORD_WRAPPING text_wrapping;
	DWRITE_LINE_SPACING_METHOD line_spacing_method;

	float line_spacing;
	float line_spacing_baseline;

	std::tstring text;
	Font* font;
};

#endif