#ifndef _SHAPE_H
#define _SHAPE_H

#include "Helpers\TaggedObject.h"
#include "Core\Rendering\RenderItem.h"
#ifndef _COLOR_H
#include "Defines/color.h"
#endif

class Renderer;

class Shape : public TaggedObject<Shape> , public RenderItem
{
public:
	Shape(const std::tstring& name = _T(""));
	virtual ~Shape();

	virtual void render(Renderer* renderer) = 0;

	virtual bool isTransparant() const;

	void setColor(const Color& c);
	const Color& getColor() const;

private:
	Color color;
};

#endif