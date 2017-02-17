#include "Core/Data/Factory/GeometryFactory.h"

#include "Math\Objects\Rect2D.h"

#include "Core/Data/Objects/Descriptions/Shapes/CircleShapeDescription.h"
#include "Core/Data/Objects/Descriptions/Shapes/RectShapeDescription.h"
#include "Core/Data/Objects/Descriptions/Shapes/LineShapeDescription.h"
#include "Core/Data/Objects/Descriptions/Shapes/PolygonShapeDescription.h"

#include "Core/Data/Objects/Geometry.h"

#include "Core/System/Manager/SystemManager.h"
#include "Core/System/Objects/Graphics.h"

#include "Core/Types/GeometryType.h"
#include "Core/Types/SystemType.h"

#include "Core/Defines/debug.h"

GeometryFactory::GeometryFactory()
{}
GeometryFactory::~GeometryFactory()
{}

Geometry* GeometryFactory::createGeometry(ShapeDescription* description)
{
	switch (description->getGeometryType())
	{
	case GeometryType::LINE_GEOMETRY:
		return createLineGeometry(description);
		break;
	case GeometryType::CIRCLE_GEOMETRY:
		return createCircleGeometry(description);
		break;
	case GeometryType::POLYGON_GEOMETRY:
		return createPolygonGeometry(description);
		break;
	case GeometryType::RECTANGLE_GEOMETRY:
		return createRectangleGeometry(description);
		break;
	}

	return nullptr;
}

Geometry* GeometryFactory::createRectangleGeometry(ShapeDescription* description)
{
	RectShapeDescription* rect_description = dynamic_cast<RectShapeDescription*>(description);
	Graphics* graphics = SystemManager::getInstance().getSystem<Graphics>();
	HRESULT hr = S_OK;

	//Create the rectangular geometry
	ID2D1RectangleGeometry* rect_geometry;
	hr = graphics->getD2DFactory()->CreateRectangleGeometry(Rect2D::toD2DRect(rect_description->getRect()), &rect_geometry);
	if (SUCCEEDED(hr))
		return new Geometry(rect_geometry, _T("Rectange Geometry"));

	LogManager::getInstance().log(new WarningLog(_T("Rect shape creation failed!"), LOG_INFO));
	return nullptr;
}
Geometry* GeometryFactory::createCircleGeometry(ShapeDescription* description)
{
	CircleShapeDescription* circle_description = dynamic_cast<CircleShapeDescription*>(description);
	Graphics* graphics = SystemManager::getInstance().getSystem<Graphics>();
	HRESULT hr = S_OK;

	D2D1_ELLIPSE ellipse;
	ellipse.point.x = circle_description->getCenter().x;
	ellipse.point.y = circle_description->getCenter().y;

	ellipse.radiusX = circle_description->getRadius();
	ellipse.radiusY = circle_description->getRadius();

	//Create circle geometry
	ID2D1EllipseGeometry* ellipse_geometry;
	hr = graphics->getD2DFactory()->CreateEllipseGeometry(ellipse, &ellipse_geometry);

	if (SUCCEEDED(hr))
		return new Geometry(ellipse_geometry, _T("Ellipse Geometry"));

	LogManager::getInstance().log(new WarningLog(_T("Circle shape creation failed!"), LOG_INFO));
	return nullptr;
}
Geometry* GeometryFactory::createLineGeometry(ShapeDescription* description)
{
	LineShapeDescription* line_description = dynamic_cast<LineShapeDescription*>(description);
	Graphics* graphics = SystemManager::getInstance().getSystem<Graphics>();
	HRESULT hr = S_OK;

	//Create line geometry
	ID2D1PathGeometry* path_geometry;
	hr = graphics->getD2DFactory()->CreatePathGeometry(&path_geometry);
	if (FAILED(hr))
	{
		LogManager::getInstance().log(new WarningLog(_T("Line shape creation failed!"), LOG_INFO));
		return nullptr;
	}

	D2D1_POINT_2F start = Vector2D::toD2DPoint(line_description->getStartPosition());
	D2D1_POINT_2F end = Vector2D::toD2DPoint(line_description->getEndPosition());

	ID2D1GeometrySink *geometry_sink = nullptr;
	hr = path_geometry->Open(&geometry_sink);
	if (FAILED(hr))
	{
		LogManager::getInstance().log(new WarningLog(_T("Line shape creation failed!"), LOG_INFO));
		SafeRelease(geometry_sink);
		return nullptr;
	}

	geometry_sink->BeginFigure(start, D2D1_FIGURE_BEGIN_HOLLOW);
	geometry_sink->AddLine(end);
	geometry_sink->EndFigure(D2D1_FIGURE_END_OPEN);

	hr = geometry_sink->Close();
	if (FAILED(hr))
	{
		LogManager::getInstance().log(new WarningLog(_T("Line shape creation failed!"), LOG_INFO));
		SafeRelease(geometry_sink);
		return nullptr;
	}
	SafeRelease(geometry_sink);

	return new Geometry(path_geometry, _T("Line Geometry"));
}
Geometry* GeometryFactory::createPolygonGeometry(ShapeDescription* description)
{
	PolygonShapeDescription* polygon_description = dynamic_cast<PolygonShapeDescription*>(description);
	Graphics* graphics = SystemManager::getInstance().getSystem<Graphics>();
	HRESULT hr = S_OK;

	//Create polygon geometry
	ID2D1PathGeometry* path_geometry = nullptr;
	hr = graphics->getD2DFactory()->CreatePathGeometry(&path_geometry);
	if (FAILED(hr))
	{
		LogManager::getInstance().log(new WarningLog(_T("Polygon shape creation failed!"), LOG_INFO));
		return nullptr;
	}

	ID2D1GeometrySink* geometry_sink = nullptr;
	path_geometry->Open(&geometry_sink);
	if (FAILED(hr))
	{
		LogManager::getInstance().log(new WarningLog(_T("Polygon shape creation failed!"), LOG_INFO));
		SafeRelease(geometry_sink);
		return nullptr;
	}

	std::vector<Vector2D> points = polygon_description->getPoints();

	geometry_sink->BeginFigure(Vector2D::toD2DPoint(points[0]), D2D1_FIGURE_BEGIN_FILLED);

	for (unsigned int i = 0; i < (unsigned int)points.size(); ++i)
		geometry_sink->AddLine(Vector2D::toD2DPoint(points[i]));

	geometry_sink->EndFigure(polygon_description->getClose() ? D2D1_FIGURE_END_CLOSED : D2D1_FIGURE_END_OPEN);

	hr = geometry_sink->Close();
	if (FAILED(hr))
	{
		LogManager::getInstance().log(new WarningLog(_T("Polygon shape creation failed!"), LOG_INFO));
		SafeRelease(geometry_sink);
		return nullptr;
	}

	SafeRelease(geometry_sink);
	return new Geometry(path_geometry, _T("Polygon Geometry"));
}