#ifndef _MYSCENE_H
#define _MYSCENE_H

#include "SceneGraph/Scene/Scene.h"

class SceneObject;
class Input;
class FreeCamera;

class MyScene : public Scene
{
public:
	MyScene();
	virtual ~MyScene();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	virtual void setupInput(Input* input);

	void changeColorRectangle();
	void changeColorCircle();

private:
	FreeCamera* camera;

	SceneObject* rectangle;
	SceneObject* circle;
};

#endif