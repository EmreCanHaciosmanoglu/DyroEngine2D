#ifndef _RADIALGRADIENTCOLORBRUSH_H
#define _RADIALGRADIENTCOLORBRUSH_H

#include "Core/Data/Objects/Direct2D/Brushes/GradientColorBrush.h"

class RadialGradientColorBrush : public GradientColorBrush
{
public:
	RadialGradientColorBrush(RenderTarget* renderTarget, GradientColorsCollection& collection, const D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES& properties);
	virtual ~RadialGradientColorBrush();

	virtual bool create();

private:
	D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES radial_brush_properties;
};

#endif