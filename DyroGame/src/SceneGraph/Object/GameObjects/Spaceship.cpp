#include "SceneGraph/Object/GameObjects/Spaceship.h"

#include "SceneGraph/Component/ShapeComponent.h"
#include "SceneGraph/Component/RigidBodyComponent.h"
#include "SceneGraph/Component/TransformComponent.h"
#include "SceneGraph/Component/Collision/PolygonCollisionComponent.h"

#include "SceneGraph/Object/Objects/Shapes/PolygonShape.h"

#include "Core/System/Input.h"
#include "Core/System/MainTimer.h"

namespace
{
	const float SPACESHIP_SCALE = 20.0f;

	const float PI = 3.1415f;

	const float FORCE = 200.0f;
	const float TORQUE = 10.0f;
}

Spaceship::Spaceship(const std::tstring& name)
	:PhysicsObject(BodyType::DYNAMIC,name)
	, direction(Vector2D(-1,0))
{}
Spaceship::~Spaceship()
{}

bool Spaceship::initialize()
{
	std::vector<Vector2D> vertices;

	vertices.push_back(Vector2D(-1 * SPACESHIP_SCALE, 0));
	vertices.push_back(Vector2D(1 * SPACESHIP_SCALE, 1 * SPACESHIP_SCALE));
	vertices.push_back(Vector2D(0, 0));
	vertices.push_back(Vector2D(1 * SPACESHIP_SCALE, -1 * SPACESHIP_SCALE));

	addComponent(new ShapeComponent(new PolygonShape(vertices)));
	addComponent(new PolygonCollisionComponent(getRigidBody(),vertices));

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

	b2Vec2 position = rigid->getBody()->GetPosition();
	float angle = rigid->getBody()->GetAngle();

	Vector2D forward;

	forward.x = this->direction.x * cos(angle) - this->direction.y * sin(angle);
	forward.y = this->direction.x * sin(angle) + this->direction.y * cos(angle);

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

	forward.x = this->direction.x * cos(angle) - this->direction.y * sin(angle);
	forward.y = this->direction.x * sin(angle) + this->direction.y * cos(angle);

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
