#ifndef _RECTSHAPE_H
#define _RECTSHAPE_H

#include "Rendering/Objects/RenderItems/Shapes/Shape.h"

#ifndef _RECTSHAPEDESCRIPTION_H
#include "Core\Data\Objects\Descriptions\Shapes\RectShapeDescription.h"
#endif

#ifndef _VECTOR2D_H
#include "Math/Objects/Vector2D.h"
#endif
#ifndef _RECT2D_H
#include "Math/Objects/Rect2D.h"
#endif

class Renderer;

class RectShape : public Shape
{
public:
	RectShape(Visualization* parent, const std::tstring& name = _T("RectShape"));
	RectShape(Visualization* parent, RectShapeDescription* desc, const std::tstring& name = _T("RectShape"));
	virtual ~RectShape();

	virtual void create();
	virtual void render(Renderer* renderer);

	virtual float getWidth() const;
	virtual float getHeight() const;

	RectShapeDescription* getRectShapeDescription() const;

private:
};

#endif