#ifndef _COLORBRUSH_H
#define _COLORBRUSH_H

#ifndef _2DUTILL_H
#include "Core/Defines/d2dutill.h"
#endif

class RenderTarget;

class ColorBrush
{
public:
	ColorBrush(RenderTarget* renderTarget);
	~ColorBrush();

	virtual bool create() = 0;
	virtual bool destroy();

protected:
	ID2D1Brush* brush;
	RenderTarget* render_target;
};

#endif