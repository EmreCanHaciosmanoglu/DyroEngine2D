#ifndef _TRIANGLESHAPEDESCRIPTION_H
#define _TRIANGLESHAPEDESCRIPTION_H

#include "Core\Data\Objects\Descriptions\Shapes\PolygonShapeDescription.h"

class TriangleShapeDescription : public PolygonShapeDescription
{
public:
	TriangleShapeDescription();
	TriangleShapeDescription(const TriangleShapeDescription& ref);
	TriangleShapeDescription(float xScale, float yScale, bool fill, float lineWidth = 0.5f);
	virtual ~TriangleShapeDescription();

	bool operator==(const TriangleShapeDescription& ref) const;
	bool operator!=(const TriangleShapeDescription& ref) const;

	TriangleShapeDescription& operator=(const TriangleShapeDescription& ref);

	void setXScale(float scale);
	void setYScale(float scale);

	float getXScale() const;
	float getYScale() const;
private:
	float x_scale;
	float y_scale;
};

#endif