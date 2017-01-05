#include "Rendering/Objects/RenderItems/RenderItem.h"

#include "Core\Data\Objects\Layer.h"

RenderItem::RenderItem(const std::tstring& name)
	:TaggedObject<RenderItem>(name)
	, layer(nullptr)
	, transform(Matrix2D::createIdentityMatrix())
{
}
RenderItem::~RenderItem()
{
}

void RenderItem::setLayer(Layer* layer)
{
	this->layer = layer;
}
Layer* RenderItem::getLayer() const
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