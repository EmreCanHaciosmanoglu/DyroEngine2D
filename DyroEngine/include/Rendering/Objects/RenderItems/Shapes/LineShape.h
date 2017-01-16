#ifndef _LINESHAPE_H
#define _LINESHAPE_H

#include "Rendering/Objects/RenderItems/Shapes/Shape.h"

#ifndef _LINESHAPEDESCRIPTION_H
#include "Core\Data\Objects\Descriptions\Shapes\LineShapeDescription.h"
#endif

#ifndef _VECTOR2D_H
#include "Math/Objects/Vector2D.h"
#endif

class Renderer;

class LineShape : public Shape
{
public:
	LineShape(Visualization* parent, const std::tstring& name = _T("Lineshape"));
	LineShape(Visualization* parent, LineShapeDescription* description, const std::tstring& name = _T("LineShape"));
	virtual ~LineShape();

	virtual void create();
	virtual void render(Renderer* renderer);

	virtual float getWidth() const;
	virtual float getHeight() const;

	LineShapeDescription* getLineShapeDescription() const;

private:
};

#endif