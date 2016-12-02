#include "SceneGraph\Component\Collision\BoxCollisionComponent.h"
#include "SceneGraph\Component\RigidBodyComponent.h"
#include "SceneGraph\Component\TransformComponent.h"

#include "SceneGraph/Object/GameObjects/PhysicsObject.h"

#include "Defines\programdefaults.h"
#include "Defines\assert.h"

#include <Box2D\Box2D.h>

namespace
{
	const int BOX_COLLISION_VERTICES_SIZE = 4;
}

BoxCollisionComponent::BoxCollisionComponent(RigidBodyComponent* rigid, float width, float height, float restitution, float friction, float density, const std::tstring& name)
	:CollisionComponent(rigid, restitution, friction, density, name == _T("") ? _T("BoxCollisionComponent") : name)
	,width(width)
	,height(height)

{}
BoxCollisionComponent::~BoxCollisionComponent()
{}

bool BoxCollisionComponent::initialize()
{
	//Rigid body cannot be null
	assert(getRigid() != nullptr);

	b2FixtureDef fixtureDef;
	
	this->width /= constants::BOX2D_SCALE; 
	this->height /= constants::BOX2D_SCALE;

	b2Vec2* vertices = new b2Vec2[BOX_COLLISION_VERTICES_SIZE];

	vertices[0] = (b2Vec2(0.0f, 0.0f));
	vertices[1] = (b2Vec2(1.0f * width, 0.0f));
	vertices[2] = (b2Vec2(1.0f * width, 1.0f * height));
	vertices[3] = (b2Vec2(0.0f, 1.0f * height));

	//TransformComponent* transform = dynamic_cast<PhysicsObject*>(getParent())->getTransform();

	b2PolygonShape shape;
	//shape.SetAsBox(this->width / 2.0f, this->height / 2.0f, Vector2D::toBox2DVec(transform->getCenterPosition()), transform->getRotation());
	shape.Set(vertices, BOX_COLLISION_VERTICES_SIZE);
	shape.m_centroid.SetZero();

	fixtureDef.shape = &shape;

	fixtureDef.density = getRigid()->getBody()->GetType() == b2_dynamicBody
		? getDensity()
		: 0.0f;
	fixtureDef.restitution = getRestitution();
	fixtureDef.friction = getFriction();

	fixtureDef.userData = (void *)this;

	//fixtureDef.filter = m_CollisionFilter;

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

