#ifndef _SHAPE_H
#define _SHAPE_H

#include "Rendering\Objects\RenderItems\RenderItem.h"

class Graphics;
class Renderer;
class ShapeDescription;
class Geometry;

class Shape : public RenderItem
{
public:
	Shape(Visualization* parent, const std::tstring& name = _T("Shape"));
	Shape(Visualization* parent, ShapeDescription* description, const std::tstring& name = _T("Shape"));
	virtual ~Shape();

	virtual void create() = 0;
	virtual void render(Renderer* renderer) = 0;

	void setDescription(ShapeDescription* description);

	virtual bool isTransparant() const;

	virtual float getWidth() const = 0;
	virtual float getHeight() const = 0;

	ShapeDescription* getDescription() const;
	Geometry* getGeometry() const;
	Graphics* getGraphics() const;

protected:
	Geometry* geometry;
	ShapeDescription* description;
};

#endif