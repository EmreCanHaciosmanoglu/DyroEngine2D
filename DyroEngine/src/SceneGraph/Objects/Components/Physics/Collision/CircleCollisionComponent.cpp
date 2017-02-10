#include "SceneGraph\Objects\Components\Physics\Collision\CircleCollisionComponent.h"
#include "SceneGraph\Objects\Components\Physics\RigidBodyComponent.h"

#include "Core\Defines\programdefaults.h"
#include "Core\Defines\assert.h"

#include <Box2D\Box2D.h>

CircleCollisionComponent::CircleCollisionComponent(RigidBodyComponent* rigid, float radius, float restitution, float friction, float density, const std::tstring& name)
	:CollisionComponent(rigid, restitution, friction, density, name == _T("") ? _T("CircleCollisionComponent") : name)
	, radius(radius)
{
	OBJECT_INIT(_T("CircleCollisionComponent"));
}
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

	fixtureDef.filter = getCollisionLayer();

	b2Fixture *fixturePtr = getRigid()->getBody()->CreateFixture(&fixtureDef);
	if (fixturePtr == nullptr)
		return false;

	return true;
}
void CircleCollisionComponent::update()
{}
bool CircleCollisionComponent::shutdown()
{
	return true;
}