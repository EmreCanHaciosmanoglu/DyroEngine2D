#ifndef _LAYER_H
#define _LAYER_H

#include "Helpers\TaggedObject.h"

class Layer : public TaggedObject<Layer>
{
public:
	Layer(const std::tstring& name);
	virtual ~Layer();
};

#endif