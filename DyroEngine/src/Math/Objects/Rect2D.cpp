#include "Math/Objects/Rect2D.h"

//Initialize static empty rect2D
const Rect2D Rect2D::empty;

Rect2D::Rect2D()
	: left(0)
	, top(0)
	, right(0)
	, bottom(0)
{
}
Rect2D::Rect2D(const Rect2D& r)
	: left(r.left)
	, top(r.top)
	, right(r.right)
	, bottom(r.bottom)
{
}
Rect2D::Rect2D(double l, double t, double r, double b)
	: left(l)
	, top(t)
	, right(r)
	, bottom(b)
{
}

Rect2D::Rect2D(const Vector2D& v1, const Vector2D& v2)
	: top(v1.y)
	, left(v1.x)
	, bottom(v2.y)
	, right(v2.x)
{
}
Rect2D::~Rect2D()
{}

double Rect2D::getWidth() const
{
	return right - left;
}
double Rect2D::getHeight() const
{
	return bottom - top;
}

Rect2D Rect2D::operator-()const
{
	return Rect2D(-left, -top, -right, -bottom);
}
Rect2D Rect2D::operator+(const Rect2D& rhs) const
{
	return Rect2D(left + rhs.left, top + rhs.top, right + rhs.right, bottom + rhs.bottom);
}
Rect2D Rect2D::operator-(const Rect2D& rhs) const
{
	return Rect2D(left - rhs.left, top - rhs.top, right - rhs.right, bottom - rhs.bottom);
}
Rect2D& Rect2D::operator+=(const Rect2D& rhs)
{
	left += rhs.left;
	top += rhs.top;
	right += rhs.right;
	bottom += rhs.bottom;

	return *this;
}
Rect2D& Rect2D::operator-=(const Rect2D& rhs)
{
	left -= rhs.left;
	top -= rhs.top;
	right -= rhs.right;
	bottom -= rhs.bottom;

	return *this;
}
Rect2D& Rect2D::operator+=(const Vector2D& rhs)
{
	left += rhs.x;
	top += rhs.y;
	right += rhs.x;
	bottom += rhs.y;

	return *this;
}
Rect2D& Rect2D::operator-=(const Vector2D& rhs)
{
	left += rhs.x;
	top += rhs.y;
	right += rhs.x;
	bottom += rhs.y;

	return *this;
}
Rect2D Rect2D::operator*(const float scale) const
{
	return Rect2D(left * scale, top * scale, right * scale, bottom * scale);
}
Rect2D Rect2D::operator*(const Rect2D& rhs) const
{
	return Rect2D(left * rhs.left, top * rhs.top, right * rhs.right, bottom * rhs.bottom);
}
Rect2D& Rect2D::operator*=(const float scale)
{
	left *= scale;
	top *= scale;
	right *= scale;
	bottom *= scale;

	return *this;
}
Rect2D& Rect2D::operator*=(const Vector2D& rhs)
{
	left *= rhs.x;
	top *= rhs.y;
	right *= rhs.x;
	bottom *= rhs.y;

	return *this;
}
Rect2D& Rect2D::operator*=(const Rect2D& rhs)
{
	left *= rhs.left;
	top *= rhs.top;
	right *= rhs.right;
	bottom *= rhs.bottom;

	return *this;
}
Rect2D Rect2D::operator/(const float scale) const
{
	return Rect2D(left / scale, top / scale, right / scale, bottom / scale);
}
Rect2D& Rect2D::operator/=(const float scale)
{
	left /= scale;
	top /= scale;
	right /= scale;
	bottom /= scale;

	return *this;
}
Rect2D Rect2D::operator/(const int scale) const
{
	return Rect2D(left / (float)scale, top / (float)scale, right / (float)scale, bottom / (float)scale);
}
Rect2D& Rect2D::operator/=(const int scale)
{
	left /= (float)scale;
	top /= (float)scale;
	right /= (float)scale;
	bottom /= (float)scale;

	return *this;
}

Rect2D Rect2D::operator/(const Rect2D& rhs) const
{
	return Rect2D(left / rhs.left, top / rhs.top, right / rhs.right, bottom / rhs.bottom);
}
Rect2D& Rect2D::operator/=(const Rect2D& rhs)
{
	left /= rhs.left;
	top /= rhs.top;
	right /= rhs.right;
	bottom /= rhs.bottom;

	return *this;
}
Rect2D& Rect2D::operator/=(const Vector2D& rhs)
{
	left /= rhs.x;
	top /= rhs.y;
	right /= rhs.x;
	bottom /= rhs.y;

	return *this;
}

bool Rect2D::operator== (const Rect2D& other) const
{
	return this->left == other.left && this->right == other.right && this->top == other.top && this->bottom == other.bottom;
}
bool Rect2D::operator!= (const Rect2D& other) const
{
	return this->left != other.left || this->right != other.right || this->top != other.top || this->bottom != other.bottom;
}

bool Rect2D::contains(const Vector2D& point)
{
	return point.x > this->left && point.x < this->right && point.y > this->top && point.y < this->bottom;
}
bool Rect2D::contains(const Rect2D& rect)
{
	return contains(Vector2D((float)rect.left, (float)rect.top)) && contains(Vector2D((float)rect.right, (float)rect.bottom));
}
bool Rect2D::overlaps(const Rect2D& rect)
{
	return contains(Vector2D((float)rect.left, (float)rect.top))
		|| contains(Vector2D((float)rect.right, (float)rect.bottom))
		|| contains(Vector2D((float)rect.left, (float)rect.bottom))
		|| contains(Vector2D((float)rect.right, (float)rect.top));
}

D2D_RECT_F Rect2D::toD2DRect(const Rect2D& other)
{
	D2D_RECT_F d2d_rect;

	d2d_rect.left = (float)other.left;
	d2d_rect.top = (float)other.top;
	d2d_rect.right = (float)other.right;
	d2d_rect.bottom = (float)other.bottom;

	return d2d_rect;
}