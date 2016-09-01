#ifndef _ENGINE_H
#define _ENGINE_H

class AbstractGame;

class Engine
{
public:
	Engine(AbstractGame* game);
	~Engine();

	int mainLoop();

private:

	int initialize();
	void draw();
	void update();
	int shutDown();

	bool createManagers();
	bool destroyManagers();

	AbstractGame* game;
};

#endif // _ENGINE_H
