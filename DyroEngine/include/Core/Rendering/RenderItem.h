#ifndef _RENDERITEM_H
#define _RENDERITEM_H

#include "Helpers\TaggedObject.h"

#ifndef _MATRIX2D_H
#include "Helpers/Math/Matrix2D.h"
#endif

class Renderer;
class Layer;

class RenderItem : public TaggedObject<RenderItem>
{
public:
	RenderItem(const std::tstring& name = _T(""));
	virtual ~RenderItem();

	virtual void render(Renderer* renderer) = 0;

	void setLayer(Layer* layer);
	Layer* getLayer() const;
	void setTransform(const Matrix2D& transform);
	const Matrix2D& getTransform() const;

	virtual bool isTransparant() const = 0;

private:

	Layer* layer;
	Matrix2D transform;
};

#endif