#ifndef _MYGAME_H
#define _MYGAME_H

#include "Core/Data/Objects/Game.h"

class MyGame : public Game
{
public:
	MyGame();
	virtual ~MyGame();

	virtual bool initialize();
	virtual bool shutdown();
};

#endif