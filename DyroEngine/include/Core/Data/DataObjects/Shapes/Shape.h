#ifndef _SHAPE_H
#define _SHAPE_H

#ifndef _COLOR_H
#include "Defines/color.h"
#endif

class Renderer;

class Shape
{
public:
	Shape(const std::tstring& name = _T(""));
	virtual ~Shape();

	void setColor(const Color& c);
	const Color& getColor() const;

private:
	Color color;
};

#endif