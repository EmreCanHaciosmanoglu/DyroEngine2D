#ifndef _SHAPE_H
#define _SHAPE_H

class Renderer;

#ifndef _COLOR_H
#include "Defines/color.h"
#endif

class Shape
{
public:
	Shape();
	virtual ~Shape();

	virtual void render(Renderer* renderer) = 0;

	void setColor(const Color& c);
	const Color& getColor() const;
private:
	Color color;
};

#endif