#ifndef _COLOR_H
#define _COLOR_H

#include "Defines\d2dutill.h"

struct Color
{
	Color()
		: red(0)
		, green(0)
		, blue(0)
		, alpha(0)
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
		return D2D1::ColorF (this->red,this->green,this->blue,this->alpha);
	}
};

#endif //_COLOR_H