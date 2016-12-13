#ifndef _RENDERITEM_H
#define _RENDERITEM_H

#ifndef _MATRIX2D_H
#include "Helpers\Math\Matrix2D.h"
#endif

class Renderer;

class RenderItem
{
public:
	RenderItem();
	virtual ~RenderItem();

	virtual void render(Renderer* renderer) = 0;

	void setLayer(unsigned int layer);
	unsigned int getLayer() const;

	void setTransform(const Matrix2D& transform);
	const Matrix2D& getTransform() const;

private:

	unsigned int layer;
	Matrix2D transform;
};

#endif