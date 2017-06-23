#include "SceneGraph\Objects\GameObjects\Spaceship.h"

#include "SceneGraph\Objects\Components\Shapes\PolygonShapeComponent.h"
#include "SceneGraph\Objects\Components\Physics\Collision\PolygonCollisionComponent.h"
#include "SceneGraph\Objects\Components\TransformComponent.h"
#include "SceneGraph\Objects\Components\Physics\RigidBodyComponent.h"

#include "SceneGraph\Objects\Components\SpaceshipPlayerControllerComponent.h"
#include "SceneGraph\Objects\Components\SpaceshipWeaponComponent.h"

#include "Core/Data/Objects/Descriptions/Shapes/PolygonShapeDescription.h"

#include "Core/System/Objects/Input.h"

namespace
{
	const float SPACESHIP_X_SCALE = 15.0f;
	const float SPACESHIP_Y_SCALE = 15.0f;
}

SpaceShip::SpaceShip()
	:PhysicsObject(BodyType::DYNAMIC, _T("SpaceShip"))
	, controller(nullptr)
	, weapon(nullptr)
{
	OBJECT_INIT(_T("Spaceship"));

	getRigidBody()->setAngularDamping(0.25f);
	getRigidBody()->setLinearDamping(0.25f);
}
SpaceShip::~SpaceShip()
{}

bool SpaceShip::initialize()
{
	this->controller = new SpaceshipPlayerControllerComponent();
	this->weapon = new SpaceshipWeaponComponent();

	PolygonShapeDescription* description = new PolygonShapeDescription();

	std::vector<Vector2D> points;
	points.push_back(Vector2D(0.0f * SPACESHIP_X_SCALE, -1.0f * SPACESHIP_Y_SCALE));
	points.push_back(Vector2D(1.0f * SPACESHIP_X_SCALE, 1.0f * SPACESHIP_Y_SCALE));
	points.push_back(Vector2D(0.0f * SPACESHIP_X_SCALE, 0.5f * SPACESHIP_Y_SCALE));
	points.push_back(Vector2D(-1.0f * SPACESHIP_X_SCALE, 1.0f * SPACESHIP_Y_SCALE));

	description->setPoints(points);
	description->setColor(Color(1.0f, 0.0f, 0.0f));
	description->setFill(true);

	PolygonShapeComponent* shape_component = new PolygonShapeComponent(description);
	PolygonCollisionComponent* collision_component = new PolygonCollisionComponent(getRigidBody(), points);

	addComponent(this->controller);
	addComponent(this->weapon);
	addComponent(shape_component);
	addComponent(collision_component);

	return PhysicsObject::initialize();
}

void SpaceShip::setupInput(Input* input)
{
	input->bindKey(KeyBinding('W', std::bind(&SpaceshipPlayerControllerComponent::moveForward, this->controller), InputStateType::DOWN));
	input->bindKey(KeyBinding('A', std::bind(&SpaceshipPlayerControllerComponent::rotateLeft, this->controller), InputStateType::DOWN));
	input->bindKey(KeyBinding('S', std::bind(&SpaceshipPlayerControllerComponent::moveBackward, this->controller), InputStateType::DOWN));
	input->bindKey(KeyBinding('D', std::bind(&SpaceshipPlayerControllerComponent::rotateRight, this->controller), InputStateType::DOWN));

	input->bindKey(KeyBinding(VK_SPACE, std::bind(&SpaceshipPlayerControllerComponent::startFire, this->controller), InputStateType::DOWN));
	input->bindKey(KeyBinding(VK_SPACE, std::bind(&SpaceshipPlayerControllerComponent::stopFire, this->controller), InputStateType::RELEASD));
}