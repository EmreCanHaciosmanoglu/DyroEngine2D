#ifndef _IWINDOW_H
#define _IWINDOW_H

#ifndef _WINDOWS_
#include <windows.h>
#endif
#ifndef _STRING_H
#include "Core/Defines/string.h"
#endif

class IWindow
{
public:
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	virtual LRESULT handleEvent(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) = 0;

	virtual long getWindowWidth() const;
	virtual long getWindowHeight() const;

	virtual BYTE getWindowBitsPerPixel() const = 0;

	virtual const std::tstring getWindowTitle() const = 0;
	virtual const std::tstring getWindowClassName() const = 0;

	virtual const POINT getWindowPosition() const = 0;

	HDC getWindowDeviceContext() const;
	HWND getWindowHandle() const;
	HINSTANCE getWindowInstance() const;

protected:
	IWindow();
	virtual ~IWindow();

	bool createWindow();
	bool destroyWindow();

	const POINT getCenterPosition() const;

	void setExtendedStyle(DWORD extendedStyle);
	void setStyle(DWORD style);

	DWORD getExtentedStyle() const;
	DWORD getStyle() const;

	RECT getWindowRect() const;

	void setWindowWidth(long width);
	void setWindowHeight(long height);

private:
	bool setupWindow();
	bool errorHandling();

	WNDCLASS createWindowClass();
	RECT createWindowRect();
	PIXELFORMATDESCRIPTOR createWindowPixelFormatDescription();

	HDC             handle_devicecontext;
	HWND            handle_window;
	HINSTANCE       handle_instance;

	RECT			window_rect;

	DWORD			extended_style;
	DWORD			style;

	unsigned int	pixel_format;

	std::tstring	window_classname;
	std::tstring	window_title;

	long			window_width;
	long			window_height;
};

#endif //_IWINDOW_H
