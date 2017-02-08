#ifndef _TRIANGLESHAPE_H
#define _TRIANGLESHAPE_H

#include "Rendering\Objects\RenderItems\Shapes\PolygonShape.h"

#ifndef _TRIANGLESHAPEDESCRIPTION_H
#include "Core\Data\Objects\Descriptions\Shapes\TriangleShapeDescription.h"
#endif

#ifndef _STRING_H
#include "Core\Defines\string.h"
#endif

class Renderer;

class TriangleShape : public PolygonShape
{
public:
	TriangleShape(const std::tstring& name = _T("TriangleShape"));
	TriangleShape(TriangleShapeDescription* desc, const std::tstring& name = _T("TriangleShape"));
	virtual ~TriangleShape();

	virtual void render(Renderer* renderer);

	TriangleShapeDescription* getTriangleShapeDescription() const;

private:
};

#endif