#include "Core/Rendering/Renderer.h"

#include "Core/System/Graphics.h"
#include "Core/System/Manager/SystemManager.h"

#include "Diagnostics/Logger.h"

#include "Defines/assert.h"
#include "Defines/deletemacros.h"

#include "Helpers/Singleton.h"

Renderer::Renderer()
	:interpolation_mode(D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR)
{
}
Renderer::~Renderer()
{
}
void Renderer::setTransformMatrix(const Matrix2D& transformMatrix)
{
	this->graphics->getRenderTarget()->SetTransform(&transformMatrix.toMatrix3x2F());
}
void Renderer::setInterpolationMode(D2D1_BITMAP_INTERPOLATION_MODE i)
{
	interpolation_mode = i; 
}

bool Renderer::initialize()
{
	this->graphics = dynamic_cast<Graphics*>(Singleton<SystemManager>::getInstance().getSystem(SystemType::GRAPHICS_SYSTEM));
	assert(this->graphics != nullptr);

	return true;
}
bool Renderer::shutdown()
{
	return true;
}

void Renderer::setColor(const Color& c)
{
	this->graphics->getColorBrush()->SetColor(D2D1::ColorF(c.red, c.green, c.blue, c.alpha));
}
void Renderer::setColor(float r, float g, float b, float a)
{
	setColor(Color(r, g, b, a));
}

void Renderer::drawLine(const Vector2D& v1, const Vector2D& v2, float lineWidth)
{
	D2D1_POINT_2F p1, p2;
	p1.x = (FLOAT)v1.x; p1.y = (FLOAT)v1.y;
	p2.x = (FLOAT)v2.x; p2.y = (FLOAT)v2.y;

	this->graphics->getRenderTarget()->DrawLine(p1, p2, this->graphics->getColorBrush(), lineWidth);
}
void Renderer::drawLine(float x1, float y1, float x2, float y2, float lineWidth)
{
	Vector2D v1(x1, y1);
	Vector2D v2(x2, y2);

	drawLine(v1, v2, lineWidth);
}

void Renderer::drawRect(double left, double top, double width, double height, float lineWidth)
{
	drawRect(Rect2D(left, top, left + width, top + height), lineWidth);
}
void Renderer::drawRect(const Vector2D& lefttop, const Vector2D& rightbottom, float lineWidth)
{
	drawRect(Rect2D(lefttop, rightbottom), lineWidth);
}
void Renderer::drawRect(const Rect2D& rect, float lineWidth)
{
	D2D1_RECT_F d2dRect = D2D1::RectF((FLOAT)rect.left, (FLOAT)rect.top, (FLOAT)rect.right, (FLOAT)rect.bottom);
	this->graphics->getRenderTarget()->DrawRectangle(d2dRect, this->graphics->getColorBrush(), lineWidth);
}

void Renderer::drawCircle(double xcenter, double ycenter, double r, float lineWidth)
{
	D2D1_ELLIPSE ellipse = D2D1::Ellipse(D2D1::Point2((FLOAT)xcenter, (FLOAT)ycenter), (FLOAT)r, (FLOAT)r);
	this->graphics->getRenderTarget()->DrawEllipse(ellipse, this->graphics->getColorBrush(), lineWidth);
}
void Renderer::drawCircle(const Vector2D& center, double r, float lineWidth)
{
	drawCircle(center.x, center.y, r, lineWidth);
}

void Renderer::drawPolygon(const std::vector<Vector2D>& vecPoints, bool close, float lineWidth)
{
	Vector2D* points = new Vector2D[(int)vecPoints.size()];
	for (int i = 0; i < (int)vecPoints.size(); ++i)
		points[i] = vecPoints[i];

	drawPolygon(points, vecPoints.size(), close, lineWidth);
}
void Renderer::drawPolygon(Vector2D* points, int size, bool close, float lineWidth)
{
	//Do not draw an empty polygon
	if (size < 3)
		return;

	for (int countloop = 0; countloop < size - 1; ++countloop)
		drawLine(points[countloop], points[countloop + 1], lineWidth);

	if (close)
		drawLine(points[0], points[size - 1], lineWidth);
}

void Renderer::fillRect(double left, double top, double width, double height)
{
	fillRect(Rect2D(left, top, left + width, top + height));
}
void Renderer::fillRect(const Vector2D& lefttop, const Vector2D& rightbottom)
{
	fillRect(Rect2D(lefttop, rightbottom));
}
void Renderer::fillRect(const Rect2D& rect)
{
	D2D1_RECT_F d2dRect = D2D1::RectF((FLOAT)rect.left, (FLOAT)rect.top, (FLOAT)rect.right, (FLOAT)rect.bottom);
	this->graphics->getRenderTarget()->FillRectangle(d2dRect, this->graphics->getColorBrush());
}

void Renderer::fillCircle(const Vector2D& center, double r)
{
	fillCircle(center.x, center.y, r);
}
void Renderer::fillCircle(double xcenter, double ycenter, double r)
{
	D2D1_ELLIPSE ellipse = D2D1::Ellipse(D2D1::Point2((FLOAT)xcenter, (FLOAT)ycenter), (FLOAT)r, (FLOAT)r);
	this->graphics->getRenderTarget()->FillEllipse(ellipse, this->graphics->getColorBrush());
}

void Renderer::fillPolygon(const std::vector<Vector2D>& vecPoints)
{
	Vector2D* points = new Vector2D[(int)vecPoints.size()];
	for (int i = 0; i < (int)vecPoints.size(); ++i)
		points[i] = vecPoints[i];

	fillPolygon(points, vecPoints.size());
}
void Renderer::fillPolygon(Vector2D* points, int size)
{
	if (size < 3)
		return;

	HRESULT hr;

	ID2D1PathGeometry* pGeometry = nullptr;
	hr = this->graphics->getD2DFactory()->CreatePathGeometry(&pGeometry);
	if (FAILED(hr))
	{
		SafeRelease(pGeometry);
		Singleton<Logger>::getInstance().log(_T("Failed to create path geometry"),LOGTYPE_WARNING);
		return;
	}

	//Write to the path geometry using the geometry sink
	ID2D1GeometrySink* pGeometrySink = nullptr;
	hr = pGeometry->Open(&pGeometrySink);
	if (FAILED(hr))
	{
		SafeRelease(pGeometrySink);
		SafeRelease(pGeometry);
		Singleton<Logger>::getInstance().log(_T("Failed to create geometry sink"),LOGTYPE_WARNING);
		return;
	}

	if (SUCCEEDED(hr))
	{
		pGeometrySink->BeginFigure(D2D1::Point2F((FLOAT)points[0].x, (FLOAT)points[0].y), D2D1_FIGURE_BEGIN_FILLED);

		for (int i = 0; i < size; ++i)
			pGeometrySink->AddLine(D2D1::Point2F((FLOAT)points[i].x, (FLOAT)points[0].y));

		pGeometrySink->EndFigure(D2D1_FIGURE_END_CLOSED);

		hr = pGeometrySink->Close();
		SafeRelease(pGeometrySink);
	}

	if (SUCCEEDED(hr))
	{
		this->graphics->getRenderTarget()->FillGeometry(pGeometry, this->graphics->getColorBrush());
		SafeRelease(pGeometry);
		return;
	}

	SafeRelease(pGeometry);
}