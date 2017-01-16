#include "Core\Data\Objects\Resources\Image.h"

#include "Core/System/Manager/SystemManager.h"
#include "Core/System/Objects/Graphics.h"

Image::Image(const std::tstring& resourcePath)
	:Resource(resourcePath, ResourceType::IMAGE_RESOURCE)
	, bitmap(nullptr)
	, converter(nullptr)
	, opacity(1.0f)
	, clip(Rect2D::empty)
{}
Image::~Image()
{}

bool Image::initialize()
{
	ID2D1RenderTarget *renderTargetPtr = dynamic_cast<Graphics*>(SystemManager::getInstance().getSystem(SystemType::GRAPHICS_SYSTEM))->getRenderTarget();
	IWICImagingFactory *iWICFactoryPtr = dynamic_cast<Graphics*>(SystemManager::getInstance().getSystem(SystemType::GRAPHICS_SYSTEM))->getImageFactory();

	HRESULT hr = LoadBitmapFromFile(renderTargetPtr, iWICFactoryPtr, getResourcePath(), 0, 0, &this->converter);
	if (FAILED(hr))
		return false;

	// Create a Direct2D bitmap from the WIC bitmap.
	hr = renderTargetPtr->CreateBitmapFromWicBitmap(this->converter, &this->bitmap);

	if (FAILED(hr))
		return false;

	return true;
}
bool Image::shutdown()
{
	this->bitmap->Release();
	this->converter->Release();

	return true;
}

HRESULT Image::LoadBitmapFromFile(ID2D1RenderTarget *renderTargetPtr, IWICImagingFactory *wICFactoryPtr, const std::tstring& uriRef, UINT destinationWidth, UINT destinationHeight, IWICFormatConverter **FormatConverterPtr)
{
	IWICBitmapDecoder*		decoderPtr = nullptr;
	IWICBitmapFrameDecode*	sourcePtr = nullptr;
	IWICBitmapScaler*		scalerPtr = nullptr;

	//CreateDecoderFromFilename->first param HAS TO BE LPCWSTR
	std::tstring tUri(uriRef.c_str());
	std::wstring wUri(tUri.begin(), tUri.end());
	HRESULT hr = wICFactoryPtr->CreateDecoderFromFilename(wUri.c_str(), NULL, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &decoderPtr);

	if (FAILED(hr))
		return hr;

	// Create the initial frame.
	hr = decoderPtr->GetFrame(0, &sourcePtr);
	if (FAILED(hr))
	{
		if (decoderPtr != nullptr)
			decoderPtr->Release();

		return hr;
	}

	// Convert the image format to 32bppPBGRA
	// (DXGI_FORMAT_B8G8R8A8_UNORM + D2D1_ALPHA_MODE_PREMULTIPLIED).
	hr = wICFactoryPtr->CreateFormatConverter(FormatConverterPtr);
	if (FAILED(hr))
	{
		if (decoderPtr != nullptr)
			decoderPtr->Release();

		return hr;
	}

	// If a new width or height was specified, create an
	// IWICBitmapScaler and use it to resize the image.
	if (destinationWidth != 0 || destinationHeight != 0)
	{
		UINT originalWidth, originalHeight;
		hr = sourcePtr->GetSize(&originalWidth, &originalHeight);
		if (FAILED(hr))
		{
			if (decoderPtr != nullptr)
				decoderPtr->Release();
			if (sourcePtr != nullptr)
				sourcePtr->Release();

			return hr;
		}

		if (destinationWidth == 0)
		{
			FLOAT scalar = (FLOAT)destinationHeight / (FLOAT)originalHeight;
			destinationWidth = (UINT)(scalar * (FLOAT)originalWidth);
		}
		else if (destinationHeight == 0)
		{
			FLOAT scalar = (FLOAT)destinationWidth / (FLOAT)originalWidth;
			destinationHeight = (UINT)(scalar * (FLOAT)originalHeight);
		}

		hr = wICFactoryPtr->CreateBitmapScaler(&scalerPtr);
		if (FAILED(hr))
		{
			if (decoderPtr != nullptr)
				decoderPtr->Release();
			if (sourcePtr != nullptr)
				sourcePtr->Release();

			return hr;
		}

		hr = scalerPtr->Initialize(sourcePtr, destinationWidth, destinationHeight, WICBitmapInterpolationModeCubic);
		if (FAILED(hr))
		{
			if (decoderPtr != nullptr)
				decoderPtr->Release();
			if (sourcePtr != nullptr)
				sourcePtr->Release();
			if (scalerPtr != nullptr)
				scalerPtr->Release();

			return hr;
		}

		hr = (*FormatConverterPtr)->Initialize(scalerPtr, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, NULL, 0.f, WICBitmapPaletteTypeMedianCut);
		if (FAILED(hr))
		{
			if (decoderPtr != nullptr)
				decoderPtr->Release();
			if (sourcePtr != nullptr)
				sourcePtr->Release();
			if (scalerPtr != nullptr)
				scalerPtr->Release();

			return hr;
		}
	}
	else
	{
		hr = (*FormatConverterPtr)->Initialize(sourcePtr, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, NULL, 0.f, WICBitmapPaletteTypeMedianCut);
	}

	if (decoderPtr != nullptr) decoderPtr->Release();
	if (sourcePtr != nullptr)  sourcePtr->Release();
	if (scalerPtr != nullptr)  scalerPtr->Release();

	return hr;
}

