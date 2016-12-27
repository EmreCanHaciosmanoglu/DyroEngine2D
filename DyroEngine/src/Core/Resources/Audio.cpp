#include "Core\Resources\Audio.h"

Audio::Audio(const std::tstring& resourcePath)
	:Resource(resourcePath, ResourceType::AUDIO_RESOURCE)
{}
Audio::~Audio()
{}

bool Audio::initialize()
{
	return true;
}
bool Audio::shutdown()
{
	return true;
}