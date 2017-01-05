#include "SceneGraph\Objects\Components\Collision\CollisionComponent.h"
#include "SceneGraph\Objects\Components\RigidBodyComponent.h"

#include "SceneGraph\Objects\GameObjects\PhysicsObject.h"

#include "Core\Defines\collisionlayers.h"

CollisionComponent::CollisionComponent(RigidBodyComponent* rigid, float restitution, float friction, float density, const std::tstring& name)
	:Component(name)
	, restitution(restitution)
	, friction(friction)
	, density(density)
	, rigid(rigid)
{
	OBJECT_INIT(_T("CollisionComponent"));

	setExecutionOrder(300);
}
CollisionComponent::~CollisionComponent()
{}

void CollisionComponent::setCollisionLayer(const b2Filter& layer)
{
	this->collision_layer = layer;

	//apply on all fixtures
	for (b2Fixture* fixturePtr = getRigid()->getBody()->GetFixtureList(); fixturePtr != nullptr; fixturePtr = fixturePtr->GetNext())
		fixturePtr->SetFilterData(layer);
}
const b2Filter& CollisionComponent::getCollisionLayer() const
{
	return this->collision_layer;
}

void CollisionComponent::setAsTrigger(bool trigger)
{
	this->is_trigger = trigger;
	for (b2Fixture* fixture = this->rigid->getBody()->GetFixtureList(); fixture != nullptr; fixture = fixture->GetNext())
	{
		fixture->SetSensor(this->is_trigger);
	}
}
bool CollisionComponent::getIsTrigger() const
{
	return this->is_trigger;
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