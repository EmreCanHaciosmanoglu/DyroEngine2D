#ifndef _SOLIDCOLORBRUSH_H
#define _SOLIDCOLORBRUSH_H

#include "Core/Data/Objects/Direct2D/Brushes/ColorBrush.h"

#ifndef _COLOR_H
#include "Core/Defines/color.h"
#endif

class SolidColorBrush : public ColorBrush
{
public:
	SolidColorBrush(RenderTarget* renderTarget, const Color& color);
	virtual ~SolidColorBrush();

	virtual bool create();

private:
	Color brush_color;
};

#endif