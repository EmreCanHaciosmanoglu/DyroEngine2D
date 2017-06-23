#ifndef _TEXT_H
#define _TEXT_H

#include "Rendering/Objects/RenderItems/RenderItem.h"

class TextDescription;

class Text : public RenderItem
{
public:
	Text(TextDescription* description, const std::tstring& name = _T("Text"));
	virtual ~Text();

	virtual void render(Renderer* renderer);

	virtual bool isTransparant() const;
	virtual Rect2D getBounds() const;

	virtual float getWidth() const;
	virtual float getHeight() const;

	TextDescription* getTextDescription() const;

private:
	TextDescription* description;
};

#endif