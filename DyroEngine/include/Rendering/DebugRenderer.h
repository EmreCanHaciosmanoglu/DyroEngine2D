#ifndef _DEBUGRENDERER_H
#define _DEBUGRENDERER_H

#ifndef BOX2D_H
#include <Box2D\Box2D.h>
#endif

#ifndef _COLOR_H
#include "Core\Defines\color.h"
#endif
#ifndef _MATRIX2D_H
#include "Math/Objects/Matrix2D.h"
#endif

class Scene;

class DebugRenderer : public b2Draw
{
public:
	DebugRenderer();
	virtual ~DebugRenderer();

	DebugRenderer(const DebugRenderer&) = delete;
	DebugRenderer& operator=(const DebugRenderer&) = delete;

	void DrawPoint(const b2Vec2& p, float32 size, const b2Color& color);

	void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
	void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

	void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
	void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);

	void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);

	void DrawTransform(const b2Transform& xf);

private:

	Color color;
	Matrix2D mat_scale;
};

#endif