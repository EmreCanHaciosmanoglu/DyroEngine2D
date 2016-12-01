#ifndef _TESTSCENE_H
#define _TESTSCENE_H

#include "SceneGraph/Scene/Scene.h"

#ifndef _VECTOR2D_H
#include "Helpers\Math\Vector2D.h"
#endif

class Input;

class Spaceship;

class TestScene : public Scene
{
public:
	TestScene();
	virtual ~TestScene();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	virtual void setupInput(Input* input);

private:
	void addObstacle(const Vector2D& position, float colliderWidth, float colliderHeight);

	Spaceship* spaceship;
};

#endif