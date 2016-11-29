#include "SceneGraph\Object\GameObjects\PhysicsObject.h"

#include "SceneGraph\Component\RigidBodyComponent.h"
#include "SceneGraph\Component\TransformComponent.h"

#include "SceneGraph\Scene\Scene.h"

PhysicsObject::PhysicsObject(BodyType bodyType, const std::tstring& name)
	:SceneObject(name)
	,rigid(new RigidBodyComponent(bodyType))
{
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
void PhysicsObject::draw()
{
	SceneObject::draw();
}
void PhysicsObject::drawDebugInfo()
{

}
bool PhysicsObject::shutdown()
{
	return SceneObject::shutdown();
}

bool PhysicsObject::shouldCollide() { return true; }

void PhysicsObject::onCollisionEnter(){}
void PhysicsObject::onCollisionStay(){}
void PhysicsObject::onCollisionLeave(){}

void PhysicsObject::onTriggerEnter(){}
void PhysicsObject::onTriggerStay(){}
void PhysicsObject::onTriggerLeave(){}

RigidBodyComponent* PhysicsObject::getRigidBody() const
{
	return this->rigid;
}