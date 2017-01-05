#ifndef _RECTSHAPEDESCRIPTION_H
#define _RECTSHAPEDESCRIPTION_H

#include "Core\Data\Objects\Descriptions\Shapes\FillableShapeDescription.h"

#ifndef _VECTOR2D_H
#include "Math/Objects/Vector2D.h"
#endif
#ifndef _RECT2D_H
#include "Math/Objects/Rect2D.h"
#endif

class RectShapeDescription : public FillableShapeDescription
{
public:
	RectShapeDescription();
	RectShapeDescription(const RectShapeDescription& ref);
	RectShapeDescription(double left, double top, double width, double height, bool fill = true, float lineWidth = 0.5f);
	RectShapeDescription(const Vector2D& lefttop, const Vector2D& rightbottom, bool fill = true, float lineWidth = 0.5f);
	RectShapeDescription(const Rect2D& rect, bool fill = true, float lineWidth = 0.5f);
	virtual ~RectShapeDescription();

	bool operator==(const RectShapeDescription& ref) const;
	bool operator!=(const RectShapeDescription& ref) const;

	RectShapeDescription& operator=(const RectShapeDescription& ref);

	void setRect(const Rect2D& rect);
	const Rect2D& getRect() const;

private:
	Rect2D rect;
};

#endif