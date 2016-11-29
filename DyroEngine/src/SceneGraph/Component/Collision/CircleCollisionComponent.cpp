#include "SceneGraph\Component\Collision\CircleCollisionComponent.h"
#include "SceneGraph\Component\RigidBodyComponent.h"

#include "Defines\programdefaults.h"
#include "Defines\assert.h"

#include <Box2D\Box2D.h>

CircleCollisionComponent::CircleCollisionComponent(RigidBodyComponent* rigid, float radius, float restitution, float friction, float density, const std::tstring& name)
	:CollisionComponent(rigid,restitution,friction,density, name == _T("") ? _T("CircleCollisionComponent") : name)
	,radius(radius)
{}
CircleCollisionComponent::~CircleCollisionComponent()
{}

bool CircleCollisionComponent::initialize()
{
	//Rigid body cannot be null
	assert(getRigid() != nullptr);

	b2FixtureDef fixtureDef;

	this->radius /= constants::BOX2D_SCALE;

	b2CircleShape shape; 
	shape.m_radius = (float)radius;

	fixtureDef.shape = &shape;

	fixtureDef.density = getRigid()->getBody()->GetType() == b2_dynamicBody
		? getDensity()
		: 0.0f;
	fixtureDef.restitution = getRestitution();
	fixtureDef.friction = getFriction();

	fixtureDef.userData = (void *)this;

	//fixtureDef.filter = m_CollisionFilter;

	b2Fixture *fixturePtr = getRigid()->getBody()->CreateFixture(&fixtureDef);
	if (fixturePtr != nullptr)
		setAsTrigger(fixturePtr);

	return true;
}
void CircleCollisionComponent::update()
{}
bool CircleCollisionComponent::shutdown()
{
	return true;
}