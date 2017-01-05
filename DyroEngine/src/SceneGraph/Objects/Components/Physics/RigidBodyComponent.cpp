#include "SceneGraph\Objects\Components\RigidBodyComponent.h"
#include "SceneGraph\Objects\Components\TransformComponent.h"

#include "SceneGraph\Objects\GameObjects\SceneObject.h"

#include "SceneGraph\Objects\Scenes\Scene.h"

#include "Core\Defines\programdefaults.h"

#include <Box2D\Box2D.h>

RigidBodyComponent::RigidBodyComponent(BodyType bodyType, const std::tstring& name)
	:Component(name == _T("") ? _T("RigidBodyComponent") : name)
	, body(nullptr)
	, body_type(bodyType)
	, gravity_scale(1.0f)
	, linear_damping(0.0f)
	, angular_damping(0.0f)
	, is_dirty(false)
{
	OBJECT_INIT(_T("RigidBodyComponent"));

	setExecutionOrder(200);
}
RigidBodyComponent::~RigidBodyComponent()
{}

bool RigidBodyComponent::initialize()
{
	this->transform = dynamic_cast<SceneObject*>(getParent())->getTransform();

	//Create the physics body of the object
	if (!createBody(this->transform->getPosition(), this->transform->getRotation()))
		return false;

	return true;
}
void RigidBodyComponent::update()
{
	b2Vec2 position = this->body->GetPosition();
	float rotation = this->body->GetAngle();

	this->transform->setPosition(Vector2D::toVector2D(position) * (float)constants::BOX2D_SCALE);
	this->transform->setRotation(rotation);

	if (!is_dirty)
		return;

	this->is_dirty = false;

	getBody()->SetGravityScale(this->gravity_scale);
	getBody()->SetLinearDamping(this->linear_damping);
	getBody()->SetAngularDamping(this->angular_damping);
}
bool RigidBodyComponent::shutdown()
{
	getParent()->getScene()->getPhyxWorld()->DestroyBody(this->body);

	this->body = nullptr;

	return true;
}

b2Body* RigidBodyComponent::getBody() const
{
	return this->body;
}

void RigidBodyComponent::setGravityScale(float gravityScale)
{
	this->is_dirty = true;
	this->gravity_scale = gravityScale;
}
float RigidBodyComponent::getGravityScale() const
{
	return this->gravity_scale;
}

void RigidBodyComponent::setLinearDamping(float damping)
{
	this->is_dirty = true;
	this->linear_damping = damping;
}
float RigidBodyComponent::getLinearDamping() const
{
	return this->linear_damping;
}
void RigidBodyComponent::setAngularDamping(float damping)
{
	this->is_dirty = true;
	this->angular_damping = damping;
}
float RigidBodyComponent::getAngularDamping() const
{
	return this->angular_damping;
}

void RigidBodyComponent::setLinearVelocity(const Vector2D& velocity)
{
	Vector2D v = velocity;
	v /= constants::BOX2D_SCALE;

	this->body->SetLinearVelocity(b2Vec2((float)v.x, (float)v.y));
	this->body->SetAwake(true);
}
Vector2D RigidBodyComponent::getLinearVelocity() const
{
	b2Vec2 v = this->body->GetLinearVelocity();
	return Vector2D(v.x, v.y) * (float)constants::BOX2D_SCALE;
}
void RigidBodyComponent::setAngularVelocity(float velocity)
{
	this->body->SetAngularVelocity((float)velocity);
	this->body->SetAwake(true);
}
float  RigidBodyComponent::getAngularVelocity() const
{
	return this->body->GetAngularVelocity();
}

void RigidBodyComponent::ApplyForce(const Vector2D& force, const Vector2D& offsetPoint)
{
	Vector2D f = force;
	f /= (constants::BOX2D_SCALE * constants::BOX2D_SCALE);
	if (offsetPoint.x == 0 && offsetPoint.y == 0)
	{
		this->body->ApplyForceToCenter(b2Vec2((float)f.x, (float)f.y), true);
	}
	else
	{
		b2Vec2 p = this->body->GetWorldPoint(b2Vec2((float)offsetPoint.x / constants::BOX2D_SCALE, (float)offsetPoint.y / constants::BOX2D_SCALE));
		this->body->ApplyForce(b2Vec2((float)f.x, (float)f.y), p, true);
	}
}
void RigidBodyComponent::ApplyTorque(float torque)
{
	torque /= (constants::BOX2D_SCALE * constants::BOX2D_SCALE);
	this->body->ApplyTorque((float)torque, true);
}

void RigidBodyComponent::ApplyLinearImpulse(const Vector2D& impulse, const Vector2D& offsetPoint)
{
	Vector2D i = impulse;
	i /= (constants::BOX2D_SCALE * constants::BOX2D_SCALE);
	b2Vec2 p = this->body->GetWorldPoint(b2Vec2((float)offsetPoint.x / constants::BOX2D_SCALE, (float)offsetPoint.y / constants::BOX2D_SCALE));
	this->body->ApplyLinearImpulse(b2Vec2((float)i.x, (float)i.y), p, true);
}
void RigidBodyComponent::ApplyAngularImpulse(float impulse)
{
	impulse /= (constants::BOX2D_SCALE * constants::BOX2D_SCALE);
	this->body->ApplyAngularImpulse((float)impulse, true);
}

bool RigidBodyComponent::createBody(const Vector2D& position, const float angle)
{
	Vector2D pos = position;

	b2BodyDef bodyDef;
	// Define the dynamic body. We set its position and call the body factory.
	switch (this->body_type)
	{
	case BodyType::DYNAMIC:
		bodyDef.type = b2_dynamicBody;
		break;
	case BodyType::STATIC:
		bodyDef.type = b2_staticBody;
		break;
	case BodyType::KINEMATIC:
		bodyDef.type = b2_kinematicBody;
		break;
	}

	pos.x /= constants::BOX2D_SCALE;
	pos.y /= constants::BOX2D_SCALE;

	bodyDef.position.Set(pos.x, pos.y);
	bodyDef.angle = angle;
	bodyDef.gravityScale = this->gravity_scale;
	bodyDef.linearDamping = this->linear_damping;
	bodyDef.angularDamping = this->angular_damping;

	bodyDef.userData = (void*)getParent();

	this->body = getParent()->getScene()->getPhyxWorld()->CreateBody(&bodyDef);

	return this->body != nullptr;
}