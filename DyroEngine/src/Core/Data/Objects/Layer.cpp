#include "Core\Data\Objects\Layer.h"

Layer::Layer(unsigned int layerDepth, const std::tstring& name)
	:TaggedObject(name)
{}
Layer::~Layer()
{}

void Layer::setLayerDepth(unsigned int layerDepth)
{
	this->layer_depth = layerDepth;
}
unsigned int Layer::getLayerDepth() const
{
	return this->layer_depth;
}