#ifndef _POLYGONSHAPE_H
#define _POLYGONSHAPE_H

#include "Rendering/Objects/RenderItems/Shapes/Shape.h"

#ifndef _POLYGONSHAPEDESCRIPTION_H
#include "Core\Data\Objects\Descriptions\Shapes\PolygonShapeDescription.h"
#endif

#ifndef _VECTOR2D_H
#include "Math/Objects/Vector2D.h"
#endif

#ifndef _VECTOR_
#include <vector>
#endif

class Renderer;

class PolygonShape : public Shape
{
public:
	PolygonShape(Visualization* parent, const std::tstring& name = _T("PolygonShape"));
	PolygonShape(Visualization* parent, PolygonShapeDescription* description, const std::tstring& name = _T("PolygonShape"));
	virtual ~PolygonShape();

	virtual void create();
	virtual void render(Renderer* renderer);

	virtual float getWidth() const;
	virtual float getHeight() const;

	PolygonShapeDescription* getPolygonShapeDescription() const;

private:
};

#endif
