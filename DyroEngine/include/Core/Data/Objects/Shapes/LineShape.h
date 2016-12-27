#ifndef _LINESHAPE_H
#define _LINESHAPE_H

#include "Core/Data/Objects/Shapes/Shape.h"

#ifndef _LINESHAPEDESCRIPTION_H
#include "Core\Data\Objects\Descriptions\Shapes\LineShapeDescription.h"
#endif

#ifndef _VECTOR2D_H
#include "Helpers/Math/Vector2D.h"
#endif

class Renderer;

class LineShape : public Shape
{
public:
	LineShape(const std::tstring& name = _T(""));
	LineShape(LineShapeDescription* description, const std::tstring& name = _T(""));
	virtual ~LineShape();

	virtual void render(Renderer* renderer);

	LineShapeDescription* getLineShapeDescription() const;

private:
};

#endif