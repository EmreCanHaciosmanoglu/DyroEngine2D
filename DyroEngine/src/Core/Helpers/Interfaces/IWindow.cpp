#include "Core/Helpers/Interfaces/IWindow.h"

#include "Core\Types\SettingsType.h"

#include "Core\Data\Manager\SettingsManager.h"
#include "Core\Data\Objects\Settings\ApplicationSettings.h"

#include "Core/Defines/debug.h"

IWindow::IWindow()
	: handle_devicecontext(0)
	, handle_window(0)
	, handle_instance(GetModuleHandle(NULL))

	, window_rect()

	, extended_style(0)
	, style(0)

	, pixel_format(0)

	, window_classname(_T(""))
	, window_title(_T(""))

	, window_width(0)
	, window_height(0)
{}
IWindow::~IWindow()
{}

LRESULT CALLBACK IWindow::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_CREATE)
	{
		// if the message is WM_CREATE, the lParam contains a pointer to a CREATESTRUCT
		// the CREATESTRUCT contains the "this" pointer from the CreateWindow method
		// the "this" pointer of our app is stored in the createstruct pcs->lpCreateParams
		CREATESTRUCT *pCS = (CREATESTRUCT*)lParam;
		SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)pCS->lpCreateParams);
	}
	else
	{
		//retrieve the stored "this" pointer
		IWindow* window = (IWindow*)(GetWindowLongPtr(hWnd, GWLP_USERDATA));
		if (window != nullptr)
			return window->handleEvent(hWnd, uMsg, wParam, lParam);
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

bool IWindow::createWindow()
{
	ApplicationSettings* appSettings = dynamic_cast<ApplicationSettings*>(Singleton<SettingsManager>::getInstance().getSettings(SettingsType::APPLICATION_SETTINGS));
	if (appSettings == nullptr)
		return false;

	window_width = appSettings->getWindowWidth();
	window_height = appSettings->getWindowHeight();
	
	this->window_rect = createWindowRect();

	this->window_classname = getWindowClassName();
	this->window_title = getWindowTitle();

	if (!RegisterClass(&createWindowClass()))
	{
		int value = GetLastError();
		LogManager::getInstance().log(new ErrorLog(_T("Register \"WNDCLASS\" failed."), LOG_INFO));
		return false;
	}

	if (!setupWindow())
		return false;
	if (!errorHandling())
		return false;

	ShowWindow(this->handle_window, SW_SHOW);
	SetForegroundWindow(this->handle_window);
	SetFocus(this->handle_window);

	return true;
}
bool IWindow::destroyWindow()
{
	LPCTSTR window_classname = getWindowClassName().c_str();

	if (this->handle_devicecontext && !ReleaseDC(this->handle_window, this->handle_devicecontext))
	{
		LogManager::getInstance().log(new ErrorLog(_T("Release \"DC\" failed."), LOG_INFO));
		this->handle_devicecontext = NULL;
	}
	if (this->handle_window && !DestroyWindow(this->handle_window))
	{
		LogManager::getInstance().log(new ErrorLog(_T("Release \"HWND\" failed"), LOG_INFO));
		this->handle_window = NULL;
	}

	if (!UnregisterClass(this->window_classname.c_str(), this->handle_instance))
	{
		LogManager::getInstance().log(new ErrorLog(_T("Unregister \"WNDCLASS\" failed"), LOG_INFO));
		this->handle_instance = NULL;
	}

	return true;
}

const POINT IWindow::getCenterPosition() const
{
	int windowwidth = this->window_rect.right - this->window_rect.left;
	int windowheight = this->window_rect.bottom - this->window_rect.top;

	return POINT
	{
		GetSystemMetrics(SM_CXSCREEN) / 2 - windowwidth / 2,
		GetSystemMetrics(SM_CYSCREEN) / 2 - windowheight / 2
	};
}

void IWindow::setExtendedStyle(DWORD extendedStyle)
{
	this->extended_style = extendedStyle;
}
void IWindow::setStyle(DWORD style)
{
	this->style = style;
}

DWORD IWindow::getExtentedStyle() const
{
	return this->extended_style;
}
DWORD IWindow::getStyle() const
{
	return this->style;
}

RECT IWindow::getWindowRect() const
{
	return this->window_rect;
}

bool IWindow::setupWindow()
{
	this->handle_window = CreateWindowEx(this->extended_style,
		this->window_classname.c_str(),
		this->window_title.c_str(),
		this->style,
		getWindowPosition().x, getWindowPosition().y,
		this->window_rect.right - this->window_rect.left,
		this->window_rect.bottom - this->window_rect.top,
		NULL,
		NULL,
		this->handle_instance,
		this);

	int error = GetLastError();
	if (!this->handle_window)
	{
		LogManager::getInstance().log(new ErrorLog(_T("Creation of our window failed."), LOG_INFO));
		return false;
	}

	return true;
}
bool IWindow::errorHandling()
{
	//Check if we have a device context
	if (!(this->handle_devicecontext = GetDC(this->handle_window)))
	{
		LogManager::getInstance().log(new ErrorLog(_T("Can't create a \"GLDC\"."), LOG_INFO));
		return false;
	}

	//Check the pixel format
	PIXELFORMATDESCRIPTOR pfd = createWindowPixelFormatDescription();

	this->pixel_format = ChoosePixelFormat(this->handle_devicecontext, &pfd);
	if (!this->pixel_format)
	{
		LogManager::getInstance().log(new ErrorLog(_T("Can't find a suitable \"PixelFormat\"."), LOG_INFO));
		return false;
	}
	if (!SetPixelFormat(this->handle_devicecontext, this->pixel_format, &pfd))
	{
		LogManager::getInstance().log(new ErrorLog(_T("Can't set the \"PixelFormat\"."), LOG_INFO));
		return false;
	}

	return true;
}

WNDCLASS IWindow::createWindowClass()
{
	LPCTSTR window_classname = getWindowClassName().c_str();

	WNDCLASS wc;
	memset(&wc, NULL, sizeof(WNDCLASS));

	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = this->handle_instance;

	//TODO: load the cursor and application icon!
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	wc.hbrBackground = NULL;
	wc.lpszMenuName = NULL;

	wc.lpszClassName = this->window_classname.c_str();

	return wc;
}
RECT IWindow::createWindowRect()
{
	return RECT
	{
		(long)0,
		(long)0,
		(long)getWindowWidth(),
		(long)getWindowHeight()
	};
}
PIXELFORMATDESCRIPTOR IWindow::createWindowPixelFormatDescription()
{
	return PIXELFORMATDESCRIPTOR
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL |
		PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		getWindowBitsPerPixel(),
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		16,
		0,
		0,
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};
}

long IWindow::getWindowWidth() const
{
	return window_width;
}
long IWindow::getWindowHeight() const
{
	return window_height;
}

void IWindow::setWindowWidth(long width)
{
	this->window_width = width;
}
void IWindow::setWindowHeight(long height)
{
	this->window_height = height;
}

HDC IWindow::getWindowDeviceContext() const
{
	return this->handle_devicecontext;
}
HWND IWindow::getWindowHandle() const
{
	return this->handle_window;
}
HINSTANCE IWindow::getWindowInstance() const
{
	return this->handle_instance;
}