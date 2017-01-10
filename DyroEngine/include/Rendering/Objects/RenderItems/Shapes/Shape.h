#ifndef _SHAPE_H
#define _SHAPE_H

#include "Rendering\Objects\RenderItems\RenderItem.h"

class Renderer;
class ShapeDescription;

class Shape : public RenderItem
{
public:
	Shape(const std::tstring& name = _T("Shape"));
	Shape(ShapeDescription* description, const std::tstring& name = _T("Shape"));
	virtual ~Shape();

	virtual void render(Renderer* renderer) = 0;

	void setDescription(ShapeDescription* description);

	virtual bool isTransparant() const;

	virtual float getWidth() const = 0;
	virtual float getHeight() const = 0;

	ShapeDescription* getDescription() const;

protected:
	ShapeDescription* description;
};

#endif