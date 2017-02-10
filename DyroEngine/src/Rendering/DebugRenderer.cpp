#include "Rendering\DebugRenderer.h"
#include "Rendering\Renderer.h"

#include "Rendering\Objects\RenderItems\Shapes\CircleShape.h"
#include "Rendering\Objects\RenderItems\Shapes\LineShape.h"
#include "Rendering\Objects\RenderItems\Shapes\PolygonShape.h"
#include "Rendering\Objects\RenderItems\Shapes\RectShape.h"

#include "Math/Objects/Matrix2D.h"

#include "Core\Data/Objects/Settings\ApplicationSettings.h"

#include "Core/Data/Objects/Descriptions/Shapes/CircleShapeDescription.h"
#include "Core/Data/Objects/Descriptions/Shapes/LineShapeDescription.h"
#include "Core/Data/Objects/Descriptions/Shapes/PolygonShapeDescription.h"
#include "Core/Data/Objects/Descriptions/Shapes/RectShapeDescription.h"

#include "Core\Data\Manager\LayerManager.h"
#include "Core\Data\Manager\GeometryManager.h"

#include "Core/Types/GeometryType.h"

#include "SceneGraph\Manager\CameraManager.h"
#include "SceneGraph\Objects\GameObjects\Camera\FreeCamera.h"
#include "SceneGraph\Objects\Components\CameraComponent.h"
#include "SceneGraph\Objects\Scenes\Scene.h"

#include "Core/Defines\programdefaults.h"

DebugRenderer::DebugRenderer(Renderer* r)
	:b2Draw()
	, color(255, 255, 255, 187)
	, renderer(r)
{
	this->mat_scale = Matrix2D::createScalingMatrix(Vector2D((float)constants::BOX2D_SCALE, (float)constants::BOX2D_SCALE));
}
DebugRenderer::~DebugRenderer()
{
}

void DebugRenderer::DrawPoint(const b2Vec2& p, float32 size, const b2Color& color)
{
	Scene* scene = this->renderer->getScene();

	Matrix2D mat_view = scene->getManager<CameraManager>()->getActiveCamera()->getCamera()->getViewMatrix();
	CircleShapeDescription* description = new CircleShapeDescription(p.x, p.y, size, true, Color(color.r, color.g, color.b, color.a));
	Geometry* geometry = scene->getManager<GeometryManager>()->getGeometry(description);
	CircleShape* shape = new CircleShape(description, geometry, _T("Debug Point"));
	shape->setTransform(this->mat_scale);
	shape->setLayer(scene->getManager<LayerManager>()->getLayer(_T("Debug")));

	this->renderer->cacheShape(shape);
}

void DebugRenderer::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	Scene* scene = this->renderer->getScene();

	 Matrix2D mat_view = scene->getManager<CameraManager>()->getActiveCamera()->getCamera()->getViewMatrix();
	std::vector<Vector2D> vertexArr;
	for (int i = 0; i < vertexCount; i++)
		vertexArr.push_back(Vector2D(vertices[i].x, vertices[i].y));

	PolygonShapeDescription* description = new PolygonShapeDescription(vertexArr, true, false, Color(color.r, color.g, color.b, color.a), 1/constants::BOX2D_SCALE);
	Geometry* geometry = scene->getManager<GeometryManager>()->getGeometry(description);
	PolygonShape* shape = new PolygonShape(description, geometry);
	shape->setTransform(this->mat_scale);
	shape->setLayer(scene->getManager<LayerManager>()->getLayer(_T("Debug")));

	this->renderer->cacheShape(shape);
}
void DebugRenderer::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	Scene* scene = this->renderer->getScene();

	 Matrix2D mat_view = scene->getManager<CameraManager>()->getActiveCamera()->getCamera()->getViewMatrix();
	std::vector<Vector2D> vertexArr;
	for (int i = 0; i < vertexCount; i++)
		vertexArr.push_back(Vector2D(vertices[i].x, vertices[i].y));

	PolygonShapeDescription* description = new PolygonShapeDescription(vertexArr, true, true, Color(color.r, color.g, color.b, color.a), 1 / constants::BOX2D_SCALE);
	Geometry* geometry = scene->getManager<GeometryManager>()->getGeometry(description);
	PolygonShape* shape = new PolygonShape(description, geometry);
	shape->setTransform(this->mat_scale);
	shape->setLayer(scene->getManager<LayerManager>()->getLayer(_T("Debug")));

	this->renderer->cacheShape(shape);
}

