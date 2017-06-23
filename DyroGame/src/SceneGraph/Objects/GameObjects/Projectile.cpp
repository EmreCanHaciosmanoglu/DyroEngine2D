#include "SceneGraph\Objects\GameObjects\Projectile.h"
#include "SceneGraph\Objects\Components\Physics\RigidBodyComponent.h"

Projectile::Projectile(const std::tstring& name)
	:PhysicsObject(BodyType::DYNAMIC, name)
{
	OBJECT_INIT(_T("Projectile"));
}
Projectile::~Projectile()
{}

void Projectile::launch(const Vector2D& direction, float force)
{
	getRigidBody()->ApplyForce(direction * force);
}