#ifndef _SHAPECOMPONENT_H
#define _SHAPECOMPONENT_H

#include "SceneGraph/Component/Component.h"

#ifndef _COLOR_H
#include "Defines/color.h"
#endif

class Shape;

class ShapeComponent : public Component
{
public:
	ShapeComponent(Shape* shape, const std::tstring& name = _T(""));
	virtual ~ShapeComponent();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	void setColor(const Color& c);
	const Color& getColor() const;

	void setFill(bool fill);
	bool getFill() const;

	Shape* getShape() const;
private:
	Shape* shape;
};

#endif