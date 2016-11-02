#ifndef _IMAGE_H
#define _IMAGE_H

#include "Core\Resources\Resource.h"

class Image : public Resource
{
public:
	Image(const std::tstring& resourcePath);
	virtual ~Image();

	virtual bool intialize();
	virtual bool shutdown();
};

#endif