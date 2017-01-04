#ifndef _SHAPECOMPONENT_H
#define _SHAPECOMPONENT_H

#include "SceneGraph/Component/Component.h"

#ifndef _COLOR_H
#include "Defines/color.h"
#endif

class ShapeDescription;

class ShapeComponent : public Component
{
	/**
	\note Must be present in every subclass definition.
	*/
	OBJECT_STATICS("ShapeComponent")

public:
	ShapeComponent(ShapeDescription* description, const std::tstring& name = _T(""));
	virtual ~ShapeComponent();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	void setColor(const Color& c);
	void setLineWidth(float width);

	const Color& getColor() const;
	float getLineWidth() const;

protected:
	ShapeDescription* getDescription() const;

private:
	ShapeDescription* description;
};

#endif