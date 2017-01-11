#ifndef _CIRCLESHAPEDESCRIPTION_H
#define _CIRCLESHAPEDESCRIPTION_H

#include "Core\Data\Objects\Descriptions\Shapes\FillableShapeDescription.h"

#ifndef _VECTOR2D_H
#include "Math/Objects/Vector2D.h"
#endif

class CircleShapeDescription : public FillableShapeDescription
{
public:
	CircleShapeDescription();
	CircleShapeDescription(const CircleShapeDescription& ref);
	CircleShapeDescription(float xcenter, float ycenter, float r, bool fill = true, const Color& color = Color(), float lineWidth = 0.5f);
	CircleShapeDescription(const Vector2D& center, float r, bool fill = true, const Color& color = Color(), float lineWidth = 0.5f);
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