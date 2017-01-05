#ifndef _SPACESHIP_H
#define _SPACESHIP_H

#include "SceneGraph\Objects\GameObjects\PhysicsObject.h"

#ifndef _VECTOR2D_H
#include "Math\Objects\Vector2D.h"
#endif

class Input;

class Spaceship : public PhysicsObject
{
public:
	Spaceship(const std::tstring& name);
	virtual ~Spaceship();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	virtual void setupInput(Input* input);

private:
	void moveForward();
	void moveBackward();
	void rotateRight();
	void rotateLeft();
};

#endif