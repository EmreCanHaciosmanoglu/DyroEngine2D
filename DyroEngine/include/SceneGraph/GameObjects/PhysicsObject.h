#ifndef _PHYSICSOBJECT_H
#define _PHYSICSOBJECT_H

#include "SceneGraph\GameObjects\SceneObject.h"

#ifndef _BODYTYPE_H
#include "Defines\Types\BodyType.h"
#endif

class RigidBodyComponent;

class PhysicsObject : public SceneObject
{
	/**
	\note Must be present in every subclass definition.
	*/
	OBJECT_STATICS("PhysicsObject")

public:
	PhysicsObject(BodyType bodyType, const std::tstring& name = _T(""));
	virtual ~PhysicsObject();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	void setCollisionLayer(unsigned int layer);

	virtual bool shouldCollide(PhysicsObject* other);

	virtual void onCollisionEnter(PhysicsObject* other);
	virtual void onCollisionStay(PhysicsObject* other);
	virtual void onCollisionLeave(PhysicsObject* other);

	virtual void onTriggerEnter(PhysicsObject* other);
	virtual void onTriggerStay(PhysicsObject* other);
	virtual void onTriggerLeave(PhysicsObject* other);

	RigidBodyComponent* getRigidBody() const;

private:

	RigidBodyComponent* rigid;
};

#endif