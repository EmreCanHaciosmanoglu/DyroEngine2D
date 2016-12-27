#ifndef _IMAGE_H
#define _IMAGE_H

#include "Core\Resources\Resource.h"
#ifndef _IBOUNDINGBOX_H
#include "Interfaces/IBoundingBox.h"
#endif

#ifndef _COLOR_H
#include "Defines/color.h"
#endif
#ifndef _2DUTILL_H
#include "Defines/d2dutill.h"
#endif

#ifndef _RECT2D_H
#include "Helpers/Math/Rect2D.h"
#endif

class Image : public Resource, public IBoundingBox
{
public:
	Image(const std::tstring& resourcePath);
	virtual ~Image();

	virtual bool initialize();
	virtual bool shutdown();

	ID2D1Bitmap* getBitmap() const;

	int	getWidth() const;
	int	getHeight() const;

	void setOpacity(float opacity);
	float getOpacity() const;
	void setClip(const Rect2D& clip);
	const Rect2D& getClip() const;

	void setTransparencyColor(const Color& transparentColor);

	virtual Rect2D getBoundingBox() const;

private:
	HRESULT LoadBitmapFromFile(ID2D1RenderTarget* renderTargetPtr, IWICImagingFactory* wICFactoryPtr, const std::tstring& uriRef, UINT destinationWidth, UINT destinationHeight, IWICFormatConverter** formatConvertorPtrPtr);

	ID2D1Bitmap*			bitmap;
	IWICFormatConverter*	converter;
	float					opacity;
	Rect2D					clip;
};

#endif