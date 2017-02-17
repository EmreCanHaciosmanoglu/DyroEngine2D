#include "Core/System/Objects/Window.h"
#include "Core/System/Objects/Graphics.h"
#include "Core/System/Manager/SystemManager.h"

#include "Core/Data/Manager/SettingsManager.h"
#include "Core/Data/Objects/Settings/ApplicationSettings.h"

#include "Core/Types/SystemType.h"
#include "core/Types/SettingsType.h"

#include "Core/Defines/string.h"

#include "Core/Defines/debug.h"

Window::Window()
	:System(SystemType::WINDOW_SYSTEM)
{
}
Window::~Window()
{
}

bool Window::initialize()
{
	//Set the main window style
	setStyle(WS_POPUPWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);

	if (!createWindow())
	{
		shutdown();
		return false;
	}

	return true;
}
void Window::update()
{
}
bool Window::shutdown()
{
	ApplicationSettings* appSettings = SettingsManager::getInstance().getSettings<ApplicationSettings>();
	if (appSettings == nullptr)
		return false;

	if (appSettings->getFullscreen())
	{
		ChangeDisplaySettings(NULL, 0);
		ShowCursor(true);
	}

	destroyWindow();

	return true;
}

LRESULT Window::handleEvent(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_ACTIVATE:
	{
		if (!HIWORD(wParam))
		{
			std::vector<System*> systems;
			SystemManager::getInstance().getSystems(systems);
			for (System* sys : systems)
				sys->activate();
		}
		else
		{
			std::vector<System*> systems;
			SystemManager::getInstance().getSystems(systems);
			for (System* sys : systems)
				sys->deactivate();
		}

		return 0;
	}

	case WM_SYSCOMMAND:
	{
		switch (wParam)
		{
		case SC_SCREENSAVE:
		case SC_MONITORPOWER:
			return 0;
		}
		break;
	}

	case WM_SIZE:
	{
		Graphics* graphics = SystemManager::getInstance().getSystem<Graphics>();
		if (graphics != nullptr)
		{
			graphics->onResize(LOWORD(lParam), HIWORD(lParam));
			return 0;
		}
	}

	case WM_CLOSE:
	{
		PostQuitMessage(0);
		return 0;
	}
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

BYTE Window::getWindowBitsPerPixel() const
{
	ApplicationSettings* appSettings = SettingsManager::getInstance().getSettings<ApplicationSettings>();
	if (appSettings == nullptr)
		return 0;

	return appSettings->getBitsPerPixel();
}

const std::tstring Window::getWindowTitle() const
{
	ApplicationSettings* appSettings = SettingsManager::getInstance().getSettings<ApplicationSettings>();
	if (appSettings == nullptr)
		return _T("");

	return appSettings->getWindowTitle();
}
const std::tstring Window::getWindowClassName() const
{
	ApplicationSettings* appSettings = SettingsManager::getInstance().getSettings<ApplicationSettings>();
	if (appSettings == nullptr)
		return _T("");

	return appSettings->getWindowTitle();
}

const POINT Window::getWindowPosition() const
{
	return getCenterPosition();
}