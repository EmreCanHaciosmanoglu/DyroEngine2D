#ifndef _RENDERER_H
#define _RENDERER_H

#ifndef _WINDOWS_H
#include <Windows.h>
#endif
#ifndef _VECTOR_
#include <vector>
#endif

#ifndef _VECTOR2D_H
#include "Math/Objects/Vector2D.h"
#endif
#ifndef _MATRIX2D_H
#include "Math/Objects/Matrix2D.h"
#endif
#ifndef _RECT2D_H
#include "Math/Objects/Rect2D.h"
#endif

#ifndef _COLOR_H
#include "Core/Defines/color.h"
#endif

class Graphics;
class Image;

class RenderItem;
class Geometry;

class Renderer
{
public:
	Renderer();
	virtual ~Renderer();

	void render(std::vector<RenderItem*>& items);

	void setTransformMatrix(const Matrix2D& transformMatrix);
	void setInterpolationMode(D2D1_BITMAP_INTERPOLATION_MODE i);

	void setColor(const Color& c);
	void setColor(float r, float g, float b, float a = 1.0f);

	void drawGeometry(Geometry* geometry, float lineWidth = 0.5f) const;
	void fillGeometry(Geometry* geometry) const;

	void cacheShape(RenderItem* item);

	bool drawBitmap(const Image* bmpPtr) const;
	bool drawBitmap(const Image* bmpPtr, float x, float y) const;
	bool drawBitmap(const Image* bmpPtr, const Vector2D& position) const;
	bool drawBitmap(const Image* bmpPtr, const Rect2D& srcRect) const;
	bool drawBitmap(const Image* bmpPtr, float x, float y, const Rect2D& srcRect) const;
	bool drawBitmap(const Image* bmpPtr, const Vector2D& position, const Rect2D& srcRect) const;

private:
	D2D1_BITMAP_INTERPOLATION_MODE interpolation_mode;
	Graphics* graphics;
	std::vector<RenderItem*> cached_render_items;
};

#endif // _RENDERER_H