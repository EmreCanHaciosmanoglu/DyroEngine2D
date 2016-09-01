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

class Renderer
{
public:
	Renderer();
	~Renderer();

	void setInterpolationMode(D2D1_BITMAP_INTERPOLATION_MODE i) { interpolation_mode = i; }
	
	void setColor(const Color& c);
	void setColor(float r, float g, float b, float a = 1.0f);

	void drawLine(const Vector2D& v1, const Vector2D& v2, float lineWidth = 0.5f);
	void drawLine(float x1, float y1, float x2, float y2, float lineWidth = 0.5f);
	
	void drawRect(double left, double top, double width, double height, float lineWidth = 0.5f);
	void drawRect(const Vector2D& lefttop, const Vector2D& rightbottom, float lineWidth = 0.5f);
	void drawRect(const Rect2D& rect, float lineWidth = 0.5f);
	
	void drawCircle(double xcenter, double ycenter, double r, float lineWidth = 0.5f);
	void drawCircle(const Vector2D& center, double r, float lineWidth = 0.5f);
	
	void drawPolygon(const std::vector<Vector2D>& vecPoints, bool close = true, float lineWidth = 0.5f);
	void drawPolygon(Vector2D* points, int size, bool close = true, float lineWidth = 0.5f);
	
	void fillRect(double left, double top, double width, double height);
	void fillRect(const Vector2D& lefttop, const Vector2D& rightbottom);
	void fillRect(const Rect2D& rect);
	
	void fillCircle(const Vector2D& center, double r);
	void fillCircle(double xcenter, double ycenter, double r);
	
	void fillPolygon(const std::vector<Vector2D>& vecPoints);
	void fillPolygon(Vector2D* points, int size);

private:
	D2D1_BITMAP_INTERPOLATION_MODE interpolation_mode;
	Graphics* graphics;
};

#endif // _RENDERER_H