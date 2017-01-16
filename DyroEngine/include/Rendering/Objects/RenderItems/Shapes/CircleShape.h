#ifndef _CIRCLESHAPE_H
#define _CIRCLESHAPE_H

#include "Rendering/Objects/RenderItems/Shapes/Shape.h"

#ifndef _CIRCLESHAPEDESCRIPTION_H
#include "Core\Data\Objects\Descriptions\Shapes\CircleShapeDescription.h"
#endif


#ifndef _VECTOR2D_H
#include "Math/Objects/Vector2D.h"
#endif

class Renderer;

class CircleShape : public Shape
{
public:
	CircleShape(Visualization* parent, const std::tstring& name = _T("CircleShape"));
	CircleShape(Visualization* parent, CircleShapeDescription* descripion, const std::tstring& name = _T("CircleShape"));
	virtual ~CircleShape();

	virtual void create();
	virtual void render(Renderer* renderer);

	virtual float getWidth() const;
	virtual float getHeight() const;

	CircleShapeDescription* getCirlceShapeDescription() const;

private:
};

#endif