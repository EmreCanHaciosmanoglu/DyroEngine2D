#ifndef _CIRCLESHAPE_H
#define _CIRCLESHAPE_H

#include "Core/Data/Objects/Shapes/Shape.h"

#ifndef _IFILLABLESHAPE_H
#include "Interfaces/IFillableShape.h"
#endif
#ifndef _IBOUNDINGBOX_H
#include "Interfaces\IBoundingBox.h"
#endif

#ifndef _CIRCLESHAPEDESCRIPTION_H
#include "Core\Data\Objects\Descriptions\Shapes\CircleShapeDescription.h"
#endif


#ifndef _VECTOR2D_H
#include "Helpers/Math/Vector2D.h"
#endif

class Renderer;

class CircleShape : public Shape, public IFillableShape, public IBoundingBox
{
public:
	CircleShape(const std::tstring& name = _T(""));
	CircleShape(CircleShapeDescription* descripion, const std::tstring& name = _T(""));
	virtual ~CircleShape();

	virtual void setFill(bool fill);
	virtual bool getFill() const;

	virtual void render(Renderer* renderer);

	CircleShapeDescription* getCirlceShapeDescription() const;

	virtual Rect2D getBoundingBox() const;

private:
};

#endif