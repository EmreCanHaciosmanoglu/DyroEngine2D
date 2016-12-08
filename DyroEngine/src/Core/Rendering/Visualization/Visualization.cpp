#include "Core/Rendering/Visualization/Visualization.h"
#include "Core/Data/DataObjects/DataObject.h"

Visualization::Visualization(DataObject* object)
	:data_object(object)
{

}
Visualization::~Visualization()
{

}

const std::vector<RenderItem>& Visualization::getRenderItems()
{
	return this->vec_renderitems;
}
DataObject* Visualization::getDataObject() const
{
	return this->data_object;
}

