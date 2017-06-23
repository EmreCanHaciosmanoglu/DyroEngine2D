#include "SceneGraph\Objects\Components\SpaceshipPlayerControllerComponent.h"
#include "SceneGraph\Objects\Components\Physics\RigidBodyComponent.h"
#include "SceneGraph\Objects\Components\TransformComponent.h"
#include "SceneGraph\Objects\Components\SpaceshipWeaponComponent.h"

#include "SceneGraph\Objects\GameObjects\GameObject.h"

#include "Core\Data\Objects\Timers\WorldTimer.h"

SpaceshipPlayerControllerComponent::SpaceshipPlayerControllerComponent()
	:PlayerControllerComponent(_T("SpaceshipPlayerControllerComponent"))
{
	OBJECT_INIT(_T("SpaceshipPlayerControllerComponent"));
}
SpaceshipPlayerControllerComponent::~SpaceshipPlayerControllerComponent()
{}

bool SpaceshipPlayerControllerComponent::initialize()
{
	setHorizontalForce(50.0f);
	setVerticalForce(200.0f);

	setRotationForce(1.5f);

	return PlayerControllerComponent::initialize();
}

void SpaceshipPlayerControllerComponent::startFire()
{
	SpaceshipWeaponComponent* weapon = getParent()->getComponent<SpaceshipWeaponComponent>();
	if (!weapon)
		return;

	weapon->startFire();
}
void SpaceshipPlayerControllerComponent::stopFire()
{
	SpaceshipWeaponComponent* weapon = getParent()->getComponent<SpaceshipWeaponComponent>();
	if (!weapon)
		return;

	weapon->stopFire();
}

void SpaceshipPlayerControllerComponent::moveForward()
{
	float v = getVerticalForce();

	RigidBodyComponent* rigid = getParent()->getComponent<RigidBodyComponent>();
	if (rigid == nullptr)
		return;
	TransformComponent* transform = getParent()->getComponent<TransformComponent>();
	if (transform == nullptr)
		return;

	//We need the negative forward since our forward is pointing up instead of pointing down
	rigid->ApplyForce(-transform->getForward() * v);
}
void SpaceshipPlayerControllerComponent::moveBackward()
{
	float v = getVerticalForce();

	RigidBodyComponent* rigid = getParent()->getComponent<RigidBodyComponent>();
	if (rigid == nullptr)
		return;
	TransformComponent* transform = getParent()->getComponent<TransformComponent>();
	if (transform == nullptr)
		return;

	float rotation = transform->getRotation();
	Matrix2D rot_mat = Matrix2D::createRotationMatrix(rotation);
	Vector2D transform_vector = rot_mat.transformVector(Vector2D(0, 1));

	rigid->ApplyForce(transform_vector * v);
}
void SpaceshipPlayerControllerComponent::rotateLeft()
{
	float r = getRotationForce();

	RigidBodyComponent* rigid = getParent()->getComponent<RigidBodyComponent>();
	if (rigid == nullptr)
		return;

	rigid->ApplyTorque(-r);
}
void SpaceshipPlayerControllerComponent::rotateRight()
{
	float r = getRotationForce();

	RigidBodyComponent* rigid = getParent()->getComponent<RigidBodyComponent>();
	if (rigid == nullptr)
		return;

	rigid->ApplyTorque(r);
}