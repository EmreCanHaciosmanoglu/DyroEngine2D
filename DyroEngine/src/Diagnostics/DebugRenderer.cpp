#include "Diagnostics\DebugRenderer.h"

#include "Helpers\Singleton.h"
#include "Helpers\Math\Matrix2D.h"

#include "Helpers\Singleton.h"

#include "Core\Settings\WorldSettings.h"
#include "Core\Settings\ApplicationSettings.h"

#include "Core\Rendering\Renderer.h"

#include "SceneGraph\Object\GameObjects\Camera\Manager\CameraManager.h"
#include "SceneGraph\Object\GameObjects\Camera\FreeCamera.h"
#include "SceneGraph\Component\CameraComponent.h"

#include "Defines\programdefaults.h"

DebugRenderer::DebugRenderer()
	:b2Draw()
	,color(255, 255, 255, 187)
{	
	this->mat_scale = Matrix2D::createScalingMatrix(Vector2D((float)constants::BOX2D_SCALE, (float)constants::BOX2D_SCALE));
}
DebugRenderer::~DebugRenderer()
{

}

void DebugRenderer::DrawPoint(const b2Vec2& p, float32 size, const b2Color& color)
{
	Renderer renderer = Singleton<Renderer>::getInstance();
	Matrix2D mat_view = Singleton<CameraManager>::getInstance().getActiveCamera()->getCamera()->getViewMatrix();

	renderer.setTransformMatrix(this->mat_scale * mat_view);
	renderer.setColor(Color(color.r, color.g, color.b, color.a));
	renderer.fillCircle(p.x,p.y, size);
}

void DebugRenderer::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	Renderer renderer = Singleton<Renderer>::getInstance();
	Matrix2D mat_view = Singleton<CameraManager>::getInstance().getActiveCamera()->getCamera()->getViewMatrix();

	std::vector<Vector2D> vertexsArr;
	for (int i = 0; i < vertexCount; i++)
		vertexsArr.push_back(Vector2D(vertices[i].x, vertices[i].y));
	
	renderer.setTransformMatrix(this->mat_scale * mat_view);
	renderer.setColor(Color(color.r, color.g, color.b, color.a));
	renderer.drawPolygon(vertexsArr, true, 1 / constants::BOX2D_SCALE);
}
void DebugRenderer::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	Renderer renderer = Singleton<Renderer>::getInstance();
	Matrix2D mat_view = Singleton<CameraManager>::getInstance().getActiveCamera()->getCamera()->getViewMatrix();

	std::vector<Vector2D> vertexsArr;
	for (int i = 0; i < vertexCount; i++)
		vertexsArr.push_back(Vector2D(vertices[i].x, vertices[i].y));

	renderer.setTransformMatrix(this->mat_scale * mat_view);
	renderer.setColor(Color(color.r, color.g, color.b, color.a));
	renderer.fillPolygon(vertexsArr);
}

void DebugRenderer::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
{
	Renderer renderer = Singleton<Renderer>::getInstance();
	Matrix2D mat_view = Singleton<CameraManager>::getInstance().getActiveCamera()->getCamera()->getViewMatrix();

	renderer.setTransformMatrix(this->mat_scale * mat_view);
	renderer.setColor(Color(color.r, color.g, color.b, color.a));
	renderer.drawCircle(Vector2D(center.x, center.y), radius, 1.0f / constants::BOX2D_SCALE);
}
void DebugRenderer::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
{
	Renderer renderer = Singleton<Renderer>::getInstance();
	Matrix2D mat_view = Singleton<CameraManager>::getInstance().getActiveCamera()->getCamera()->getViewMatrix();

	renderer.setTransformMatrix(this->mat_scale * mat_view);
	renderer.setColor(Color(color.r, color.g, color.b, color.a));
	renderer.fillCircle(Vector2D(center.x, center.y), radius);
}

void DebugRenderer::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
	Renderer renderer = Singleton<Renderer>::getInstance();
	Matrix2D mat_view = Singleton<CameraManager>::getInstance().getActiveCamera()->getCamera()->getViewMatrix();

	renderer.setTransformMatrix(this->mat_scale * mat_view);
	renderer.setColor(Color(color.r, color.g, color.b, color.a));
	renderer.drawLine(Vector2D(p1.x, p1.y), Vector2D(p2.x, p2.y), 1.0f / constants::BOX2D_SCALE);
}

void DebugRenderer::DrawTransform(const b2Transform& xf)
{
	Renderer renderer = Singleton<Renderer>::getInstance();
	Matrix2D mat_view = Singleton<CameraManager>::getInstance().getActiveCamera()->getCamera()->getViewMatrix();

	renderer.setTransformMatrix(this->mat_scale * mat_view);
	renderer.setColor(this->color);

	renderer.setColor(Color(0, 0, 0));
	renderer.drawCircle(Vector2D(xf.p.x, xf.p.y), 2.0f / constants::BOX2D_SCALE, 1.0f / constants::BOX2D_SCALE);

	Vector2D x(xf.q.GetXAxis().x, xf.q.GetXAxis().y);
	x = (x / (float)constants::BOX2D_SCALE) * 20.0f;
	renderer.setColor(Color(1.0f, 0, 0));
	renderer.drawLine(Vector2D(xf.p.x, xf.p.y), Vector2D(xf.p.x, xf.p.y) + x, 1.0f / constants::BOX2D_SCALE);

	Vector2D y(xf.q.GetYAxis().x, xf.q.GetYAxis().y);
	y = (y / (float)constants::BOX2D_SCALE) * 20.0f;
	renderer.setColor(Color(0, 1.0f, 0));
	renderer.drawLine(Vector2D(xf.p.x, xf.p.y), Vector2D(xf.p.x, xf.p.y) + y, 1.0f / constants::BOX2D_SCALE);

}