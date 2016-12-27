#ifndef _AUDIO_H
#define _AUDIO_H

#include "Core\Resources\Resource.h"

class Audio : public Resource
{
public:
	Audio(const std::tstring& resourcePath);
	virtual ~Audio();

	virtual bool initialize();
	virtual bool shutdown();
};

#endif