#ifndef _COLOR_H
#define _COLOR_H

#include "Core/Defines/d2dutill.h"

struct Color
{
	Color()
		: red(1)
		, green(1)
		, blue(1)
		, alpha(1)
	{}
	Color(float r, float g, float b, float a = 1.0f)
		: red(r)
		, green(g)
		, blue(b)
		, alpha(a)
	{}
	Color(const Color& c)
		:red(c.red)
		, green(c.green)
		, blue(c.blue)
		, alpha(c.alpha)
	{}

	float red;
	float green;
	float blue;
	float alpha;

	D2D1::ColorF toColorF() const
	{
		return D2D1::ColorF(this->red, this->green, this->blue, this->alpha);
	}

	bool operator== (const Color& ref) const
	{
		return this->red == ref.red && this->green == ref.green && this->blue == ref.blue && this->alpha == ref.alpha;
	}
	bool operator!=(const Color& ref) const
	{
		return this->red != ref.red || this->green != ref.green || this->blue != ref.blue || this->alpha != ref.alpha;
	}
};

#endif //_COLOR_H