#ifndef _TEXTCOMPONENT_H
#define _TEXTCOMPONENT_H

#include "SceneGraph\Objects\Components\Component.h"

#ifndef _TEXTFORMAT_H
#include "Core/Data/Objects/Direct2D/Text/TextFormat.h"
#endif
#ifndef _TEXTLAYOUT_H
#include "Core/Data/Objects/Direct2D/Text/TextLayout.h"
#endif

#ifndef _COLOR_H
#include "Core/Defines/color.h"
#endif
#ifndef _2DUTILL_H
#include "Core/Defines/d2dutill.h"
#endif

class Font;
class TextDescription;

class TextComponent : public Component
{
public:
	TextComponent(TextDescription* description, const std::tstring& name = _T("TextComponnet"));
	virtual ~TextComponent();

	virtual bool initialize();
	virtual bool shutdown();

	void setFlowDirection(const DWRITE_FLOW_DIRECTION& flowDirection);
	void setLineSpacing(const LineSpacingData& data);
	void setParagraphAlignment(const DWRITE_PARAGRAPH_ALIGNMENT& alignment);
	void setReadingDirection(const DWRITE_READING_DIRECTION& direction);
	void setTextAlignment(const DWRITE_TEXT_ALIGNMENT& alignment);
	void setWordWrapping(const DWRITE_WORD_WRAPPING& wrapping);

	void setOriginOffset(const Vector2D& originOffset);
	void setLayoutBox(const Rect2D& layoutBox);
	void setColor(const Color& color);
	void setDescription(TextDescription* description);

	void setText(const std::tstring& text);
	void setFont(Font* font);

	const DWRITE_FLOW_DIRECTION& getFlowDirection() const;
	const LineSpacingData& getLineSpacing() const;
	const DWRITE_PARAGRAPH_ALIGNMENT& getParagraphAlignment() const;
	const DWRITE_READING_DIRECTION& getReadingDirection() const;
	const DWRITE_TEXT_ALIGNMENT& getTextAlignment() const;
	const DWRITE_WORD_WRAPPING& getWordWrapping() const;

	const Vector2D& getOriginOffset() const;
	const Rect2D& getLayoutBox() const;
	const Color& getColor() const;
	TextDescription* getDescription() const;

	const std::tstring& getText() const;
	Font* getFont() const;

private:
	TextDescription* description;
};

#endif