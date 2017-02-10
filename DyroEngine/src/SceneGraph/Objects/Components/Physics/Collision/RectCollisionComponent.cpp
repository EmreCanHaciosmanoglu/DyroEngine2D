#include "SceneGraph\Objects\Components\Physics\Collision\RectCollisionComponent.h"
#include "SceneGraph\Objects\Components\Physics\RigidBodyComponent.h"
#include "SceneGraph\Objects\Components\TransformComponent.h"

#include "SceneGraph/Objects/GameObjects\Physics/PhysicsObject.h"

#include "Core\Defines\programdefaults.h"
#include "Core\Defines\assert.h"

#include <Box2D\Box2D.h>

RectCollisionComponent::RectCollisionComponent(RigidBodyComponent* rigid, float width, float height, float restitution, float friction, float density, const std::tstring& name)
	:CollisionComponent(rigid, restitution, friction, density, name == _T("") ? _T("RectCollisionComponent") : name)
	, width(width)
	, height(height)

{
	OBJECT_INIT(_T("RectCollisionComponent"));
}
RectCollisionComponent::~RectCollisionComponent()
{}

bool RectCollisionComponent::initialize()
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
void RectCollisionComponent::update()
{
}
bool RectCollisionComponent::shutdown()
{
	return true;
}