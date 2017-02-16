#ifndef _DEVICERESOURCE_H
#define _DEVICERESOURCE_H

#ifndef _2DUTILL_H
#include "Core/Defines/d2dutill.h"
#endif

class DeviceResource
{
public:
	DeviceResource(ID2D1Factory* factory);
	virtual ~DeviceResource();

	virtual bool create() = 0;
	virtual bool destroy() = 0;

protected:
	ID2D1Factory* getD2DFactory();

private:
	ID2D1Factory* d2d_factory;
};

#endif