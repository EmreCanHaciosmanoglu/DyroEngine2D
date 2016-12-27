#ifndef _POLYGONSHAPE_H
#define _POLYGONSHAPE_H

#include "Core/Data/Objects/Shapes/Shape.h"

#ifndef _IFILLABLESHAPE_H
#include "Interfaces/IFillableShape.h"
#endif
#ifndef _IBOUNDINGBOX_H
#include "Interfaces\IBoundingBox.h"
#endif

#ifndef _POLYGONSHAPEDESCRIPTION_H
#include "Core\Data\Objects\Descriptions\Shapes\PolygonShapeDescription.h"
#endif

#ifndef _VECTOR2D_H
#include "Helpers/Math/Vector2D.h"
#endif

#ifndef _VECTOR_
#include <vector>
#endif

class Renderer;

class PolygonShape : public Shape, public IFillableShape, public IBoundingBox
{
public:
	PolygonShape(const std::tstring& name = _T(""));
	PolygonShape(PolygonShapeDescription* description, const std::tstring& name = _T(""));
	virtual ~PolygonShape();

	virtual void setFill(bool fill);
	virtual bool getFill() const;

	virtual void render(Renderer* renderer);

	PolygonShapeDescription* getPolygonShapeDescription() const;

	virtual Rect2D getBoundingBox() const;

private:
};

#endif