ID2D1Bitmap* Image::getBitmap() const
{
	return this->bitmap;
}

int Image::getWidth() const
{
	return this->bitmap->GetPixelSize().width;
}
int	Image::getHeight() const
{
	return this->bitmap->GetPixelSize().height;
}

float Image::getOpacity() const
{
	return this->opacity;
}
void Image::setOpacity(float opacity)
{
	this->opacity = opacity;
}

const Rect2D& Image::getClip() const
{
	return this->clip;
}
void Image::setClip(const Rect2D& clip)
{
	this->clip = clip;
}

void Image::setTransparencyColor(const Color& transparentColor)
{
	COLORREF color = RGB((int)(transparentColor.red * 255), (int)(transparentColor.green * 255), (int)(transparentColor.blue * 255));

	UINT width = 0, height = 0;

	WICPixelFormatGUID pixelFormat;
	this->converter->GetPixelFormat(&pixelFormat);
	this->converter->GetSize(&width, &height);

	UINT bitmapStride = 4 * width;
	UINT size = width * height * 4;
	unsigned char* pixelsPtr = new unsigned char[size]; // create 32 bit buffer

	this->converter->CopyPixels(NULL, bitmapStride, size, pixelsPtr);

	for (unsigned int count = 0; count < width * height; ++count)
	{
		if (RGB(pixelsPtr[count * 4 + 2], pixelsPtr[count * 4 + 1], pixelsPtr[count * 4]) == color) // if the color of this pixel == transparency color
		{
			((int*)pixelsPtr)[count] = 0; // set all four values to zero, this assumes sizeof(int) == 4 on this system
										  // setting values to zero means pre-multiplying the RGB values to an alpha of 0
		}
	}

	//assign modified pixels to bitmap
	IWICImagingFactory* iWICFactoryPtr = dynamic_cast<Graphics*>(SystemManager::getInstance().getSystem(SystemType::GRAPHICS_SYSTEM))->getImageFactory();

	IWICBitmap* iWICBitmapPtr = nullptr;
	HRESULT hr = iWICFactoryPtr->CreateBitmapFromMemory(width, height, GUID_WICPixelFormat32bppPBGRA, bitmapStride, size, pixelsPtr, &iWICBitmapPtr);

	delete[] pixelsPtr; //destroy buffer

	if (hr == S_OK)
	{
		ID2D1RenderTarget *renderTargetPtr = dynamic_cast<Graphics*>(SystemManager::getInstance().getSystem(SystemType::GRAPHICS_SYSTEM))->getRenderTarget();

		if (this->bitmap != nullptr)
			this->bitmap->Release();

		renderTargetPtr->CreateBitmapFromWicBitmap(iWICBitmapPtr, &this->bitmap);

		iWICBitmapPtr->Release();
	}
}

Rect2D Image::getBoundingBox() const
{
	Rect2D bounding_rect;

	if (this->clip != Rect2D::empty)
	{
		bounding_rect.left = 0;
		bounding_rect.top = 0;
		bounding_rect.right = this->clip.right - this->clip.left;
		bounding_rect.bottom = this->clip.bottom - this->clip.top;
	}
	else
	{
		bounding_rect.left = 0;
		bounding_rect.top = 0;
		bounding_rect.right = getWidth();
		bounding_rect.bottom = getHeight();
	}

	return bounding_rect;
}