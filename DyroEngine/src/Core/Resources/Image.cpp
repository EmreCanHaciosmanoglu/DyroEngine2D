#include "Core\Resources\Image.h"

Image::Image(const std::tstring& resourcePath)
	:Resource(resourcePath,ResourceType::IMAGE_RESOURCE)
{}
Image::~Image()
{}

bool Image::intialize()
{
	return true;
}
bool Image::shutdown()
{
	return true;
}