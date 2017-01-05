#include "Core/Engine.h"

#ifndef _WINDOWS_
#include <Windows.h>
#endif

#include "Core/System/Objects/System.h"
#include "Core\System\Objects\Logic.h"
#include "Core\System\Objects\Window.h"
#include "Core\System\Objects\Graphics.h"
#include "Core\System\Objects\Input.h"
#include "Core/System/Manager/SystemManager.h"

#include "Core/Types/SystemType.h"
#include "Core/Types/SettingsType.h"

#include "Rendering/Manager/VisualizationManager.h"
#include "Rendering/Factory/VisualizationFactory.h"

#include "Core/Helpers/Patterns/Singleton.h"

#include "Core/Diagnostics/Logger.h"

#include "SceneGraph/Manager/SceneManager.h"

#include "Core/Data/Objects/Game.h"
#include "Core/Data/Factory/SettingsFactory.h"
#include "Core/Data/Manager/SettingsManager.h"

//#include <ctime>
//#include <iostream>

namespace
{
	const int INITIALIZATION_FAILED = 0x0001;
	const int SHUTDOWN_FAILED = 0x0010;
}

Engine::Engine(Game* game)
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
	srand(GetTickCount());

	MSG msg = {};
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		//clock_t current_ticks, delta_ticks;
		//clock_t fps = 0;

		//current_ticks = clock();

		update();

		//delta_ticks = clock() - current_ticks; //the time, in ms, that took to render the scene
		//if (delta_ticks > 0)
		//	fps = CLOCKS_PER_SEC / delta_ticks;
		//std::cout << fps << std::endl;
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

	SettingsFactory factory;

	Singleton<SettingsManager>::getInstance().addSettings(factory.createSettings(_T("resources/INI/Engine.ini"), SettingsType::APPLICATION_SETTINGS));
	Singleton<SettingsManager>::getInstance().addSettings(factory.createSettings(_T("resources/INI/Engine.ini"), SettingsType::GAME_SETTINGS));
	Singleton<SettingsManager>::getInstance().addSettings(factory.createSettings(_T("resources/INI/Engine.ini"), SettingsType::PHYSICS_SETTINGS));

	if (!Singleton<SettingsManager>::getInstance().initialize())
		return FALSE;
	if (!Singleton<SystemManager>::getInstance().initialize())
		return FALSE;

	Window* window = dynamic_cast<Window*>(Singleton<SystemManager>::getInstance().getSystem(SystemType::WINDOW_SYSTEM));
	if (window == nullptr)
		return FALSE;
	Input* input = dynamic_cast<Input*>(Singleton<SystemManager>::getInstance().getSystem(SystemType::INPUT_SYSTEM));
	if (input == nullptr)
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
	if (!graphics->initialize())
		return FALSE;

	logic->setGame(this->game);
	if (!logic->initialize())
		return FALSE;

	return TRUE;
}
void Engine::update()
{
	std::vector<System*> systems;
	Singleton<SystemManager>::getInstance().getSystems(systems);
	for (System* system : systems)
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
	Singleton<SettingsManager>::createInstance();
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
	Singleton<SettingsManager>::destroyInstance();

	return true;
}