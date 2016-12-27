#ifndef _RENDERER_H
#define _RENDERER_H

#ifndef _WINDOWS_H
#include <Windows.h>
#endif
#ifndef _VECTOR_
#include <vector>
#endif

#ifndef _VECTOR2D_H
#include "Helpers/Math/Vector2D.h"
#endif
#ifndef _MATRIX2D_H
#include "Helpers/Math/Matrix2D.h"
#endif
#ifndef _RECT2D_H
#include "Helpers/Math/Rect2D.h"
#endif

#ifndef _COLOR_H
#include "Defines/color.h"
#endif

class Graphics;
class Image;

class Renderer
{
public:
	Renderer();
	virtual ~Renderer();

	void setTransformMatrix(const Matrix2D& transformMatrix);
	void setInterpolationMode(D2D1_BITMAP_INTERPOLATION_MODE i);

	void setColor(const Color& c);
	void setColor(float r, float g, float b, float a = 1.0f);

	void drawLine(const Vector2D& v1, const Vector2D& v2, float lineWidth = 0.5f) const;
	void drawLine(float x1, float y1, float x2, float y2, float lineWidth = 0.5f) const;

	void drawRect(float left, float top, float width, float height, float lineWidth = 0.5f) const;
	void drawRect(const Vector2D& lefttop, const Vector2D& rightbottom, float lineWidth = 0.5f) const;
	void drawRect(const Rect2D& rect, float lineWidth = 0.5f) const;

	void drawCircle(float xcenter, float ycenter, float r, float lineWidth = 0.5f) const;
	void drawCircle(const Vector2D& center, float r, float lineWidth = 0.5f) const;

	void drawPolygon(const std::vector<Vector2D>& vecPoints, bool close = true, float lineWidth = 0.5f) const;
	void drawPolygon(Vector2D* points, int size, bool close = true, float lineWidth = 0.5f) const;

	void fillRect(float left, float top, float width, float height) const;
	void fillRect(const Vector2D& lefttop, const Vector2D& rightbottom) const;
	void fillRect(const Rect2D& rect) const;

	void fillCircle(const Vector2D& center, float r) const;
	void fillCircle(float xcenter, float ycenter, float r) const;

	void fillPolygon(const std::vector<Vector2D>& vecPoints) const;
	void fillPolygon(Vector2D* points, int size) const;

	bool drawBitmap(const Image* bmpPtr) const;
	bool drawBitmap(const Image* bmpPtr, float x, float y) const;
	bool drawBitmap(const Image* bmpPtr, const Vector2D& position) const;
	bool drawBitmap(const Image* bmpPtr, const Rect2D& srcRect) const;
	bool drawBitmap(const Image* bmpPtr, float x, float y, const Rect2D& srcRect) const;
	bool drawBitmap(const Image* bmpPtr, const Vector2D& position, const Rect2D& srcRect) const;

private:
	D2D1_BITMAP_INTERPOLATION_MODE interpolation_mode;
	Graphics* graphics;
};

#endif // _RENDERER_H