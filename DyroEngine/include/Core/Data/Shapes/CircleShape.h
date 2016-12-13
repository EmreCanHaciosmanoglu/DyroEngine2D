#ifndef _CIRCLESHAPE_H
#define _CIRCLESHAPE_H

#include "Core/Data/Shapes/Shape.h"
#ifndef _IFILLABLESHAPE_H
#include "Interfaces/IFillableShape.h"
#endif
#ifndef _IBOUNDINGBOX_H
#include "Interfaces\IBoundingBox.h"
#endif

#ifndef _VECTOR2D_H
#include "Helpers/Math/Vector2D.h"
#endif

class Renderer;

class CircleShape : public Shape, public IFillableShape, public IBoundingBox
{
public:
	CircleShape(float xcenter, float ycenter, float r, float lineWidth = 0.5f, const std::tstring& name = _T(""));
	CircleShape(const Vector2D& center, float r, float lineWidth = 0.5f, const std::tstring& name = _T(""));
	virtual ~CircleShape();

	virtual void setFill(bool fill);
	virtual bool getFill() const;

	virtual void render(Renderer* renderer);

	virtual Rect2D getBoundingBox() const;
private:
	Vector2D center;
	float radius;
	float line_width;
};

#endif