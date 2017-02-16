#include "Core\Data\Objects\Direct2D\Brushes\RadialGradientColorBrush.h"

#ifndef _RENDERTARGET_H
#include "Core/Data/Objects/Direct2D/RenderTarget.h"
#endif

RadialGradientColorBrush::RadialGradientColorBrush(RenderTarget* renderTarget, GradientColorsCollection& collection, const D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES& properties)
	:GradientColorBrush(renderTarget, collection)
	, radial_brush_properties(properties)
{}
RadialGradientColorBrush::~RadialGradientColorBrush()
{}

bool RadialGradientColorBrush::create()
{
	GradientColorsCollection collection = getGradientColorsCollection();
	ID2D1RadialGradientBrush* radial_gradient_brush = nullptr;

	HRESULT hr = this->render_target->getRenderTarget()->CreateRadialGradientBrush(
		this->radial_brush_properties,
		collection.getCollection(),
		&radial_gradient_brush);

	this->brush = radial_gradient_brush;

	return hr == S_OK;
}