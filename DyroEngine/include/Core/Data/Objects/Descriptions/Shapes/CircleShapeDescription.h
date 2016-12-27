#ifndef _CIRCLESHAPEDESCRIPTION_H
#define _CIRCLESHAPEDESCRIPTION_H

#include "Core\Data\Objects\Descriptions\Shapes\ShapeDescription.h"

#ifndef _VECTOR2D_H
#include "Helpers\Math/Vector2D.h"
#endif

class CircleShapeDescription : public ShapeDescription
{
public:
	CircleShapeDescription();
	CircleShapeDescription(const CircleShapeDescription& ref);
	CircleShapeDescription(float xcenter, float ycenter, float r, float lineWidth = 0.5f);
	CircleShapeDescription(const Vector2D& center, float r, float lineWidth = 0.5f);
	virtual ~CircleShapeDescription();

	bool operator==(const CircleShapeDescription& ref) const;
	bool operator!=(const CircleShapeDescription& ref) const;

	CircleShapeDescription& operator=(const CircleShapeDescription& ref);

	void setCenter(const Vector2D& center);
	void setRadius(float radius);

	const Vector2D& getCenter() const;
	float getRadius() const;
private:
	Vector2D center;
	float radius;
};

#endif