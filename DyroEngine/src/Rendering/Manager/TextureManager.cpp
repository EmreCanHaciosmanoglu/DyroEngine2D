#include "Rendering\Manager\TextureManager.h"
#include "Rendering\Objects\RenderItems\Texture.h"

#include "Core\Data\Objects\Resources\Image.h"

#include <algorithm>

TextureManager::TextureManager()
{}
TextureManager::~TextureManager()
{}

bool TextureManager::initialize()
{
	return true;
}
bool TextureManager::shutdown()
{
	std::vector<Texture*> textures;
	getObjects(textures);

	for (Texture* texture : textures)
		delete texture;

	return true;
}

void TextureManager::addTexture(Texture* texture)
{
	addObject(texture->getID(), texture);
}

void TextureManager::removeTexture(Texture* texture)
{
	removeObject(texture);
}
void TextureManager::removeTexture(unsigned int id)
{
	removeObject(id);
}

Texture* TextureManager::getTexture(unsigned int id)
{
	return getObject(id);
}
Texture* TextureManager::getTexture(Image* image)
{
	std::vector<Texture*> textures;
	getObjects(textures);

	std::vector<Texture*>::const_iterator it = std::find_if(textures.begin(), textures.end(),
		[image](Texture* texture) -> bool
	{
		return image->getResourceName() == texture->getImage()->getResourceName();
	});

	if(it != textures.end())
		return (*it);

	return nullptr;
}