#include "Core/System/Logic.h"
#include "Core/Game/AbstractGame.h"

#include "SceneGraph/Scene/Manager/SceneManager.h"

#include "Helpers/Singleton.h"

#include "Defines\Types\SystemType.h"
#include "Defines\assert.h"
#include "Defines/deletemacros.h"

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
void Logic::draw()
{
	if (Singleton<SceneManager>::getInstance().getCanDraw())
		Singleton<SceneManager>::getInstance().draw();
}
bool Logic::shutdown()
{
	if (!Singleton<SceneManager>::getInstance().shutdown())
		return false;

	if (!game->shutdown())
		return false;

	return true;
}

void Logic::setGame(AbstractGame* game)
{
	this->game = game;
}