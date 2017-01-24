#include "Rendering/Renderer.h"
#include "Rendering/Objects/RenderItems/RenderItem.h"

#include "Core\Data\Objects\Layer.h"
#include "Core\Data\Objects\Geometry.h"

#include "Core/System/Objects/Graphics.h"
#include "Core/System/Manager/SystemManager.h"

#include "Core/Data/Objects/Resources/Image.h"

#include "Core/Defines/debug.h"

#include "Core/Defines/assert.h"
#include "Core/Defines/deletemacros.h"

Renderer::Renderer()
	:interpolation_mode(D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR)
{
	this->graphics = dynamic_cast<Graphics*>(SystemManager::getInstance().getSystem(SystemType::GRAPHICS_SYSTEM));
	assert(this->graphics != nullptr);
}
Renderer::~Renderer()
{
}

void Renderer::render(std::vector<RenderItem*>& items)
{
	//Sort the render items
	std::sort(items.begin(), items.end(),
		[](RenderItem* i1, RenderItem* i2) -> bool
	{
		return i1->getLayer()->getID() < i2->getLayer()->getID();
	});

	this->graphics->beginDraw();
	this->graphics->clear();

	//Render the render items
	for (RenderItem* item : items)
	{
		setTransformMatrix(item->getTransform());
		item->render(this);
	}

	this->graphics->endDraw();
}

void Renderer::setTransformMatrix(const Matrix2D& transformMatrix)
{
	this->graphics->getRenderTarget()->SetTransform(&transformMatrix.toMatrix3x2F());
}
void Renderer::setInterpolationMode(D2D1_BITMAP_INTERPOLATION_MODE i)
{
	interpolation_mode = i;
}

void Renderer::setColor(const Color& c)
{
	this->graphics->getColorBrush()->SetColor(D2D1::ColorF(c.red, c.green, c.blue, c.alpha));
}
void Renderer::setColor(float r, float g, float b, float a)
{
	setColor(Color(r, g, b, a));
}

void Renderer::drawGeometry(Geometry* geometry, float lineWidth) const
{
	this->graphics->getRenderTarget()->DrawGeometry(geometry->getGeometry(), this->graphics->getColorBrush(), lineWidth);
}

void Renderer::drawLine(const Vector2D& v1, const Vector2D& v2, float lineWidth) const
{
	D2D1_POINT_2F p1, p2;
	p1.x = (FLOAT)v1.x; p1.y = (FLOAT)v1.y;
	p2.x = (FLOAT)v2.x; p2.y = (FLOAT)v2.y;

	this->graphics->getRenderTarget()->DrawLine(p1, p2, this->graphics->getColorBrush(), lineWidth);
}
void Renderer::drawLine(float x1, float y1, float x2, float y2, float lineWidth) const
{
	Vector2D v1(x1, y1);
	Vector2D v2(x2, y2);

	drawLine(v1, v2, lineWidth);
}

void Renderer::drawRect(float left, float top, float width, float height, float lineWidth) const
{
	drawRect(Rect2D(left, top, left + width, top + height), lineWidth);
}
void Renderer::drawRect(const Vector2D& lefttop, const Vector2D& rightbottom, float lineWidth) const
{
	drawRect(Rect2D(lefttop, rightbottom), lineWidth);
}
void Renderer::drawRect(const Rect2D& rect, float lineWidth) const
{
	D2D1_RECT_F d2dRect = D2D1::RectF((FLOAT)rect.left - (FLOAT)rect.getWidth() / 2, (FLOAT)rect.top - (FLOAT)rect.getHeight() / 2, (FLOAT)rect.right - (FLOAT)rect.getWidth() / 2, (FLOAT)rect.bottom - (FLOAT)rect.getHeight() / 2);
	this->graphics->getRenderTarget()->DrawRectangle(d2dRect, this->graphics->getColorBrush(), lineWidth);
}

void Renderer::drawCircle(float xcenter, float ycenter, float r, float lineWidth) const
{
	D2D1_ELLIPSE ellipse = D2D1::Ellipse(D2D1::Point2((FLOAT)xcenter, (FLOAT)ycenter), (FLOAT)r, (FLOAT)r);
	this->graphics->getRenderTarget()->DrawEllipse(ellipse, this->graphics->getColorBrush(), lineWidth);
}
void Renderer::drawCircle(const Vector2D& center, float r, float lineWidth) const
{
	drawCircle(center.x, center.y, r, lineWidth);
}

void Renderer::drawPolygon(const std::vector<Vector2D>& vecPoints, bool close, float lineWidth) const
{
	Vector2D* points = new Vector2D[(int)vecPoints.size()];
	for (int i = 0; i < (int)vecPoints.size(); ++i)
		points[i] = vecPoints[i];

	drawPolygon(points, vecPoints.size(), close, lineWidth);
}
void Renderer::drawPolygon(Vector2D* points, int size, bool close, float lineWidth) const
{
	//Do not draw an empty polygon
	if (size < 3)
		return;

	for (int countloop = 0; countloop < size - 1; ++countloop)
		drawLine(points[countloop], points[countloop + 1], lineWidth);

	if (close)
		drawLine(points[0], points[size - 1], lineWidth);
}

void Renderer::fillGeometry(Geometry* geometry) const
{
	this->graphics->getRenderTarget()->FillGeometry(geometry->getGeometry(), this->graphics->getColorBrush());
}

