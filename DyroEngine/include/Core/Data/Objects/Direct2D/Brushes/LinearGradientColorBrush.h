#ifndef _LINEARGRADIENTCOLORBRUSH_H
#define _LINEARGRADIENTCOLORBRUSH_H

#include "Core/Data/Objects/Direct2D/Brushes/GradientColorBrush.h"

class LinearGradientColorBrush : public GradientColorBrush
{
public:
	LinearGradientColorBrush(RenderTarget* renderTarget, GradientColorsCollection& collection, const D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES& properties);
	virtual ~LinearGradientColorBrush();

	virtual bool create();

private:
	D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES linear_brush_properties;
};

#endif