#include "Core/System/Objects/Logic.h"
#include "Core/Data/Objects/Game.h"

#include "SceneGraph/Manager/SceneManager.h"

#include "Core/Helpers/Patterns/Singleton.h"

#include "Core\Types\SystemType.h"
#include "Core/Defines\assert.h"
#include "Core/Defines/deletemacros.h"

Logic::Logic()
	:System(SystemType::LOGIC_SYSTEM)
	, game(nullptr)
{}
Logic::~Logic()
{}

bool Logic::initialize()
{
	//Game cannot be null!
	assert(this->game != nullptr);

	if (!game->initialize())
		return false;

	if (!Singleton<SceneManager>::getInstance().initialize())
		return false;

	return true;
}
void Logic::update()
{
	if (!getIsActive())
		return;

	Singleton<SceneManager>::getInstance().update();
}
bool Logic::shutdown()
{
	if (!Singleton<SceneManager>::getInstance().shutdown())
		return false;

	if (!game->shutdown())
		return false;

	return true;
}

void Logic::setGame(Game* game)
{
	this->game = game;
}