#ifndef _GAME_H
#define _GAME_H

class Game
{
public:
	Game();
	virtual ~Game();

	virtual bool initialize() = 0;
	virtual bool shutdown() = 0;
};

#endif