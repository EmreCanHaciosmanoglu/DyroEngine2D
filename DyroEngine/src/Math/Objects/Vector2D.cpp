#include "Math/Objects/Vector2D.h"

Vector2D Vector2D::ZeroVector = Vector2D(0,0);

float Vector2D::Length() const
{
	return sqrtf((float)x*(float)x + (float)y*(float)y);
}
float Vector2D::Distance(const Vector2D& vec) const
{
	return sqrtf(((float)vec.x - (float)x)*((float)vec.x - (float)x) + ((float)vec.y - (float)y)*((float)vec.y - (float)y));
}
Vector2D& Vector2D::Normalize()
{
	float xxyy = x*x + y*y;
	float invLength = 1.0f / sqrtf((float)xxyy);
	x *= invLength;
	y *= invLength;
	return *this;
}
float Vector2D::Dot(const Vector2D& rhs) const
{
	return (x*rhs.x + y*rhs.y);
}
Vector2D Vector2D::operator-() const
{
	return Vector2D(-x, -y);
}

Vector2D Vector2D::operator+(const Vector2D& rhs) const
{
	return Vector2D(x + rhs.x, y + rhs.y);
}
Vector2D Vector2D::operator-(const Vector2D& rhs) const
{
	return Vector2D(x - rhs.x, y - rhs.y);
}
Vector2D& Vector2D::operator+=(const Vector2D& rhs)
{
	x += rhs.x; y += rhs.y; return *this;
}
Vector2D& Vector2D::operator-=(const Vector2D& rhs)
{
	x -= rhs.x; y -= rhs.y; return *this;
}

Vector2D Vector2D::operator*(const float a) const
{
	return Vector2D(x*a, y*a);
}
Vector2D Vector2D::operator*(const Vector2D& rhs) const
{
	return Vector2D(x*rhs.x, y*rhs.y);
}
Vector2D& Vector2D::operator*=(const float a)
{
	x *= a; y *= a; return *this;
}
Vector2D& Vector2D::operator*=(const Vector2D& rhs)
{
	x *= rhs.x; y *= rhs.y; return *this;
}
Vector2D Vector2D::operator/(const float a) const
{
	return Vector2D(x / a, y / a);
}
Vector2D& Vector2D::operator/=(const float a)
{
	x /= a; y /= a; return *this;
}
Vector2D Vector2D::operator/(const int a) const
{
	return Vector2D(x / a, y / a);
}
Vector2D& Vector2D::operator/=(const int a)
{
	x /= a; y /= a; return *this;
}

bool Vector2D::operator==(const Vector2D& rhs) const
{
	return (x == rhs.x) && (y == rhs.y);
}
bool Vector2D::operator!=(const Vector2D& rhs) const
{
	return (x != rhs.x) || (y != rhs.y);
}

bool Vector2D::operator<(const Vector2D& rhs) const
{
	if (x < rhs.x) return true;
	if (x > rhs.x) return false;
	if (y < rhs.y) return true;
	if (y > rhs.y) return false;
	return false;
}

b2Vec2 Vector2D::toBox2DVec(const Vector2D& ref)
{
	return b2Vec2(ref.x, ref.y);
}
Vector2D Vector2D::toVector2D(const b2Vec2& ref)
{
	return Vector2D(ref.x, ref.y);
}

Vector2D Vector2D::randomVector()
{
	return Vector2D((float)rand(), (float)rand());
}
Vector2D Vector2D::randomVector(const Vector2D& min, const Vector2D& max)
{
	float x = (float)fmod(rand(), max.x) + min.x;
	float y = (float)fmod(rand(), max.y) + min.y;

	return Vector2D(x, y);
}