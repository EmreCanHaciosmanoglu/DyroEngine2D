#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "Rendering\Objects\RenderItems\RenderItem.h"

class Image;

class Texture : public RenderItem
{
public:
	Texture(Visualization* parent, Image* image, const std::tstring name = _T("Texture"));
	virtual ~Texture();

	virtual void render(Renderer* renderer);

	virtual bool isTransparant() const;

	virtual float getWidth() const;
	virtual float getHeight() const;

	Image* getImage() const;

private:
	Image* image;
};

#endif