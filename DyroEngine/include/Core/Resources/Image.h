#ifndef _IMAGE_H
#define _IMAGE_H

#include "Core\Resources\Resource.h"

#ifndef _COLOR_H
#include "Defines/color.h"
#endif
#ifndef _2DUTILL_H
#include "Defines/d2dutill.h"
#endif

class Image : public Resource
{
public:
	Image(const std::tstring& resourcePath);
	virtual ~Image();

	virtual bool intialize();
	virtual bool shutdown();

	ID2D1Bitmap* getBitmap() const;

	int	getWidth() const;
	int	getHeight() const;

	void setOpacity(float opacity);
	float getOpacity() const;

	void setTransparencyColor(Color transparentColor);

private:
	HRESULT LoadBitmapFromFile(ID2D1RenderTarget* renderTargetPtr, IWICImagingFactory* wICFactoryPtr, const std::tstring& uriRef, UINT destinationWidth, UINT destinationHeight, IWICFormatConverter** formatConvertorPtrPtr);

	ID2D1Bitmap*			bitmap;
	IWICFormatConverter*	converter;
	float					opacity;
};

#endif