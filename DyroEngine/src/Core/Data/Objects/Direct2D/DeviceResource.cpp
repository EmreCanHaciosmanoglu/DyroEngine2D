#include "Core/Data/Objects/Direct2D/DeviceResource.h"

DeviceResource::DeviceResource(ID2D1Factory* factory)
	:d2d_factory(factory)
{}
DeviceResource::~DeviceResource()
{}

ID2D1Factory* DeviceResource::getD2DFactory()
{
	return this->d2d_factory;
}