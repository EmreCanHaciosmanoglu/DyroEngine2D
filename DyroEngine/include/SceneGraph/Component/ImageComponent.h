#ifndef _IMAGECOMPONENT_H
#define _IMAGECOMPONENT_H

#include "SceneGraph/Component/Component.h"
#ifndef _IBOUNDINGBOX_H
#include "Interfaces\IBoundingBox.h"
#endif

#ifndef _COLOR_H
#include "Defines/color.h"
#endif

#ifndef _RECT2D_H
#include "Helpers/Math/Rect2D.h"
#endif

class Image;

class ImageComponent : public Component, public IBoundingBox
{
public:
	ImageComponent(Image* image, const std::tstring& name = _T(""));
	virtual ~ImageComponent();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	void setTransparencyColor(const Color& color);

	void setImage(Image* image);
	Image* getImage() const;

	void setOpacity(float o);
	float getOpacity() const;

	void setClip(const Rect2D& c);
	const Rect2D& getClip() const;

	virtual Rect2D getBoundingBox() const;

private:
	Image* image;
};

#endif