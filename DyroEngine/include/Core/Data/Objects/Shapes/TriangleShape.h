#ifndef _TRIANGLESHAPE_H
#define _TRIANGLESHAPE_H

#include "Core\Data\Objects\Shapes\PolygonShape.h"

#ifndef _TRIANGLESHAPEDESCRIPTION_H
#include "Core\Data\Objects\Descriptions\Shapes\TriangleShapeDescription.h"
#endif

#ifndef _STRING_H
#include "Defines\string.h"
#endif

class TriangleShape : public PolygonShape
{
public:
	TriangleShape(const std::tstring& name = _T(""));
	TriangleShape(TriangleShapeDescription* desc, const std::tstring& name = _T(""));
	virtual ~TriangleShape();

	TriangleShapeDescription* getTriangleShapeDescription() const;

private:
};

#endif