#include "SceneGraph/GameObjects/Spaceship.h"

#include "SceneGraph/Component/ShapeComponent.h"
#include "SceneGraph/Component/RigidBodyComponent.h"
#include "SceneGraph/Component/TransformComponent.h"
#include "SceneGraph/Component/Collision/PolygonCollisionComponent.h"

#include "Core/Data/DataObjects/Shapes/PolygonShape.h"

#include "Core/System/Input.h"
#include "Core/System/MainTimer.h"

#include "Defines\programdefaults.h"

namespace
{
	const float SPACESHIP_SCALE = 50.0f;

	const float FORCE = 500.0f;
	const float TORQUE = 20.0f;

	const float LINEAR_DAMPING = 0.2f;
	const float ANGULAR_DAMPING = 0.4f;
}

Spaceship::Spaceship(const std::tstring& name)
	:PhysicsObject(BodyType::DYNAMIC,name)
{}
Spaceship::~Spaceship()
{}

bool Spaceship::initialize()
{
	std::vector<Vector2D> vertices;

	vertices.push_back(Vector2D(-0.5f * SPACESHIP_SCALE, 0.0f));
	vertices.push_back(Vector2D(0.5f * SPACESHIP_SCALE, -0.5f * SPACESHIP_SCALE));
	vertices.push_back(Vector2D(0.25f * SPACESHIP_SCALE, 0.0f));
	vertices.push_back(Vector2D(0.5f * SPACESHIP_SCALE, 0.5f * SPACESHIP_SCALE));

	addComponent(new ShapeComponent(new PolygonShape(vertices)));
	addComponent(new PolygonCollisionComponent(getRigidBody(),vertices));

	getRigidBody()->setGravityScale(0.0f);

	getRigidBody()->setLinearDamping(LINEAR_DAMPING);
	getRigidBody()->setAngularDamping(ANGULAR_DAMPING);

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

	b2Vec2 position = rigid->getBody()->GetPosition();
	float angle = rigid->getBody()->GetAngle();

	Vector2D forward;
	Vector2D direction = Vector2D(-1, 0);

	forward.x = direction.x * cos(angle) - direction.y * sin(angle);
	forward.y = direction.x * sin(angle) + direction.y * cos(angle);

	direction.Normalize();

	Vector2D force = forward * FORCE * 1;

	rigid->ApplyForce(force);
}
void Spaceship::moveBackward()
{
	RigidBodyComponent* rigid = getRigidBody();

	b2Vec2 position = rigid->getBody()->GetPosition();
	float angle = rigid->getBody()->GetAngle();

	Vector2D forward;
	Vector2D direction = Vector2D(-1, 0);

	forward.x = direction.x * cos(angle) - direction.y * sin(angle);
	forward.y = direction.x * sin(angle) + direction.y * cos(angle);

	direction.Normalize();

	Vector2D force = forward * FORCE * -1;

	rigid->ApplyForce(force);
}
void Spaceship::rotateRight()
{
	RigidBodyComponent* rigid = getRigidBody();

	float direction = 1;
	float torque = TORQUE * direction;

	rigid->ApplyTorque(torque);
}
void Spaceship::rotateLeft()
{
	RigidBodyComponent* rigid = getRigidBody();

	float direction = -1;
	float torque = TORQUE * direction;

	rigid->ApplyTorque(torque);
}
