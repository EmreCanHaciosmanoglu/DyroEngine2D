#include "SceneGraph\Component\Collision\CollisionComponent.h"
#include "SceneGraph\Component\RigidBodyComponent.h"

#include "SceneGraph\Object\GameObjects\PhysicsObject.h"

#include <Box2D\Box2D.h>

CollisionComponent::CollisionComponent(RigidBodyComponent* rigid, float restitution, float friction, float density , const std::tstring& name)
	:Component(name)
	, restitution(restitution)
	, friction(friction)
	, density(density)
	, rigid(rigid)
{
	setExecutionOrder(300);
}
CollisionComponent::~CollisionComponent()
{}

void CollisionComponent::isTrigger(bool trigger)
{
	this->is_trigger = trigger;
	for (b2Fixture* fixturePtr = this->rigid->getBody()->GetFixtureList(); fixturePtr != nullptr; fixturePtr = fixturePtr->GetNext())
	{
		setAsTrigger(fixturePtr);
	}
}

void CollisionComponent::setAsTrigger(b2Fixture* fixture)
{
	fixture->SetSensor(this->is_trigger);
}

float CollisionComponent::getRestitution() const
{
	return this->restitution;
}
float CollisionComponent::getFriction() const
{
	return this->friction;
}
float CollisionComponent::getDensity() const
{
	return this->density;
}

RigidBodyComponent* CollisionComponent::getRigid() const
{
	return this->rigid;
}