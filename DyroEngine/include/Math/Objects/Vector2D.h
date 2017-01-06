#ifndef _VECTOR2D_H
#define _VECTOR2D_H

//C Runtime Header Files
#ifndef _INC_MATH
#include <math.h>
#endif

#ifndef BOX2D_H
#include <Box2D\Box2D.h>
#endif

#pragma region Disable Waring 4172
// Warning 4172
// returning address of local variable or temporary
// A function returns the address of a local variable or temporary object.
// Local variables and temporary objects are destroyed when a function returns, so the address returned is not valid.
//
// C4172.cpp
// compile with: /W1 /LD
// float f = 10;
//
// const float& bar()
// {
//  //try the following line instead
//	// const float& bar()
//	   {
//			return f;   // C4172
//	   }
#pragma warning( disable : 4172 )
#pragma endregion

struct Vector2D
{
public:
	Vector2D()
		: x(0.0)
		, y(0.0)
	{}
	Vector2D(const Vector2D& other)
	{
		x = other.x;
		y = other.y;
	}
	Vector2D(float xPos, float yPos)
		: x(xPos)
		, y(yPos)
	{}
	~Vector2D()
	{}

	float x;
	float y;

	static Vector2D ZeroVector;

	float       Length() const;							// length of a vector
	float       Distance(const Vector2D& vec) const;		// distance between two vectors
	float       Dot(const Vector2D& vec) const;			// dot product
	Vector2D&	 Normalize();								// normalized vector

	// operators
	Vector2D     operator-()const;							// unary operator (negate)
	Vector2D     operator+(const Vector2D& rhs) const;		// add rhs
	Vector2D     operator-(const Vector2D& rhs) const;		// subtract rhs
	Vector2D&    operator+=(const Vector2D& rhs);			// add rhs and update this object
	Vector2D&    operator-=(const Vector2D& rhs);			// subtract rhs and update this object
	Vector2D     operator*(const float scale) const;		// scale
	Vector2D     operator*(const Vector2D& rhs) const;		// multiply each element
	Vector2D&    operator*=(const float scale);			// scale and update this object
	Vector2D&    operator*=(const Vector2D& rhs);			// multiply each element and update this object
	Vector2D     operator/(const float scale) const;		// inverse scale
	Vector2D&    operator/=(const float scale);			// scale and update this object
	Vector2D     operator/(const int scale) const;		// inverse scale
	Vector2D&    operator/=(const int scale);			// scale and update this object

	bool        operator==(const Vector2D& rhs) const;		// exact compare, no epsilon
	bool        operator!=(const Vector2D& rhs) const;		// exact compare, no epsilon
	bool        operator<(const Vector2D& rhs) const;		// comparison for sort

	static b2Vec2		toBox2DVec(const Vector2D& ref);
	static Vector2D     toVector2D(const b2Vec2& ref);

	static Vector2D		randomVector();
	static Vector2D		randomVector(const Vector2D& min, const Vector2D& max);
};

#endif
