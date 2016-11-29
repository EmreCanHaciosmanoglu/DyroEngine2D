#ifndef _PHYSICSOBJECT_H
#define _PHYSICSOBJECT_H

#include "SceneGraph\Object\GameObjects\SceneObject.h"
#include "Interfaces\IDrawableDebugInfo.h"

#ifndef _BODYTYPE_H
	#include "Defines\Types\BodyType.h"
#endif


class RigidBodyComponent;

class PhysicsObject : public SceneObject , public IDrawableDebugInfo
{
public:
	PhysicsObject(BodyType bodyType, const std::tstring& name = _T(""));
	virtual ~PhysicsObject();

	virtual bool initialize();
	virtual void update();
	virtual void draw();
	virtual void drawDebugInfo();
	virtual bool shutdown();

	virtual bool shouldCollide();

	virtual void onCollisionEnter();
	virtual void onCollisionStay();
	virtual void onCollisionLeave();

	virtual void onTriggerEnter();
	virtual void onTriggerStay();
	virtual void onTriggerLeave();

	RigidBodyComponent* getRigidBody() const;

private:

	RigidBodyComponent* rigid;
};

#endif