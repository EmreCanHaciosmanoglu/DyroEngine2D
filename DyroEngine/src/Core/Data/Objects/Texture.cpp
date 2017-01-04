#include "Core\Data\Objects\Texture.h"
#include "Core\Resources\Image.h"

#include "Core\Rendering\Renderer.h"

Texture::Texture(Image* image)
	:RenderItem()
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

Image* Texture::getImage() const
{
	return this->image;
}