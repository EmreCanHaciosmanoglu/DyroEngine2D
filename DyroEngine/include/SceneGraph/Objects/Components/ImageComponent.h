#ifndef _IMAGECOMPONENT_H
#define _IMAGECOMPONENT_H

#include "SceneGraph/Objects/Components/Component.h"
#ifndef _IBOUNDINGBOX_H
#include "Core\Helpers\Interfaces\IBoundingBox.h"
#endif

#ifndef _COLOR_H
#include "Core/Defines/color.h"
#endif

#ifndef _RECT2D_H
#include "Math/Objects/Rect2D.h"
#endif

class Image;

class ImageComponent : public Component, public IBoundingBox
{
	/**
	\note Must be present in every subclass definition.
	*/
	OBJECT_STATICS("ImageComponent")

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