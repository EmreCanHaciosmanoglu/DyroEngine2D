#include "Core/System/Objects/Graphics.h"
#include "Core/System/Objects/Window.h"
#include "Core/System/Manager/SystemManager.h"

#include "Core/Defines/debug.h"

#include "Core/Types/SystemType.h"
#include "Core/Types/SettingsType.h"

#include "Core/Defines/deletemacros.h"
#include "Core/Defines\color.h"

#include "Core\Data\Manager\SettingsManager.h"
#include "Core\Data\Objects\Settings\GameSettings.h"

Graphics::Graphics()
	: System(SystemType::GRAPHICS_SYSTEM)
	, render_target(nullptr)
	, D2D_factory(nullptr)
	, color_brush(nullptr)
	, image_factory(nullptr)
	, write_factory(nullptr)

	, main_window(nullptr)
{
}
Graphics::~Graphics()
{
}

HRESULT Graphics::onResize(UINT width, UINT height)
{
	// Note:
	// This method can fail, but it's okay to ignore the error here,
	// because the error will be returned again the next time EndDraw is called.
	if (this->render_target)
		return this->render_target->Resize(D2D1::SizeU(width, height));
	else return S_FALSE;
}

bool Graphics::initialize()
{
	this->main_window = dynamic_cast<Window*>(SystemManager::getInstance().getSystem(SystemType::WINDOW_SYSTEM));

	HRESULT hr = createDeviceIndependentResources();
	if (FAILED(hr))
		return false;
	hr = createDeviceDependantResources();
	if (FAILED(hr))
		return false;

	return true;
}
void Graphics::update()
{
}
bool Graphics::shutdown()
{
	SafeRelease(this->image_factory);
	SafeRelease(this->color_brush);
	SafeRelease(this->render_target);
	SafeRelease(this->D2D_factory);

	return true;
}

HRESULT Graphics::createDeviceIndependentResources()
{
	HRESULT hr = S_OK;

	hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &this->D2D_factory);
	if (FAILED(hr))
		return hr;

	hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	if (FAILED(hr))
		return hr;
	hr = CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_IWICImagingFactory, (LPVOID*)&this->image_factory);
	if (FAILED(hr))
		return hr;

	hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&this->write_factory));
	if (FAILED(hr))
		return hr;

	return hr;
}
HRESULT Graphics::createDeviceDependantResources()
{
	HRESULT hr = S_OK;
	if (!this->render_target)
	{
		HWND hWnd = this->main_window->getWindowHandle();

		RECT rc;
		GetClientRect(hWnd, &rc);
		D2D1_SIZE_U size = D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top);

		hr = this->D2D_factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(hWnd, size), &this->render_target);
		if (FAILED(hr))
			return hr;
		hr = this->render_target->CreateSolidColorBrush((D2D1::ColorF) D2D1::ColorF::Black, &this->color_brush);
		if (FAILED(hr))
			return hr;
	}
	return hr;
}

void Graphics::discardDeviceResources()
{
	SafeRelease(this->render_target);
}

void Graphics::clear()
{
	GameSettings* gameSettings = dynamic_cast<GameSettings*>(SettingsManager::getInstance().getSettings(SettingsType::GAME_SETTINGS));
	if (gameSettings == nullptr)
		return;

	this->render_target->Clear(gameSettings->getBackgroundColor().toColorF());
}

void Graphics::beginDraw()
{
	this->render_target->BeginDraw();
}
HRESULT Graphics::endDraw()
{
	return this->render_target->EndDraw();
}