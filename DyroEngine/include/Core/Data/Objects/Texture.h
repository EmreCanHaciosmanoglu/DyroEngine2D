#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "Core\Rendering\RenderItem.h"

class Image;

class Texture : public RenderItem
{
public:
	Texture(Image* image);
	virtual ~Texture();

	virtual void render(Renderer* renderer);

	virtual bool isTransparant() const;

	Image* getImage() const;

private:
	Image* image;
};

#endif