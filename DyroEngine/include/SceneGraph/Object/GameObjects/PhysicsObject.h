#ifndef _PHYSICSOBJECT_H
#define _PHYSICSOBJECT_H

#include "SceneGraph\Object\GameObjects\SceneObject.h"
#ifndef _IDRAWABLEDEBUGINFO_H
#include "Interfaces\IDrawableDebugInfo.h"
#endif

#ifndef _BODYTYPE_H
#include "Defines\Types\BodyType.h"
#endif

class RigidBodyComponent;

class PhysicsObject : public SceneObject, public IDrawableDebugInfo
{
public:
	PhysicsObject(BodyType bodyType, const std::tstring& name = _T(""));
	virtual ~PhysicsObject();

	virtual bool initialize();
	virtual void update();
	virtual void draw();
	virtual void drawDebugInfo();
	virtual bool shutdown();

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