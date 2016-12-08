#ifndef _SHAPE_H
#define _SHAPE_H

#include "Core/Data/DataObjects/DataObject.h"

#ifndef _COLOR_H
#include "Defines/color.h"
#endif

class Renderer;

class Shape : public DataObject
{
public:
	Shape(const std::tstring& name = _T(""));
	virtual ~Shape();

	virtual void render(Renderer* renderer) = 0;

	void setColor(const Color& c);
	const Color& getColor() const;
private:
	Color color;
};

#endif