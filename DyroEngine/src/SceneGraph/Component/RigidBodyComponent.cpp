#include "SceneGraph\Component\RigidBodyComponent.h"
#include "SceneGraph\Component\TransformComponent.h"

#include "SceneGraph\Object\GameObjects\SceneObject.h"

#include "SceneGraph\Scene\Scene.h"

#include "Defines\programdefaults.h"

#include <Box2D\Box2D.h>

RigidBodyComponent::RigidBodyComponent(BodyType bodyType, const std::tstring& name)
	:Component(name == _T("") ? _T("RigidBodyComponent") : name)
	,body(nullptr)
	,body_type(bodyType)
{
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

	this->body = getParent()->getScene()->getPhyxWorld()->CreateBody(&bodyDef);

	return this->body != nullptr;
}