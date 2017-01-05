#include "Rendering/Objects/RenderItems/\Texture.h"
#include "Core\Data\Objects\Resources\Image.h"

#include "Rendering\Renderer.h"

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