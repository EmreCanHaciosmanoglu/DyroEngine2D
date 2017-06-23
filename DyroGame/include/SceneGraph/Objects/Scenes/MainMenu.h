#ifndef _MAINMENU_H
#define _MAINMENU_H

#include "SceneGraph/Objects/Scenes/Scene.h"

class Input;

class MainMenu : public Scene
{
	OBJECT_STATICS("MainMenu");

public:
	MainMenu();
	virtual ~MainMenu();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	virtual void setupInput(Input* input);

private:
	void startGame();
	void exitGame();
};

#endif