#ifndef _MYSCENE_H
#define _MYSCENE_H

#include "SceneGraph/Scene/Scene.h"

class SceneObject;

class MyScene : public Scene
{
public:
	MyScene();
	virtual ~MyScene();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

private:

	SceneObject* rectangle;
	SceneObject* circle;
};

#endif