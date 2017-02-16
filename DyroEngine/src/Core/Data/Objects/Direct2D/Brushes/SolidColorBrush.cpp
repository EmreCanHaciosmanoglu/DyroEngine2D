#include "Core\Data\Objects\Direct2D\Brushes\SolidColorBrush.h"

#ifndef _RENDERTARGET_H
#include "Core/Data/Objects/Direct2D/RenderTarget.h"
#endif

SolidColorBrush::SolidColorBrush(RenderTarget* renderTarget, const Color& color)
	:ColorBrush(renderTarget)
	, brush_color(color)
{}
SolidColorBrush::~SolidColorBrush()
{}

bool SolidColorBrush::create()
{
	ID2D1SolidColorBrush* solid_color_brush = nullptr;

	HRESULT hr = this->render_target->getRenderTarget()->CreateSolidColorBrush(
		D2D1::ColorF(this->brush_color.red, this->brush_color.green, this->brush_color.blue, this->brush_color.alpha),
		&solid_color_brush);

	this->brush = solid_color_brush;

	return hr == S_OK;
}