#ifndef _SPACESHIP_H
#define _SPACESHIP_H

#include "SceneGraph\Object\GameObjects\PhysicsObject.h"

#ifndef _VECTOR2D_H
	#include "Helpers\Math\Vector2D.h"
#endif

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

	Vector2D direction;
};

#endif