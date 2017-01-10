#include "Rendering/Objects/RenderItems/\Texture.h"
#include "Core\Data\Objects\Resources\Image.h"

#include "Rendering\Renderer.h"

Texture::Texture(Image* image, const std::tstring name)
	:RenderItem(name)
	, image(image)
{}
Texture::~Texture()
{}

void Texture::render(Renderer* renderer)
{
}

bool Texture::isTransparant() const
{
	return image->getOpacity() < 1.0f;
}

float Texture::getWidth() const
{
	return (float)getImage()->getWidth();
}
float Texture::getHeight() const
{
	return (float)getImage()->getWidth();
}

Image* Texture::getImage() const
{
	return this->image;
}