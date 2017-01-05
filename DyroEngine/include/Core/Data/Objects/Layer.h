#ifndef _LAYER_H
#define _LAYER_H

#include "Core/Helpers/TaggedObject.h"

class Layer : public TaggedObject<Layer>
{
public:
	Layer(unsigned int layerDepth, const std::tstring& name);
	virtual ~Layer();

	void setLayerDepth(unsigned int layerDepth);
	unsigned int getLayerDepth() const;

private:
	unsigned int layer_depth;
};

#endif