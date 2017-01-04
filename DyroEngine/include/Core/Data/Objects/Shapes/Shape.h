#ifndef _SHAPE_H
#define _SHAPE_H

#include "Core\Rendering\RenderItem.h"

class Renderer;
class ShapeDescription;

class Shape : public RenderItem
{
public:
	Shape(const std::tstring& name = _T(""));
	Shape(ShapeDescription* description, const std::tstring& name = _T(""));
	virtual ~Shape();

	virtual void render(Renderer* renderer) = 0;

	virtual bool isTransparant() const;

	void setDescription(ShapeDescription* description);
	ShapeDescription* getDescription() const;

protected:
	ShapeDescription* description;
};

#endif