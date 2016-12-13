#ifndef _RECTSHAPE_H
#define _RECTSHAPE_H

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
#ifndef _RECT2D_H
#include "Helpers/Math/Rect2D.h"
#endif

class Renderer;

class RectShape : public Shape, public IFillableShape, public IBoundingBox
{
public:
	RectShape(double left, double top, double width, double height, float lineWidth = 0.5f, const std::tstring& name = _T(""));
	RectShape(const Vector2D& lefttop, const Vector2D& rightbottom, float lineWidth = 0.5f, const std::tstring& name = _T(""));
	RectShape(const Rect2D& rect, float lineWidth = 0.5f, const std::tstring& name = _T(""));
	virtual ~RectShape();

	virtual void setFill(bool fill);
	virtual bool getFill() const;

	virtual void render(Renderer* renderer);

	virtual Rect2D getBoundingBox() const;

private:
	Rect2D rect;
	float line_width;
};

#endif