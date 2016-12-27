#ifndef _LINESHAPEDESCRIPTION_H
#define _LINESHAPEDESCRIPTION_H

#include "Core\Data\Objects\Descriptions\Shapes\ShapeDescription.h"

#ifndef _VECTOR2D_H
#include "Helpers\Math/Vector2D.h"
#endif

class LineShapeDescription : public ShapeDescription
{
public:
	LineShapeDescription();
	LineShapeDescription(const LineShapeDescription& ref);
	LineShapeDescription(float x1, float y1, float x2, float y2, float lineWidth = 0.5f);
	LineShapeDescription(const Vector2D& v1, const Vector2D& v2, float lineWidth = 0.5f);
	virtual ~LineShapeDescription();

	bool operator==(const LineShapeDescription& ref) const;
	bool operator!=(const LineShapeDescription& ref) const;

	LineShapeDescription& operator=(const LineShapeDescription& ref);

	void setStartPosition(const Vector2D& start);
	void setEndPosition(const Vector2D& end);

	const Vector2D& getStartPosition() const;
	const Vector2D& getEndPosition() const;

private:
	Vector2D v1;
	Vector2D v2;
};

#endif