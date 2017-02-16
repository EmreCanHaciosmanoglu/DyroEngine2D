#include "Core/Engine.h"

#ifndef _WINDOWS_
#include <Windows.h>
#endif

#include "Core/System/Manager/SystemManager.h"
#include "Core/System/Objects/System.h"
#include "Core\System\Objects\Logic.h"
#include "Core\System\Objects\Window.h"
#include "Core\System\Objects\Graphics.h"
#include "Core\System\Objects\Input.h"

#include "Core/Types/SystemType.h"
#include "Core/Types/SettingsType.h"
#include "Core/Types/EngineStateType.h"

#include "Core/Data/Factory/SettingsFactory.h"
#include "Core/Data/Manager/SettingsManager.h"

#include "Core/Data/Objects/Game.h"

#include "Core\Defines\debug.h"

namespace
{
	const int INITIALIZATION_FAILED = 0x0001;
	const int SHUTDOWN_FAILED = 0x0010;
}

EngineState::EngineStateType EngineState::ENGINE_STATE = EngineState::EngineStateType::INVALID;

Engine::Engine(Game* game)
	:game(game)
{
	LogManager::createInstance();
}
Engine::~Engine()
{
	LogManager::destroyInstance();
}

int Engine::mainLoop()
{
	//CREATE APP
	EngineState::ENGINE_STATE = EngineState::EngineStateType::CREATING;

	if (!initialize())
	{
		LogManager::getInstance().log(new ErrorLog(_T("Initialization of the engine failed."), LOG_INFO));
		return INITIALIZATION_FAILED;
	}

	// Seed the random number generator
	srand(GetTickCount());

	MSG msg = {};
	while (msg.message != WM_QUIT)
	{
		//RUN APP
		EngineState::ENGINE_STATE = EngineState::EngineStateType::RUNNING;

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

	//DESTROY APP
	EngineState::ENGINE_STATE = EngineState::EngineStateType::DESTROYING;

	if (!shutDown())
	{
		LogManager::getInstance().log(new ErrorLog(_T("Shutdown of the engine failed."), LOG_INFO));
		return SHUTDOWN_FAILED;
	}

	return msg.wParam;
}

int Engine::initialize()
{
	if (!createManagers())
		return FALSE;

	SettingsFactory factory;

	if(!SettingsManager::getInstance().addSettings(factory.createSettings(_T("resources/INI/Engine.ini"), SettingsType::APPLICATION_SETTINGS)))
		return FALSE;
	if(!SettingsManager::getInstance().addSettings(factory.createSettings(_T("resources/INI/Engine.ini"), SettingsType::GAME_SETTINGS)))
		return FALSE;
	if(!SettingsManager::getInstance().addSettings(factory.createSettings(_T("resources/INI/Engine.ini"), SettingsType::PHYSICS_SETTINGS)))
		return FALSE;

	if (!SettingsManager::getInstance().initialize())
		return FALSE;
	if (!SystemManager::getInstance().initialize())
		return FALSE;

	if (!SystemManager::getInstance().addSystem(SystemType::WINDOW_SYSTEM))
		return FALSE;
	if(!SystemManager::getInstance().addSystem(SystemType::INPUT_SYSTEM))
		return FALSE;
	if(!SystemManager::getInstance().addSystem(SystemType::GRAPHICS_SYSTEM))
		return FALSE;
	if(!SystemManager::getInstance().addSystem(SystemType::LOGIC_SYSTEM))
		return FALSE;

	Window* window = SystemManager::getInstance().getSystem<Window>();
	Input* input = SystemManager::getInstance().getSystem<Input>();
	Graphics* graphics = SystemManager::getInstance().getSystem<Graphics>();
	Logic* logic = SystemManager::getInstance().getSystem<Logic>();

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
	SystemManager::getInstance().getSystems(systems);
	for (System* system : systems)
		system->update();
}
int Engine::shutDown()
{
	if (!SystemManager::getInstance().shutdown())
		return FALSE;
	if (!SettingsManager::getInstance().shutdown())
		return FALSE;

	if (!destroyManagers())
		return FALSE;

	return TRUE;
}

bool Engine::createManagers()
{
	SettingsManager::createInstance();
	SystemManager::createInstance();

	return true;
}
bool Engine::destroyManagers()
{
	SystemManager::destroyInstance();
	SettingsManager::destroyInstance();

	return true;
}