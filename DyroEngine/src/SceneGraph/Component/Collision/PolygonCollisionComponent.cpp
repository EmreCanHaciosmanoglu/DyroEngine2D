#include "SceneGraph\Component\Collision\PolygonCollisionComponent.h"
#include "SceneGraph\Component\RigidBodyComponent.h"

#include "Defines\programdefaults.h"
#include "Defines\assert.h"

#include <Box2D\Box2D.h>

PolygonCollisionComponent::PolygonCollisionComponent(RigidBodyComponent* rigid, std::vector<Vector2D> vertices, float restitution, float friction, float density, const std::tstring& name)
	:CollisionComponent(rigid,restitution,friction,density, name == _T("") ? _T("PolygonCollisionComponent") : name)
	,vertices(vertices)
{}
PolygonCollisionComponent::~PolygonCollisionComponent()
{}

bool PolygonCollisionComponent::initialize()
{
	//Rigid body cannot be null
	assert(getRigid() != nullptr);

	b2FixtureDef fixtureDef;

	std::vector<b2Vec2> vecArr;
	for (size_t i = 0; i < vertices.size(); i++)
		vecArr.push_back(b2Vec2(this->vertices[i].x / constants::BOX2D_SCALE, this->vertices[i].y / constants::BOX2D_SCALE));

	b2PolygonShape shape;
	shape.Set(vecArr.data(), vecArr.size());

	fixtureDef.shape = &shape;

	fixtureDef.density = getRigid()->getBody()->GetType() == b2_dynamicBody
		? getDensity()
		: 0.0f;
	fixtureDef.restitution = getRestitution();
	fixtureDef.friction = getFriction();

	fixtureDef.userData = (void *)getParent();

	//fixtureDef.filter = m_CollisionFilter;

	b2Fixture *fixturePtr = getRigid()->getBody()->CreateFixture(&fixtureDef);
	if (fixturePtr != nullptr)
		setAsTrigger(fixturePtr);

	return true;
}
void PolygonCollisionComponent::update()
{}
bool PolygonCollisionComponent::shutdown()
{
	return true;
}