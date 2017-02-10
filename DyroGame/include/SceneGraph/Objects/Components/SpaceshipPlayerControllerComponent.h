#ifndef _SPACESHIPPLAYERCONTROLLERCOMPONENT_H
#define _SPACESHIPPLAYERCONTROLLERCOMPONENT_H

#include "SceneGraph\Objects\Components\PlayerControllerComponent.h"

class SpaceshipPlayerControllerComponent : public PlayerControllerComponent
{
	OBJECT_STATICS("SpaceshipPlayerControllerComponent");

public:
	SpaceshipPlayerControllerComponent();
	virtual ~SpaceshipPlayerControllerComponent();

	virtual bool initialize();

	void startFire();
	void stopFire();

	void moveForward();
	void moveBackward();
	void rotateLeft();
	void rotateRight();

private:
	void handleFiring();
};

#endif