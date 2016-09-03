#ifndef _SHAPE_H
#define _SHAPE_H

class Renderer;

class Shape
{
public:
	Shape() {}
	virtual ~Shape() {}

	virtual void render(Renderer* renderer) = 0;
};

#endif