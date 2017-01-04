#ifndef _CIRCLESHAPE_H
#define _CIRCLESHAPE_H

#include "Core/Data/Objects/Shapes/Shape.h"

#ifndef _CIRCLESHAPEDESCRIPTION_H
#include "Core\Data\Objects\Descriptions\Shapes\CircleShapeDescription.h"
#endif


#ifndef _VECTOR2D_H
#include "Helpers/Math/Vector2D.h"
#endif

class Renderer;

class CircleShape : public Shape
{
public:
	CircleShape(const std::tstring& name = _T(""));
	CircleShape(CircleShapeDescription* descripion, const std::tstring& name = _T(""));
	virtual ~CircleShape();

	virtual void render(Renderer* renderer);

	CircleShapeDescription* getCirlceShapeDescription() const;

private:
};

#endif