#ifndef _IBOUNDINGBOX_H
#define _IBOUDNINGBOX_H

#include "Helpers/Math/Rect2D.h"

class IBoundingBox
{
public:
	IBoundingBox(){}
	virtual ~IBoundingBox(){}

	virtual Rect2D getBoundingBox() const;
};

#endif