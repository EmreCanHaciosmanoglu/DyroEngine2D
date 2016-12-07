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
	virtual bool postInitialize();
	virtual void update();
	virtual bool shutdown();

	virtual void setupInput(Input* input);

private:
	void addBorder(const Vector2D& position, float colliderWidth, float colliderHeight);
	void addAstroid(const Vector2D& position, float radius, const Vector2D& direction);

	void spawnAstroids(int astroidAmount);

	Spaceship* spaceship;
};

#endif