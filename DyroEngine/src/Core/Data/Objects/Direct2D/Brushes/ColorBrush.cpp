#include "Core/Data/Objects/Direct2D/Brushes/ColorBrush.h"

#include "Core/Defines/deletemacros.h"

ColorBrush::ColorBrush(RenderTarget* renderTarget)
	:render_target(renderTarget)
{}
ColorBrush::~ColorBrush()
{}

bool ColorBrush::destroy()
{
	SafeRelease(this->brush);

	return true;
}