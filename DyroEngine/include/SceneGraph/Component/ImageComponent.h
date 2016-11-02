#ifndef _IMAGECOMPONENT_H
#define _IMAGECOMPONENT_H

#include "SceneGraph/Component/Component.h"
#include "Interfaces/IDrawable.h"

#ifndef _COLOR_H
#include "Defines/color.h"
#endif

#ifndef _RECT2D_H
#include "Helpers/Math/Rect2D.h"
#endif

class Image;
class TransformComponent;

class ImageComponent : public Component, public IDrawable
{
public:
	ImageComponent(Image* image, const std::tstring& name = _T(""));
	virtual ~ImageComponent();

	virtual bool initialize();
	virtual void update();
	virtual void draw();
	virtual bool shutdown();

	void centerImage();
	void resetCenter();

	void mirrorImageX();
	void mirrorImageY();
	void resetMirror(bool x = true, bool y = true);

	void setTransparencyColor(const Color& color);

	void setImage(Image* image);
	Image* getImage() const;

	void setOpacity(float o);
	float getOpacity() const;

	void setClip(const Rect2D& c);
	const Rect2D& getClip() const;

private:
	Image* image;
	TransformComponent* transform;
};

#endif