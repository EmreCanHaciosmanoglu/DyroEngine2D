#include "Core/Engine.h"

#ifndef _WINDOWS_
#include <Windows.h>
#endif

#include "Core\System\Manager\SystemManager.h"
#include "Core\System\Objects\System.h"
#include "Core\System\Objects\Logic.h"
#include "Core\System\Objects\Window.h"
#include "Core\System\Objects\Graphics.h"
#include "Core\System\Objects\Input.h"

#include "Core\Types\SystemType.h"
#include "Core\Types\SettingsType.h"
#include "Core\Types\SceneManagerStateType.h"

#include "Core\Data\Manager\SettingsManager.h"
#include "Core\Data\Manager\MessageManager.h"
#include "Core\Data\Objects\Game.h"

#include "Core\Defines\debug.h"

namespace
{
	const int INITIALIZATION_FAILED = 0x0001;
	const int SHUTDOWN_FAILED = 0x0010;
}

Engine::Engine(Game* game)
	:game(game)
{
	LogManager::createInstance();
	MessageManager::createInstance();

	LogManager::getInstance().initialize();
	MessageManager::getInstance().initialize();
}
Engine::~Engine()
{
	MessageManager::getInstance().shutdown();
	LogManager::getInstance().shutdown();

	MessageManager::destroyInstance();
	LogManager::destroyInstance();
}

int Engine::mainLoop()
{
	//CREATE APP
	if (!initialize())
	{
		LogManager::getInstance().log(new ErrorLog(_T("Initialization of the engine failed."), LOG_DATA));
		return INITIALIZATION_FAILED;
	}

	// Seed the random number generator
	srand((unsigned int)GetTickCount64());

	//RUN APP
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

	//DESTROY APP
	if (!shutDown())
	{
		LogManager::getInstance().log(new ErrorLog(_T("Shutdown of the engine failed."), LOG_DATA));
		return SHUTDOWN_FAILED;
	}

	return msg.wParam;
}

int Engine::initialize()
{
	if (!createManagers())
		return FALSE;

	if (!addSettings())
		return FALSE;
	if (!addSystems())
		return FALSE;

	if (!createGame())
		return FALSE;

	if (!initializeSettings())
		return FALSE;
	if (!initializeSystems())
		return FALSE;

	return TRUE;
}
void Engine::update()
{
	MessageManager::getInstance().update();

	//std::vector<System*> systems;
	//SystemManager::getInstance().getSystems(systems);
	//for (System* system : systems)
	//	system->update();

	SystemManager::getInstance().getSystem<Window>()->update();
	SystemManager::getInstance().getSystem<Input>()->update();
	SystemManager::getInstance().getSystem<Graphics>()->update();
	SystemManager::getInstance().getSystem<Logic>()->update();
}
int Engine::shutDown()
{
	if (!destroyGame())
		return FALSE;

	if (!shutdownSettings())
		return FALSE;
	if (!shutdownSystems())
		return FALSE;

	if (!destroyManagers())
		return FALSE;

	return TRUE;
}

bool Engine::createGame()
{
	//Game cannot be null!
	assert(this->game != nullptr);

	if (!game->initialize())
		return false;

	return true;
}
bool Engine::destroyGame()
{
	if (!game->shutdown())
		return false;

	return true;
}

bool Engine::addSettings()
{
	if (!SettingsManager::getInstance().addSettings(SettingsType::APPLICATION_SETTINGS))
		return false;
	if (!SettingsManager::getInstance().addSettings(SettingsType::GAME_SETTINGS))
		return false;
	if (!SettingsManager::getInstance().addSettings(SettingsType::PHYSICS_SETTINGS))
		return false;

	return true;
}
bool Engine::addSystems()
{
	if (!SystemManager::getInstance().addSystem(SystemType::WINDOW_SYSTEM))
		return false;
	if (!SystemManager::getInstance().addSystem(SystemType::INPUT_SYSTEM))
		return false;
	if (!SystemManager::getInstance().addSystem(SystemType::GRAPHICS_SYSTEM))
		return false;
	if (!SystemManager::getInstance().addSystem(SystemType::LOGIC_SYSTEM))
		return false;

	return true;
}

bool Engine::initializeSettings()
{
	if (!SettingsManager::getInstance().initialize())
		return false;

	return true;
}
bool Engine::initializeSystems()
{
	std::vector<System*> systems;
	SystemManager::getInstance().getSystems(systems);
	for (System* system : systems)
		MessageManager::getInstance().subscribeListener(system);

	if (!SystemManager::getInstance().initialize())
		return false;

	return true;
}
bool Engine::shutdownSettings()
{
	if (!SystemManager::getInstance().shutdown())
		return false;

	return true;
}
bool Engine::shutdownSystems()
{
	if (!SettingsManager::getInstance().shutdown())
		return false;

	return true;
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