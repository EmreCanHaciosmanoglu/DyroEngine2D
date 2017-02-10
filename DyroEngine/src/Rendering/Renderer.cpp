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

void Renderer::render(const RenderInfo& info)
{
	std::vector<RenderItem*> render_items;
	render_items.insert(render_items.end(), info.items.begin(), info.items.end());
	render_items.insert(render_items.end(), this->cached_render_items.begin(), this->cached_render_items.end());

	//Sort the render items
	std::sort(render_items.begin(), render_items.end(),
		[](RenderItem* i1, RenderItem* i2) -> bool
	{
		return i1->getLayer()->getID() < i2->getLayer()->getID();
	});

	this->graphics->beginDraw();
	this->graphics->clear();

	Matrix2D mat_view = info.mat_view;

	//Render the render items
	for (RenderItem* item : render_items)
	{
		setTransformMatrix(item->getTransform() * mat_view);
		item->render(this);
	}
	
	for (RenderItem* item : this->cached_render_items)
		SafeDelete(item);
	this->cached_render_items.clear();

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
void Renderer::fillGeometry(Geometry* geometry) const
{
	this->graphics->getRenderTarget()->FillGeometry(geometry->getGeometry(), this->graphics->getColorBrush());
}

void Renderer::cacheShape(RenderItem* item)
{
	std::vector<RenderItem*>::const_iterator it = std::find(this->cached_render_items.begin(),this->cached_render_items.end(), item);

	if (this->cached_render_items.end() != it)
		return;

	this->cached_render_items.push_back(item);
}

bool Renderer::drawBitmap(const Image* imagePtr, float opacity) const
{
	assert(imagePtr != nullptr);

	Rect2D srcRect2(0, 0, imagePtr->getWidth(), imagePtr->getHeight());
	return drawBitmap(imagePtr, Vector2D(0, 0), srcRect2, opacity);
}
bool Renderer::drawBitmap(const Image* imagePtr, float x, float y, float opacity) const
{
	assert(imagePtr != nullptr);

	Rect2D srcRect(0, 0, imagePtr->getWidth(), imagePtr->getHeight());
	return drawBitmap(imagePtr, Vector2D(x, y), srcRect, opacity);
}
bool Renderer::drawBitmap(const Image* imagePtr, const Vector2D& position, float opacity) const
{
	assert(imagePtr != nullptr);

	Rect2D srcRect(0, 0, imagePtr->getWidth(), imagePtr->getHeight());
	return drawBitmap(imagePtr, position, srcRect, opacity);
}
bool Renderer::drawBitmap(const Image* imagePtr, const Rect2D& srcRect, float opacity) const
{
	assert(imagePtr != nullptr);

	return drawBitmap(imagePtr, Vector2D(0, 0), srcRect, opacity);
}
bool Renderer::drawBitmap(const Image* imagePtr, float x, float y, const Rect2D& srcRect, float opacity) const
{
	assert(imagePtr != nullptr);

	return drawBitmap(imagePtr, Vector2D(x, y), srcRect, opacity);
}
bool Renderer::drawBitmap(const Image* imagePtr, const Vector2D& position, const Rect2D& srcRect, float opacity) const
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

	this->graphics->getRenderTarget()->DrawBitmap(imagePtr->getBitmap(), dstRect_f, (FLOAT)opacity, this->interpolation_mode, srcRect_f);

	return true;
}