void DebugRenderer::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
{
	Scene* scene = this->renderer->getScene();

	 Matrix2D mat_view = scene->getManager<CameraManager>()->getActiveCamera()->getCamera()->getViewMatrix();
	CircleShapeDescription* description = new CircleShapeDescription(center.x, center.y, radius, false, Color(color.r, color.g, color.b, color.a), 1 / constants::BOX2D_SCALE);
	Geometry* geometry = scene->getManager<GeometryManager>()->getGeometry(description);
	CircleShape* shape = new CircleShape(description, geometry);
	shape->setTransform(this->mat_scale);
	shape->setLayer(scene->getManager<LayerManager>()->getLayer(_T("Debug")));

	this->renderer->cacheShape(shape);
}
void DebugRenderer::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
{
	Scene* scene = this->renderer->getScene();

	 Matrix2D mat_view = scene->getManager<CameraManager>()->getActiveCamera()->getCamera()->getViewMatrix();
	CircleShapeDescription* description = new CircleShapeDescription(center.x, center.y, radius, true, Color(color.r, color.g, color.b, color.a), 1 / constants::BOX2D_SCALE);
	Geometry* geometry = scene->getManager<GeometryManager>()->getGeometry(description);
	CircleShape* shape = new CircleShape(description, geometry);
	shape->setTransform(this->mat_scale);
	shape->setLayer(scene->getManager<LayerManager>()->getLayer(_T("Debug")));

	this->renderer->cacheShape(shape);
}

void DebugRenderer::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
	Scene* scene = this->renderer->getScene();

	 Matrix2D mat_view = scene->getManager<CameraManager>()->getActiveCamera()->getCamera()->getViewMatrix();
	LineShapeDescription* description = new LineShapeDescription(Vector2D(p1.x, p1.y), Vector2D(p2.x, p2.y), Color(color.r, color.g, color.b, color.a), 1.0f / constants::BOX2D_SCALE);
	Geometry* geometry = scene->getManager<GeometryManager>()->getGeometry(description);
	LineShape* shape = new LineShape(description,geometry);
	shape->setTransform(this->mat_scale);
	shape->setLayer(scene->getManager<LayerManager>()->getLayer(_T("Debug")));

	this->renderer->cacheShape(shape);
}

void DebugRenderer::DrawTransform(const b2Transform& xf)
{
	Scene* scene = this->renderer->getScene();

	 Matrix2D mat_view = scene->getManager<CameraManager>()->getActiveCamera()->getCamera()->getViewMatrix();
	CircleShapeDescription* circle_description = new CircleShapeDescription(Vector2D(xf.p.x, xf.p.y), 2.0f / constants::BOX2D_SCALE, false, Color(0, 0, 0), 1 / constants::BOX2D_SCALE);
	Geometry* circle_geometry = scene->getManager<GeometryManager>()->getGeometry(circle_description);
	CircleShape* circle_shape = new CircleShape(circle_description, circle_geometry);
	circle_shape->setTransform(this->mat_scale);
	circle_shape->setLayer(scene->getManager<LayerManager>()->getLayer(_T("Debug")));

	this->renderer->cacheShape(circle_shape);

	Vector2D x(xf.q.GetXAxis().x, xf.q.GetXAxis().y);
	x = (x / (float)constants::BOX2D_SCALE) * 20.0f;
	LineShapeDescription* x_axis_description = new LineShapeDescription(Vector2D(xf.p.x, xf.p.y), Vector2D(xf.p.x, xf.p.y) + x, Color(1.0f, 0, 0), 1.0f / constants::BOX2D_SCALE);;
	Geometry* x_axis_geometry = scene->getManager<GeometryManager>()->getGeometry(x_axis_description);
	LineShape* x_axis_shape = new LineShape(x_axis_description, x_axis_geometry);
	x_axis_shape->setTransform(this->mat_scale);
	x_axis_shape->setLayer(scene->getManager<LayerManager>()->getLayer(_T("Debug")));

	this->renderer->cacheShape(x_axis_shape);

	Vector2D y(xf.q.GetYAxis().x, xf.q.GetYAxis().y);
	y = (y / (float)constants::BOX2D_SCALE) * 20.0f;
	LineShapeDescription* y_axis_description = new LineShapeDescription(Vector2D(xf.p.x, xf.p.y), Vector2D(xf.p.x, xf.p.y) + y, Color(0, 1.0f, 0), 1.0f / constants::BOX2D_SCALE);;
	Geometry* y_axis_geometry = scene->getManager<GeometryManager>()->getGeometry(y_axis_description);
	LineShape* y_axis_shape = new LineShape(y_axis_description, y_axis_geometry);
	y_axis_shape->setTransform(this->mat_scale);
	y_axis_shape->setLayer(scene->getManager<LayerManager>()->getLayer(_T("Debug")));

	this->renderer->cacheShape(y_axis_shape);
}