#ifndef _SPACESHIP_H
#define _SPACESHIP_H

#include "SceneGraph\Objects\GameObjects\Physics\PhysicsObject.h"

class SpaceshipPlayerControllerComponent;
class SpaceshipWeaponComponent;

class SpaceShip : public PhysicsObject
{
	OBJECT_STATICS("Spaceship")

public:
	SpaceShip(const Vector2D& startPosition);
	virtual ~SpaceShip();

	virtual bool initialize();

	virtual void setupInput(Input* input);

private:
	void moveForward();
	void moveBackward();
	void moveLeft();
	void moveRight();

	SpaceshipPlayerControllerComponent* controller;
	SpaceshipWeaponComponent* weapon;
};

#endif