#include "SceneGraph\Component\Collision\BoxCollisionComponent.h"
#include "SceneGraph\Component\RigidBodyComponent.h"
#include "SceneGraph\Component\TransformComponent.h"

#include "SceneGraph/GameObjects/PhysicsObject.h"

#include "Defines\programdefaults.h"
#include "Defines\assert.h"

#include <Box2D\Box2D.h>

BoxCollisionComponent::BoxCollisionComponent(RigidBodyComponent* rigid, float width, float height, float restitution, float friction, float density, const std::tstring& name)
	:CollisionComponent(rigid, restitution, friction, density, name == _T("") ? _T("BoxCollisionComponent") : name)
	,width(width)
	,height(height)

{
	OBJECT_INIT(_T("BoxCollisionComponent"));
}
BoxCollisionComponent::~BoxCollisionComponent()
{}

bool BoxCollisionComponent::initialize()
{
	//Rigid body cannot be null
	assert(getRigid() != nullptr);

	b2FixtureDef fixtureDef;
	
	this->width /= constants::BOX2D_SCALE; 
	this->height /= constants::BOX2D_SCALE;

	b2PolygonShape shape;
	shape.SetAsBox(width / 2, height / 2);

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
void BoxCollisionComponent::update()
{
}
bool BoxCollisionComponent::shutdown()
{
	return true;
}

