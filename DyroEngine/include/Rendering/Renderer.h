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

class Scene;
class Graphics;
class Image;

class RenderItem;
class Geometry;

struct RenderInfo
{
	RenderInfo()
	{}

	Matrix2D mat_view;
	std::vector<RenderItem*> items;
};

class Renderer
{
public:
	Renderer(Scene* scene);
	virtual ~Renderer();

	Scene* getScene() const;

	void render(const RenderInfo& info);

	void setTransformMatrix(const Matrix2D& transformMatrix);
	void setInterpolationMode(D2D1_BITMAP_INTERPOLATION_MODE i);

	void setColor(const Color& c);
	void setColor(float r, float g, float b, float a = 1.0f);

	void drawGeometry(Geometry* geometry, float lineWidth = 0.5f) const;
	void fillGeometry(Geometry* geometry) const;

	void cacheShape(RenderItem* item);

	bool drawBitmap(const Image* bmpPtr, float opacity = 1.0f) const;
	bool drawBitmap(const Image* bmpPtr, float x, float y, float opacity = 1.0f) const;
	bool drawBitmap(const Image* bmpPtr, const Vector2D& position, float opacity = 1.0f) const;
	bool drawBitmap(const Image* bmpPtr, const Rect2D& srcRect, float opacity = 1.0f) const;
	bool drawBitmap(const Image* bmpPtr, float x, float y, const Rect2D& srcRect, float opacity = 1.0f) const;
	bool drawBitmap(const Image* bmpPtr, const Vector2D& position, const Rect2D& srcRect, float opacity = 1.0f) const;

private:
	D2D1_BITMAP_INTERPOLATION_MODE interpolation_mode;
	Graphics* graphics;
	Scene* scene;
	std::vector<RenderItem*> cached_render_items;
};

#endif // _RENDERER_H