#ifndef _TEXTDESCRIPTION_H
#define _TEXTDESCRIPTION_H

#ifndef _STRING_H
#include "Core/Defines/string.h"
#endif
#ifndef _COLOR_H
#include "Core/Defines/color.h"
#endif

#ifndef _RECT2D_H
#include "Math\Objects\Rect2D.h"
#endif
#ifndef _VECTOR2D_H
#include "Math\Objects\Vector2D.h"
#endif

class Font;

class TextDescription
{
public:
	TextDescription(const std::tstring& text, Font* font, const Rect2D& layoutBox);
	~TextDescription();

	void setText(const std::tstring& text);
	void setFont(Font* font);
	void setColor(const Color& color);
	void setLayoutBox(const Rect2D& layoutBox);
	void setOriginOffset(const Vector2D& originOffset);

	const std::tstring& getText() const;
	Font* getFont();
	const Color& getColor() const;
	const Rect2D& getLayoutBox() const;
	const Vector2D& getOriginOffset() const;

private:
	std::tstring text;
	Color color;
	Font* font;
	Rect2D layout_box;
	Vector2D origin_offset;
};

#endif
