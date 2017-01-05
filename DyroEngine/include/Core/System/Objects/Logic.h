#ifndef _LOGIC_H
#define _LOGIC_H

#include "System.h"

class Game;

class Logic : public System
{
public:
	Logic();
	virtual ~Logic();

	virtual bool initialize();
	void update();
	virtual bool shutdown();

	void setGame(Game* game);

private:

	Game* game;
};

#endif