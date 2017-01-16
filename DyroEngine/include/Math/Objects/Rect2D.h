#ifndef _RECT2D_H
#define _RECT2D_H

#ifndef _2DUTILL_H
#include "Core/Defines/d2dutill.h"
#endif

#ifndef _VECTOR2D_H
#include "Math/Objects/Vector2D.h"
#endif

//------------------------------------------------------------------------------
// Rect2D Struct
//------------------------------------------------------------------------------
struct Rect2D
{
public:
	Rect2D();
	Rect2D(const Rect2D& r);
	Rect2D(double l, double t, double r, double b);
	Rect2D(const Vector2D& v1, const Vector2D& v2);
	~Rect2D();

	double top;
	double left;
	double bottom;
	double right;

	static const Rect2D empty;

	double getWidth() const;
	double getHeight() const;

	Rect2D     operator-()const;						// unary operator (negate)
	Rect2D     operator+(const Rect2D& rhs) const;		// add rhs
	Rect2D     operator-(const Rect2D& rhs) const;		// subtract rhs
	Rect2D&    operator+=(const Rect2D& rhs);			// add rhs and update this object
	Rect2D&    operator-=(const Rect2D& rhs);			// subtract rhs and update this object
	Rect2D&    operator+=(const Vector2D& rhs);			// add rhs and update this object
	Rect2D&    operator-=(const Vector2D& rhs);			// subtract rhs and update this object
	Rect2D     operator*(const float scale) const;		// scale
	Rect2D     operator*(const Rect2D& rhs) const;		// multiply each element
	Rect2D&    operator*=(const float scale);			// scale and update this object
	Rect2D&    operator*=(const Vector2D& rhs);			// scale and update this object
	Rect2D&    operator*=(const Rect2D& rhs);			// multiply each element and update this object
	Rect2D     operator/(const float scale) const;		// inverse scale
	Rect2D&    operator/=(const float scale);			// scale and update this object
	Rect2D     operator/(const int scale) const;		// inverse scale
	Rect2D&    operator/=(const int scale);				// scale and update this object
	Rect2D     operator/(const Rect2D& rhs) const;		// inverse scale
	Rect2D&    operator/=(const Rect2D& rhs);			// scale and update this object
	Rect2D&    operator/=(const Vector2D& rhs);			// scale and update this object

	bool operator== (const Rect2D& other) const;
	bool operator!= (const Rect2D& other) const;

	static D2D_RECT_F toD2DRect(const Rect2D& other);
};

#endif
