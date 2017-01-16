#ifndef _SHAPEDESCRIPTION_H
#define _SHAPEDESCRIPTION_H

#ifndef _STRING_H
#include "Core\Defines\string.h"
#endif
#ifndef _COLOR_H
#include "Core\Defines\color.h"
#endif

enum class GeometryType;

class ShapeDescription
{
public:
	ShapeDescription(GeometryType type);
	ShapeDescription(const ShapeDescription& ref);
	ShapeDescription(GeometryType type, const Color& color, float lineWidth = 0.5f);
	virtual ~ShapeDescription();

	bool operator==(const ShapeDescription& ref) const;
	bool operator!=(const ShapeDescription& ref) const;

	ShapeDescription& operator=(const ShapeDescription& ref);

	void setColor(const Color& color);
	void setLineWidth(float lineWidth);

	const Color& getColor() const;
	float getLineWidth() const;

	GeometryType getGeometryType() const;

protected:
	void setGeometryType(GeometryType type);

private:
	GeometryType geometry_type;
	Color color;
	float line_width;
};

#endif