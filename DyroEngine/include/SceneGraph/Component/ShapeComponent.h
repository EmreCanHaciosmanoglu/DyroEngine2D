#ifndef _SHAPECOMPONENT_H
#define _SHAPECOMPONENT_H

#include "SceneGraph/Component/Component.h"
#include "Interfaces/IDrawable.h"

class Shape;

class ShapeComponent : public Component, public IDrawable
{
public:
	ShapeComponent(Shape* shape);
	virtual ~ShapeComponent();

	virtual bool initialize();
	virtual void draw();
	virtual void update();
	virtual bool shutdown();

	void setFill(bool fill);
	bool getFill() const;

private:
	Shape* shape;
};

#endif