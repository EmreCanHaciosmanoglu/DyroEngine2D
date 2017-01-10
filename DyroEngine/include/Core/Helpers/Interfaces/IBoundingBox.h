#ifndef _IBOUNDINGBOX_H
#define _IBOUNDINGBOX_H

#ifndef _RECT2D_H
#include "Math/Objects/Rect2D.h"
#endif

class IBoundingBox
{
public:
	virtual Rect2D getBoundingBox() = 0;

protected:
	IBoundingBox() {}
	virtual ~IBoundingBox() {}
};

#endif