#ifndef _TEXTUREMANAGER_H
#define _TEXTUREMANAGER_H

#include "Core/Helpers/Patterns/Manager.h"

class Texture;
class Image;

class TextureManager : public Manager<Texture>
{
public:
	TextureManager();
	virtual ~TextureManager();

	virtual bool initialize();
	virtual bool shutdown();

	void removeTexture(Texture* texture);
	void removeTexture(unsigned int id);

	Texture* getTexture(unsigned int id);
	Texture* getTexture(Image* image);
};

#endif