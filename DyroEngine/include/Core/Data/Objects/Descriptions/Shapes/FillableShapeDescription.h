#ifndef _FILLABLESHAPEDESCRIPTION_H
#define _FILLABLESHAPEDESCRIPTION_H

#include "Core\Data\Objects\Descriptions\Shapes\ShapeDescription.h"

enum class GeometryType;

class FillableShapeDescription : public ShapeDescription
{
public:
	FillableShapeDescription(GeometryType type);
	FillableShapeDescription(const FillableShapeDescription& ref);
	FillableShapeDescription(GeometryType type, bool fill, const Color& color = Color(), float lineWidth = 0.5f);
	virtual ~FillableShapeDescription();

	bool operator==(const FillableShapeDescription& ref) const;
	bool operator!=(const FillableShapeDescription& ref) const;

	FillableShapeDescription& operator=(const FillableShapeDescription& ref);

	void setFill(bool fill);
	bool getFill() const;

private:
	bool fill;
};

#endif
