#ifndef _MYSCENE_H
#define _MYSCENE_H

#include "SceneGraph/Objects/Scenes/Scene.h"

#ifndef _VECTOR2D_H
#include "Math/Objects/Vector2D.h"
#endif

class Input;

class MyScene : public Scene
{
public:
	MyScene();
	virtual ~MyScene();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	virtual void setupInput(Input* input);

private:
	void noDebugRendering();
	void debugOnlyRendering();
	void overlayDebugRendering();
};

#endif