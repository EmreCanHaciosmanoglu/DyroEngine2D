#include "Core/Rendering/RenderItem.h"

RenderItem::RenderItem()
	:layer(0)
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

