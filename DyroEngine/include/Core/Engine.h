#ifndef _ENGINE_H
#define _ENGINE_H

#pragma warning(disable: 4100) // unreferenced formal parameter
#pragma warning(disable: 4458) // hides class member

class Game;

class Engine
{
public:
	Engine(Game* game);
	~Engine();

	int mainLoop();

private:

	int initialize();
	void update();
	int shutDown();

	bool createGame();
	bool destroyGame();

	bool addSettings();
	bool addSystems();

	bool createManagers();
	bool destroyManagers();

	Game* game;
};

#endif // _ENGINE_H
