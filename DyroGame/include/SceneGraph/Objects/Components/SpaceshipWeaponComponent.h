#ifndef _SPACESHIPWEAPONCOMPONENT_H
#define _SPACESHIPWEAPONCOMPONENT_H

#include "SceneGraph\Objects\Components\Component.h"

#ifndef _TRANSITION_H
#include "Core/Data/Objects/Transition.h"
#endif

class SpaceshipWeaponComponent : public Component
{
	OBJECT_STATICS("SpaceshipWeaponComponent");

public:
	SpaceshipWeaponComponent();
	virtual ~SpaceshipWeaponComponent();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	void startFire();
	void stopFire();

	void setFireRate(float fireRate);

	float getFireRate() const;

private:
	void fire();

	bool firing;
	float fire_rate;
	Transition<float> fire_cooldown;
};

#endif