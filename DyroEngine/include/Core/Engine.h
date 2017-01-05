#ifndef _ENGINE_H
#define _ENGINE_H

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

	bool createManagers();
	bool destroyManagers();

	Game* game;
};

#endif // _ENGINE_H
