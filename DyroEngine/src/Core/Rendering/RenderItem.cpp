#include "Core/Rendering/RenderItem.h"

RenderItem::RenderItem()
	:layer(0)
	,transform(Matrix2D::createIdentityMatrix())
{

}
RenderItem::~RenderItem()
{

}

void RenderItem::setLayer(unsigned int layer)
{
	this->layer = layer;
}
unsigned int RenderItem::getLayer() const
{
	return this->layer;
}

void RenderItem::setTransform(const Matrix2D& transform)
{
	this->transform = transform;
}
const Matrix2D& RenderItem::getTransform() const
{
	return this->transform;
}