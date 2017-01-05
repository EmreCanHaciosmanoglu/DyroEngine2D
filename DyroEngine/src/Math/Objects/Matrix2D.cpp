#include "Math/Objects/Matrix2D.h"

Matrix2D Matrix2D::ZeroMatrix = Matrix2D();

//------------------------------------------------------------------------------
// Matrix2D Constructors, friend operators, operators, methods, static methods
//------------------------------------------------------------------------------
Matrix2D::Matrix2D(Vector2D dirX, Vector2D dirY, Vector2D orig) : dirX(dirX), dirY(dirY), orig(orig)
{}

Matrix2D::Matrix2D(float e1X, float e1Y, float e2X, float e2Y, float oX, float oY) : dirX(e1X, e1Y), dirY(e2X, e2Y), orig(oX, oY)
{}

Matrix2D::Matrix2D(const Matrix2D& sourceRef) : dirX(sourceRef.dirX), dirY(sourceRef.dirY), orig(sourceRef.orig)
{}

Matrix2D::Matrix2D(const D2D1::Matrix3x2F& mat) : dirX(mat._11, mat._12), dirY(mat._21, mat._22), orig(mat._31, mat._32)
{}

Matrix2D operator*(const Matrix2D& matrix1, const Matrix2D& matrix2)
{
	return Matrix2D(Vector2D(matrix1.dirX.x * matrix2.dirX.x + matrix1.dirX.y * matrix2.dirY.x, matrix1.dirX.x * matrix2.dirX.y + matrix1.dirX.y * matrix2.dirY.y),
		Vector2D(matrix1.dirY.x * matrix2.dirX.x + matrix1.dirY.y * matrix2.dirY.x, matrix1.dirY.x * matrix2.dirX.y + matrix1.dirY.y * matrix2.dirY.y),
		Vector2D(matrix1.orig.x * matrix2.dirX.x + matrix1.orig.y * matrix2.dirY.x + matrix2.orig.x, matrix1.orig.x * matrix2.dirX.y + matrix1.orig.y * matrix2.dirY.y + matrix2.orig.y));
}

std::ostream& operator<<(std::ostream& os, Matrix2D matrix)
{
	os << "Matrix2D( " << matrix.dirX.x << ", " << matrix.dirX.y << ", " << matrix.dirY.x << ", " << matrix.dirY.y << ", " << matrix.orig.x << ", " << matrix.orig.y << " )";

	return os;
}

std::wostream& operator<<(std::wostream& wos, const Matrix2D& matrix)
{
	wos << L"Matrix2D( " << matrix.dirX.x << L", " << matrix.dirX.y << L", " << matrix.dirY.x << L", " << matrix.dirY.y << L", " << matrix.orig.x << L", " << matrix.orig.y << L" )";

	return wos;
}

Vector2D Matrix2D::transformVector(const Vector2D& vector) const
{
	return dirX * vector.x + dirY * vector.y;
}

Vector2D Matrix2D::transformPoint(const Vector2D& point) const
{
	return orig + transformVector(point - Vector2D(0, 0));
}

float Matrix2D::determinant() const
{
	return dirX.x * dirY.y - dirX.y * dirY.x;
}

Matrix2D Matrix2D::inverse() const
{
	//calculate determinant
	float det = determinant();
	//1)calculate matrix of minors
	//2)Use the alternating law of signs to produce the matrix of cofactors
	//3)Transpose
	//4)the inverse matrix is 1/Determinant * the resulting matrix
	return Matrix2D(Vector2D(+dirY.y, -dirX.y) / det,
		Vector2D(-dirY.x, +dirX.x) / det,
		Vector2D(dirY.x * orig.y - dirY.y * orig.x, -(dirX.x * orig.y - dirX.y * orig.x)) / det);
}

bool Matrix2D::equals(const Matrix2D& p) const
{
	return dirX == p.dirX && dirY == p.dirY && orig == p.orig;
}

bool Matrix2D::operator==(const Matrix2D& other) const
{
	return dirX == other.dirX && dirY == other.dirY && orig == other.orig;
}

bool Matrix2D::operator!=(const Matrix2D& other) const
{
	return dirX != other.dirX || dirY != other.dirY || orig != other.orig;
}

const D2D1::Matrix3x2F Matrix2D::toMatrix3x2F() const
{
	D2D1::Matrix3x2F mat;

	mat._11 = (FLOAT)dirX.x;
	mat._12 = (FLOAT)dirX.y;
	mat._21 = (FLOAT)dirY.x;
	mat._22 = (FLOAT)dirY.y;
	mat._31 = (FLOAT)orig.x;
	mat._32 = (FLOAT)orig.y;

	return mat;
}

void Matrix2D::setAsIdentity()
{
	dirX = Vector2D(1, 0);
	dirY = Vector2D(0, 1);
	orig = Vector2D(0, 0);
}

void Matrix2D::setAsRotate(float radians)
{
	dirX = Vector2D(cos(radians), sin(radians));
	dirY = Vector2D(-sin(radians), cos(radians));
	orig = Vector2D(0, 0);
}
void Matrix2D::setAsTranslate(float tx, float ty)
{
	dirX = Vector2D(1, 0);
	dirY = Vector2D(0, 1);
	orig = Vector2D(tx, ty);
}

void Matrix2D::setAsTranslate(Vector2D pt)
{
	dirX = Vector2D(1, 0);
	dirY = Vector2D(0, 1);
	orig = Vector2D(pt.x, pt.y);
}

void Matrix2D::setAsScale(float scaleX, float scaleY)
{
	dirX = Vector2D(scaleX, 0);
	dirY = Vector2D(0, scaleY);
	orig = Vector2D(0, 0);
}

void Matrix2D::setAsScale(float scale)
{
	setAsScale(scale, scale);
}

Matrix2D Matrix2D::createRotationMatrix(float angle)
{
	return Matrix2D(Vector2D(cos(angle), sin(angle)), Vector2D(-sin(angle), cos(angle)), Vector2D());
}

Matrix2D Matrix2D::createIdentityMatrix()
{
	return Matrix2D(Vector2D(1, 0), Vector2D(0, 1), Vector2D());
}

Matrix2D Matrix2D::createScalingMatrix(float scale)
{
	return createScalingMatrix(scale, scale);
}

Matrix2D Matrix2D::createScalingMatrix(Vector2D scaleXY)
{
	return createScalingMatrix(scaleXY.x, scaleXY.y);
}

Matrix2D Matrix2D::createScalingMatrix(float scaleX, float scaleY)
{
	return Matrix2D(Vector2D(scaleX, 0), Vector2D(0, scaleY), Vector2D());
}

Matrix2D Matrix2D::createTranslationMatrix(Vector2D origin)
{
	return Matrix2D(Vector2D(1, 0), Vector2D(0, 1), origin);
}

Matrix2D Matrix2D::createTranslationMatrix(float tx, float ty)
{
	return createTranslationMatrix(Vector2D(tx, ty));
}