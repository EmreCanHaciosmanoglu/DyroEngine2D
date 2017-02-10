#include "SceneGraph\Objects\GameObjects\Projectile.h"
#include "SceneGraph\Objects\Components\Physics\RigidBodyComponent.h"

Projectile::Projectile(float force, const std::tstring& name)
	:PhysicsObject(BodyType::DYNAMIC, name)
	, launch_force(force)
{
	OBJECT_INIT(_T("Projectile"));
}
Projectile::~Projectile()
{}

void Projectile::launch(const Vector2D& direction)
{
	getRigidBody()->ApplyForce(direction * this->launch_force);
}