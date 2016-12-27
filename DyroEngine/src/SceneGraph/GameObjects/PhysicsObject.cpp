#include "SceneGraph\GameObjects\PhysicsObject.h"

#include "SceneGraph\Component\RigidBodyComponent.h"
#include "SceneGraph\Component\TransformComponent.h"

#include "SceneGraph\Scene\Scene.h"

PhysicsObject::PhysicsObject(BodyType bodyType, const std::tstring& name)
	:SceneObject(name)
	, rigid(new RigidBodyComponent(bodyType))
{
	OBJECT_INIT(_T("PhysicsObject"));

	addComponent(this->rigid);
}
PhysicsObject::~PhysicsObject()
{}

bool PhysicsObject::initialize()
{
	return SceneObject::initialize();
}
void PhysicsObject::update()
{
	SceneObject::update();
}
bool PhysicsObject::shutdown()
{
	return SceneObject::shutdown();
}

bool PhysicsObject::shouldCollide(PhysicsObject* other)
{
	return true;
}

void PhysicsObject::onCollisionEnter(PhysicsObject* other)
{
}
void PhysicsObject::onCollisionStay(PhysicsObject* other)
{
}
void PhysicsObject::onCollisionLeave(PhysicsObject* other)
{
}

void PhysicsObject::onTriggerEnter(PhysicsObject* other)
{
}
void PhysicsObject::onTriggerStay(PhysicsObject* other)
{
}
void PhysicsObject::onTriggerLeave(PhysicsObject* other)
{
}

RigidBodyComponent* PhysicsObject::getRigidBody() const
{
	return this->rigid;
}