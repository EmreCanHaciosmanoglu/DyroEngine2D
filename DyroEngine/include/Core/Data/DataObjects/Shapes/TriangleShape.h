#ifndef _TRIANGLESHAPE_H
#define _TRIANGLESHAPE_H

#include "Core\Data\DataObjects\Shapes\PolygonShape.h"

class TriangleShape : public PolygonShape
{
public:
	TriangleShape(float xScale = 1.0f, float yScale = 1.0f, float lineWidth = 0.5f, const std::tstring& name = _T(""));
	virtual ~TriangleShape();
};

#endif