void Renderer::fillRect(float left, float top, float width, float height) const
{
	fillRect(Rect2D(left, top, left + width, top + height));
}
void Renderer::fillRect(const Vector2D& lefttop, const Vector2D& rightbottom) const
{
	fillRect(Rect2D(lefttop, rightbottom));
}
void Renderer::fillRect(const Rect2D& rect) const
{
	D2D1_RECT_F d2dRect = D2D1::RectF((FLOAT)rect.left - (FLOAT)rect.getWidth() / 2, (FLOAT)rect.top - (FLOAT)rect.getHeight() / 2, (FLOAT)rect.right - (FLOAT)rect.getWidth() / 2, (FLOAT)rect.bottom - (FLOAT)rect.getHeight() / 2);
	this->graphics->getRenderTarget()->FillRectangle(d2dRect, this->graphics->getColorBrush());
}

void Renderer::fillCircle(const Vector2D& center, float r) const
{
	fillCircle(center.x, center.y, r);
}
void Renderer::fillCircle(float xcenter, float ycenter, float r) const
{
	D2D1_ELLIPSE ellipse = D2D1::Ellipse(D2D1::Point2((FLOAT)xcenter, (FLOAT)ycenter), (FLOAT)r, (FLOAT)r);
	this->graphics->getRenderTarget()->FillEllipse(ellipse, this->graphics->getColorBrush());
}

void Renderer::fillPolygon(const std::vector<Vector2D>& vecPoints) const
{
	Vector2D* points = new Vector2D[(int)vecPoints.size()];
	for (int i = 0; i < (int)vecPoints.size(); ++i)
		points[i] = vecPoints[i];

	fillPolygon(points, vecPoints.size());
}
void Renderer::fillPolygon(Vector2D* points, int size) const
{
	if (size < 3)
		return;

	HRESULT hr;

	ID2D1PathGeometry* pGeometry = nullptr;
	hr = this->graphics->getD2DFactory()->CreatePathGeometry(&pGeometry);
	if (FAILED(hr))
	{
		SafeRelease(pGeometry);
		LogManager::getInstance().log(new WarningLog(_T("Failed to create path geometry"), LOG_INFO));
		return;
	}

	//Write to the path geometry using the geometry sink
	ID2D1GeometrySink* pGeometrySink = nullptr;
	hr = pGeometry->Open(&pGeometrySink);
	if (FAILED(hr))
	{
		SafeRelease(pGeometrySink);
		SafeRelease(pGeometry);
		LogManager::getInstance().log(new WarningLog(_T("Failed to create geometry sink"), LOG_INFO));
		return;
	}

	if (SUCCEEDED(hr))
	{
		pGeometrySink->BeginFigure(D2D1::Point2F((FLOAT)points[0].x, (FLOAT)points[0].y), D2D1_FIGURE_BEGIN_FILLED);

		for (int i = 0; i < size; ++i)
			pGeometrySink->AddLine(D2D1::Point2F((FLOAT)points[i].x, (FLOAT)points[i].y));

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

bool Renderer::drawBitmap(const Image* imagePtr) const
{
	assert(imagePtr != nullptr);

	Rect2D srcRect2(0, 0, imagePtr->getWidth(), imagePtr->getHeight());
	return drawBitmap(imagePtr, Vector2D(0, 0), srcRect2);
}
bool Renderer::drawBitmap(const Image* imagePtr, float x, float y) const
{
	assert(imagePtr != nullptr);

	Rect2D srcRect(0, 0, imagePtr->getWidth(), imagePtr->getHeight());
	return drawBitmap(imagePtr, Vector2D(x, y), srcRect);
}
bool Renderer::drawBitmap(const Image* imagePtr, const Vector2D& position) const
{
	assert(imagePtr != nullptr);

	Rect2D srcRect(0, 0, imagePtr->getWidth(), imagePtr->getHeight());
	return drawBitmap(imagePtr, position, srcRect);
}
bool Renderer::drawBitmap(const Image* imagePtr, const Rect2D& srcRect) const
{
	assert(imagePtr != nullptr);

	return drawBitmap(imagePtr, Vector2D(0, 0), srcRect);
}
bool Renderer::drawBitmap(const Image* imagePtr, float x, float y, const Rect2D& srcRect) const
{
	assert(imagePtr != nullptr);

	return drawBitmap(imagePtr, Vector2D(x, y), srcRect);
}
bool Renderer::drawBitmap(const Image* imagePtr, const Vector2D& position, const Rect2D& srcRect) const
{
	assert(imagePtr != nullptr);

	D2D1_RECT_F srcRect_f;
	srcRect_f.left = (FLOAT)srcRect.left;
	srcRect_f.right = (FLOAT)srcRect.right;
	srcRect_f.top = (FLOAT)srcRect.top;
	srcRect_f.bottom = (FLOAT)srcRect.bottom;

	D2D1_RECT_F dstRect_f;
	dstRect_f.left = (FLOAT)position.x;
	dstRect_f.right = dstRect_f.left + (FLOAT)(srcRect.right - srcRect.left);
	dstRect_f.top = (FLOAT)position.y;
	dstRect_f.bottom = dstRect_f.top + (FLOAT)(srcRect.bottom - srcRect.top);

	this->graphics->getRenderTarget()->DrawBitmap(imagePtr->getBitmap(), dstRect_f, (FLOAT)imagePtr->getOpacity(), this->interpolation_mode, srcRect_f);

	return true;
}