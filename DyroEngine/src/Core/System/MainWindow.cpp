#include "Core/System/MainWindow.h"
#include "Core/System/Graphics.h"
#include "Core/System/Manager/SystemManager.h"

#include "Core/Settings/WorldSettings.h"
#include "Core/Settings/ApplicationSettings.h"

#include "Defines/Types/SystemType.h"
#include "Defines/string.h"

#include "Diagnostics/Logger.h"

#include "Helpers/Singleton.h"

MainWindow::MainWindow()
	:System(SystemType::WINDOW_SYSTEM)
{
}
MainWindow::~MainWindow()
{
}

bool MainWindow::initialize()
{
	if (!createWindow())
	{
		shutdown();
		return false;
	}

	return true;
}
void MainWindow::update()
{

}
bool MainWindow::shutdown()
{
	ApplicationSettings* settings = Singleton<WorldSettings>::getInstance().getApplicationSettings();

	if (settings->getFullscreen())
	{
		ChangeDisplaySettings(NULL, 0);
		ShowCursor(true);
	}

	destroyWindow();

	return true;
}

LRESULT MainWindow::handleEvent(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_ACTIVATE:
	{
		if (!HIWORD(wParam))
			activate();
		else
			deactivate();

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
		Graphics* graphics = dynamic_cast<Graphics*>(Singleton<SystemManager>::getInstance().getSystem(SystemType::GRAPHICS_SYSTEM));
		graphics->onResize(LOWORD(lParam), HIWORD(lParam));
		return 0;
	}

	case WM_CLOSE:
	{
		PostQuitMessage(0);
		return 0;
	}
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

BYTE MainWindow::getWindowBitsPerPixel() const
{
	return Singleton<WorldSettings>::getInstance().getApplicationSettings()->getBitsPerPixel();
}

const std::tstring MainWindow::getWindowTitle() const
{
	return Singleton<WorldSettings>::getInstance().getApplicationSettings()->getWindowTitle();
}
const std::tstring MainWindow::getWindowClassName() const
{
	return Singleton<WorldSettings>::getInstance().getApplicationSettings()->getWindowTitle();
}

const POINT MainWindow::getWindowPosition() const
{
	return getCenterPosition();
}