#include "SceneGraph\Objects\Components\SpaceshipWeaponComponent.h"

#include "Core\Data\Objects\Timers\WorldTimer.h"

#include "Core\Defines\debug.h"

SpaceshipWeaponComponent::SpaceshipWeaponComponent()
	:Component(_T("SpaceshipWeaponComponent"))
	, firing(false)
	, fire_rate(0.2f)
	, fire_cooldown(0.0f, fire_rate)
{
	OBJECT_INIT(_T("SpaceshipWeaponComponent"));

	setExecutionOrder(500);
}
SpaceshipWeaponComponent::~SpaceshipWeaponComponent()
{}

bool SpaceshipWeaponComponent::initialize()
{
	return true;
}
void SpaceshipWeaponComponent::update()
{
	if (firing && fire_cooldown.isFinished())
	{
		fire_cooldown.reset();
		fire();
	}
	else if (firing && fire_cooldown.isRunning())
	{
		fire_cooldown.update();
	}
	else if (firing && !fire_cooldown.isRunning())
	{
		fire_cooldown.setSpeed(WorldTimer::getWorldDeltaTime());
		fire_cooldown.start();
	}
}
bool SpaceshipWeaponComponent::shutdown()
{
	return true;
}

void SpaceshipWeaponComponent::startFire()
{
	this->firing = true;
}
void SpaceshipWeaponComponent::stopFire()
{
	this->firing = false;
}

void SpaceshipWeaponComponent::setFireRate(float rate)
{
	this->fire_rate = rate;
	this->fire_cooldown.setDestination(rate);
}
float SpaceshipWeaponComponent::getFireRate() const
{
	return this->fire_rate;
}

void SpaceshipWeaponComponent::fire()
{
	LogManager::getInstance().log(new InfoLog(_T("Fire!"), LOG_INFO));
}