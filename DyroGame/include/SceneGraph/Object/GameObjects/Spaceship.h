#ifndef _SPACESHIP_H
#define _SPACESHIP_H

#include "SceneGraph\Object\GameObjects\PhysicsObject.h"

class Input;

class Spaceship : public PhysicsObject
{
public:
	Spaceship(const std::tstring& name);
	virtual ~Spaceship();

	virtual bool initialize();
	virtual void draw();
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