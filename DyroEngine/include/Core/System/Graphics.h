#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include "Core/System/System.h"

#ifndef _2DUTILL_H
#include "Defines/d2dutill.h"
#endif

class MainWindow;

class Graphics : public System
{
public:
	Graphics();
	virtual ~Graphics();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	void beginDraw();
	HRESULT endDraw();

	void clear();

	HRESULT onResize(UINT width, UINT height);

	ID2D1HwndRenderTarget* getRenderTarget() { return this->render_target; }
	IWICImagingFactory* getImageFactory() { return this->image_factory; }
	ID2D1SolidColorBrush* getColorBrush() { return this->color_brush; }
	ID2D1Factory* getD2DFactory() { return this->D2D_factory; }

private:
	HRESULT createDeviceIndependentResources();
	HRESULT createDeviceDependantResources();

	void discardDeviceResources();

	ID2D1HwndRenderTarget* render_target;
	IWICImagingFactory* image_factory;
	ID2D1SolidColorBrush* color_brush;
	ID2D1Factory* D2D_factory;

	MainWindow* main_window;
};

#endif