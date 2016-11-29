#include "SceneGraph/Object/GameObjects/Spaceship.h"

#include "SceneGraph/Component/ShapeComponent.h"
#include "SceneGraph/Component/RigidBodyComponent.h"
#include "SceneGraph/Component/TransformComponent.h"
#include "SceneGraph/Component/Collision/TriangleCollisionComponent.h"

#include "SceneGraph/Object/Objects/Shapes/TriangleShape.h"

#include "Core/System/Input.h"
#include "Core/System/MainTimer.h"

namespace
{
	const float SPACESHIP_SCALE = 20.0f;

	const float PI = 3.1415f;

	const float THRUST = 2.0f;
}

Spaceship::Spaceship(const std::tstring& name)
	:PhysicsObject(BodyType::DYNAMIC,name)
{}
Spaceship::~Spaceship()
{}

bool Spaceship::initialize()
{
	addComponent(new ShapeComponent(new TriangleShape(SPACESHIP_SCALE, SPACESHIP_SCALE)));
	addComponent(new TriangleCollisionComponent(getRigidBody(), SPACESHIP_SCALE, SPACESHIP_SCALE));

	getTransform()->rotate(PI/2);
	getRigidBody()->setGravityScale(0.0f);

	return PhysicsObject::initialize();
}
void Spaceship::draw()
{
	return PhysicsObject::draw();
}
void Spaceship::update()
{
	return PhysicsObject::update();
}
bool Spaceship::shutdown()
{
	return PhysicsObject::shutdown();
}

void Spaceship::setupInput(Input* input)
{
	input->bindInput(InputBinding(VK_UP, std::bind(&Spaceship::moveForward, this), InputStateType::DOWN));
	input->bindInput(InputBinding(VK_DOWN, std::bind(&Spaceship::moveBackward, this), InputStateType::DOWN));
	input->bindInput(InputBinding(VK_LEFT, std::bind(&Spaceship::rotateLeft, this), InputStateType::DOWN));
	input->bindInput(InputBinding(VK_RIGHT, std::bind(&Spaceship::rotateRight, this), InputStateType::DOWN));
}

void Spaceship::moveForward()
{
	RigidBodyComponent* rigid = getRigidBody();

	Vector2D direction = rigid->getLinearVelocity().Normalize();
	Vector2D force = direction * THRUST * -1;

	rigid->ApplyForce(force);
}
void Spaceship::moveBackward()
{
	RigidBodyComponent* rigid = getRigidBody();

	Vector2D direction = rigid->getLinearVelocity().Normalize();
	Vector2D force = direction * THRUST * 1;

	rigid->ApplyForce(force);
}
void Spaceship::rotateRight()
{
	RigidBodyComponent* rigid = getRigidBody();

	rigid->ApplyTorque(THRUST * -1);
}
void Spaceship::rotateLeft()
{
	RigidBodyComponent* rigid = getRigidBody();

	rigid->ApplyTorque(THRUST * 1);
}
