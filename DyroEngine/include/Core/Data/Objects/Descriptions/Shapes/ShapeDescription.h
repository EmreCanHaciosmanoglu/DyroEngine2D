#ifndef _SHAPEDESCRIPTION_H
#define _SHAPEDESCRIPTION_H

#ifndef _STRING_H
#include "Core\Defines\string.h"
#endif
#ifndef _COLOR_H
#include "Core\Defines\color.h"
#endif

class ShapeDescription
{
public:
	ShapeDescription();
	ShapeDescription(const ShapeDescription& ref);
	ShapeDescription(const Color& color, float lineWidth = 0.5f);
	virtual ~ShapeDescription();

	bool operator==(const ShapeDescription& ref) const;
	bool operator!=(const ShapeDescription& ref) const;

	ShapeDescription& operator=(const ShapeDescription& ref);

	void setColor(const Color& color);
	void setLineWidth(float lineWidth);

	const Color& getColor() const;
	float getLineWidth() const;

	ID2D1Geometry* getGeometry();

protected:
	virtual void createGeometry() = 0;
	void setGeometry(ID2D1Geometry* geometry);

private:
	Color color;
	float line_width;
	ID2D1Geometry* geometry;
};

#endif