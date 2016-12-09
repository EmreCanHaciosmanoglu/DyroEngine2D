#ifndef _SHAPECOMPONENT_H
#define _SHAPECOMPONENT_H

#include "SceneGraph/Component/Component.h"

#ifndef _IBOUNDINGBOX_H
#include "Interfaces\IBoundingBox.h"
#endif

#ifndef _COLOR_H
#include "Defines/color.h"
#endif

class Shape;

class ShapeComponent : public Component, public IBoundingBox
{
public:
	ShapeComponent(Shape* shape);
	virtual ~ShapeComponent();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	void setColor(const Color& c);
	const Color& getColor() const;

	void setFill(bool fill);
	bool getFill() const;

	Rect2D getBoundingBox() const;
private:
	Shape* shape;
};

#endif