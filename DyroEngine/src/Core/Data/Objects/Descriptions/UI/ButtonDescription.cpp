#include "Core/Data/Objects/Descriptions/UI/ButtonDescription.h"
#include "Core/Data/Objects/Descriptions/Shapes/RectShapeDescription.h"

#include "Core/Defines/deletemacros.h"

ButtonDescription::ButtonDescription()
	:border_width(0.0f)

	, border_hover_color(Color(0.35f, 0.35f, 0.35f))
	, border_idle_color(Color(0.5f, 0.5f, 0.5f))
	, background_hover_color(Color(0.35f, 0.35f, 0.35f))
	, background_idle_color(Color(0.5f, 0.5f, 0.5f))

	, text(_T("Button"))

	, shape_description(new RectShapeDescription(0, 0, 100, 30, true, background_idle_color))
	, image(nullptr)
{}
ButtonDescription::~ButtonDescription()
{}

void ButtonDescription::setShape(ShapeDescription* description)
{
	if (this->shape_description != nullptr)
		SafeDelete(this->shape_description);

	this->shape_description = description;
}
void ButtonDescription::setImage(Image* image)
{
	this->image = image;
}

void ButtonDescription::setBorderWidth(float width)
{
	this->border_width = width;
}

void ButtonDescription::setBackgroundHoverColor(const Color& color)
{
	this->background_hover_color = color;
}
void ButtonDescription::setBackgroundIdleColor(const Color& color)
{
	this->background_idle_color = color;
}
void ButtonDescription::setBorderHoverColor(const Color& color)
{
	this->border_hover_color = color;
}
void ButtonDescription::setBorderIdleColor(const Color& color)
{
	this->border_idle_color = color;
}

void ButtonDescription::setText(const std::tstring& text)
{
	this->text = text;
}

ShapeDescription* ButtonDescription::getShape() const
{
	return this->shape_description;
}
Image* ButtonDescription::getImage() const
{
	return this->image;
}

float ButtonDescription::getBorderWidth() const
{
	return this->border_width;
}

const Color& ButtonDescription::getBackgroundHoverColor() const
{
	return this->background_hover_color;
}
const Color& ButtonDescription::getBackgroundIdleColor() const
{
	return this->background_idle_color;
}
const Color& ButtonDescription::getBorderHoverColor() const
{
	return this->border_hover_color;
}
const Color& ButtonDescription::getBorderIdleColor() const
{
	return this->border_idle_color;
}

const std::tstring& ButtonDescription::getText() const
{
	return this->text;
}