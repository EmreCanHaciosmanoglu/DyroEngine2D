//#pragma once

#ifndef _IBOUNDINGBOX_H
#define _IBOUNDINGBOX_H

#ifndef _RECT2D_H
#include "Helpers/Math/Rect2D.h"
#endif

class IBoundingBox
{
public:
	IBoundingBox(){}
	virtual ~IBoundingBox(){}

	virtual Rect2D getBoundingBox() const = 0;
};

#endif