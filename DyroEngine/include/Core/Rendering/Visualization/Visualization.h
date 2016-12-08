#ifndef _VISUALIZATION_H
#define _VISUALIZATION_H

#ifndef _RENDERITEM_H
#include "Core/Rendering/RenderItem.h"
#endif

#ifndef _VECTOR_
#include <vector>
#endif

class DataObject;

class Visualization
{
public:
	Visualization(DataObject* object);
	virtual ~Visualization();

	const std::vector<RenderItem>& getRenderItems();
	DataObject* getDataObject() const;

protected:

	std::vector<RenderItem> vec_renderitems;
	DataObject* data_object;
};

#endif