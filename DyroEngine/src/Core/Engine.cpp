#include "Core/Engine.h"

#ifndef _WINDOWS_
	#include <Windows.h>
#endif

//Core
#include "Core/System/System.h"

#include "Core\System\Logic.h"
#include "Core\System\MainWindow.h"
#include "Core\System\Graphics.h"
#include "Core\System\MainTimer.h"
#include "Core\System\Input.h"

#include "Core/System/Manager/SystemManager.h"
#include "Defines/Types/SystemType.h"

#include "Core/Rendering/Visualization/Manager/VisualizationFactory.h"

//Helpers
#include "Helpers/Singleton.h"

//Diagnostics
#include "Diagnostics/Logger.h"

//Settings
#include "Core/Settings/WorldSettings.h"

//SceneGraph
#include "SceneGraph/Scene/Manager/SceneManager.h"

//Game
#include "Core/Game/AbstractGame.h"

namespace
{
	const int INITIALIZATION_FAILED = 0x0001;
	const int SHUTDOWN_FAILED = 0x0010;
}

Engine::Engine(AbstractGame* game)
	:game(game)
{
}
Engine::~Engine()
{
}

int Engine::mainLoop()
{
	if (!initialize())
	{
		Singleton<Logger>::getInstance().log(_T("Initialization of the engine failed."), LOGTYPE_ERROR);
		return INITIALIZATION_FAILED;
	}

	// Seed the random number generator
	srand(GetTickCount64());

	MSG msg = {};
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		update();
	}

	if (!shutDown())
	{
		Singleton<Logger>::getInstance().log(_T("Shutdown of the engine failed."), LOGTYPE_ERROR);
		return SHUTDOWN_FAILED;
	}

	return msg.wParam;
}

int Engine::initialize()
{
	if (!createManagers())
		return FALSE;

	if (!Singleton<SystemManager>::getInstance().initialize())
		return FALSE;

	MainWindow* window = dynamic_cast<MainWindow*>(Singleton<SystemManager>::getInstance().getSystem(SystemType::WINDOW_SYSTEM));
	if (window == nullptr)
		return FALSE;
	Input* input = dynamic_cast<Input*>(Singleton<SystemManager>::getInstance().getSystem(SystemType::INPUT_SYSTEM));
	if (input == nullptr)
		return FALSE;
	MainTimer* timer = dynamic_cast<MainTimer*>(Singleton<SystemManager>::getInstance().getSystem(SystemType::TIMER_SYSTEM));
	if (timer == nullptr)
		return FALSE;
	Graphics* graphics = dynamic_cast<Graphics*>(Singleton<SystemManager>::getInstance().getSystem(SystemType::GRAPHICS_SYSTEM));
	if (graphics == nullptr)
		return FALSE;
	Logic* logic = dynamic_cast<Logic*>(Singleton<SystemManager>::getInstance().getSystem(SystemType::LOGIC_SYSTEM));
	if (logic == nullptr)
		return FALSE;

	if (!window->initialize())
		return FALSE;
	if (!input->initialize())
		return false;
	if (!timer->initialize())
		return FALSE;
	if (!graphics->initialize())
		return FALSE;

	logic->setGame(this->game);
	if (!logic->initialize())
		return FALSE;

	return TRUE;
}
void Engine::update()
{
	for (System* system : Singleton<SystemManager>::getInstance().getSystems())
		system->update();
}
int Engine::shutDown()
{
	if (!Singleton<SystemManager>::getInstance().shutdown())
		return FALSE;

	if (!destroyManagers())
		return FALSE;

	return TRUE;
}

bool Engine::createManagers()
{
	Singleton<WorldSettings>::createInstance();
	Singleton<SystemManager>::createInstance();
	Singleton<SceneManager>::createInstance();
	Singleton<VisualizationFactory>::createInstance();

	return true;
}
bool Engine::destroyManagers()
{
	Singleton<VisualizationFactory>::destroyInstance();
	Singleton<SceneManager>::destroyInstance();
	Singleton<SystemManager>::destroyInstance();
	Singleton<WorldSettings>::destroyInstance();

	return true;
}