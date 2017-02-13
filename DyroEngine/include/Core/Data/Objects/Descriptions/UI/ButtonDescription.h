#ifndef _BUTTONDESCRIPTION_H
#define _BUTTONDESCRIPTION_H

#ifndef _VECTOR2D_H
#include "Math\Objects\Vector2D.h"
#endif

#ifndef _STRING_H
#include "Core/Defines/string.h"
#endif
#ifndef _COLOR_H
#include "Core/Defines/color.h"
#endif

class ShapeDescription;
class Image;

class ButtonDescription
{
public:
	ButtonDescription();
	~ButtonDescription();

	void setShape(ShapeDescription* description);
	void setImage(Image* image);

	void setBorderWidth(float width);

	void setBackgroundHoverColor(const Color& color);
	void setBackgroundIdleColor(const Color& color);
	void setBorderHoverColor(const Color& color);
	void setBorderIdleColor(const Color& color);

	void setText(const std::tstring& text);

	ShapeDescription* getShape() const;
	Image* getImage() const;

	float getBorderWidth() const;

	const Color& getBackgroundHoverColor() const;
	const Color& getBackgroundIdleColor() const;
	const Color& getBorderHoverColor() const;
	const Color& getBorderIdleColor() const;

	const std::tstring& getText() const;

private:
	float border_width;

	Color border_hover_color;
	Color border_idle_color;
	Color background_hover_color;
	Color background_idle_color;

	std::tstring text;

	ShapeDescription* shape_description;
	Image* image;
};

#endif