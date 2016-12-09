#ifndef _LOGIC_H
#define _LOGIC_H

#include "System.h"

class AbstractGame;

class Logic : public System
{
public:
	Logic();
	virtual ~Logic();

	virtual bool initialize();
	void update();
	virtual bool shutdown();

	void setGame(AbstractGame* game);

private:

	AbstractGame* game;
};

#endif