#ifndef _RECTSHAPE_H
#define _RECTSHAPE_H

#include "Core/Data/Objects/Shapes/Shape.h"

#ifndef _RECTSHAPEDESCRIPTION_H
#include "Core\Data\Objects\Descriptions\Shapes\RectShapeDescription.h"
#endif

#ifndef _VECTOR2D_H
#include "Helpers/Math/Vector2D.h"
#endif
#ifndef _RECT2D_H
#include "Helpers/Math/Rect2D.h"
#endif

class Renderer;

class RectShape : public Shape
{
public:
	RectShape(const std::tstring& name = _T(""));
	RectShape(RectShapeDescription* desc, const std::tstring& name = _T(""));
	virtual ~RectShape();

	virtual void render(Renderer* renderer);

	RectShapeDescription* getRectShapeDescription() const;

private:
};

#endif