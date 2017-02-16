#include "Core\Data\Objects\Direct2D\Brushes\LinearGradientColorBrush.h"

#ifndef _RENDERTARGET_H
#include "Core/Data/Objects/Direct2D/RenderTarget.h"
#endif

LinearGradientColorBrush::LinearGradientColorBrush(RenderTarget* renderTarget, GradientColorsCollection& collection, const D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES& properties)
	:GradientColorBrush(renderTarget, collection)
	,linear_brush_properties(properties)
{}
LinearGradientColorBrush::~LinearGradientColorBrush()
{}

bool LinearGradientColorBrush::create()
{
	GradientColorsCollection collection = getGradientColorsCollection();
	ID2D1LinearGradientBrush* linear_gradient_brush = nullptr;

	HRESULT hr = this->render_target->getRenderTarget()->CreateLinearGradientBrush(
		this->linear_brush_properties,
		collection.getCollection(),
		&linear_gradient_brush);

	this->brush = linear_gradient_brush;

	return hr == S_OK;
}