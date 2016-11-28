#ifndef _COLLISIONCOMPONENT_H
#define _COLLISIONCOMPONENT_H

#include "SceneGraph\Component\Component.h"

class b2Fixture;
class RigidBodyComponent;

class CollisionComponent : public Component
{
public:
	CollisionComponent(RigidBodyComponent* rigid, float restitution = 0.5f, float friction = 0.5f, float density = 1.0f, const std::tstring& name = _T(""));
	virtual ~CollisionComponent();

	virtual bool initialize() = 0;
	virtual void update() = 0;
	virtual bool shutdown() = 0;

	void isTrigger(bool trigger);

protected:
	void setAsTrigger(b2Fixture* fixture);

	float getRestitution() const;
	float getFriction() const;
	float getDensity() const;

	RigidBodyComponent* getRigid() const;

private:
	float restitution;
	float friction;
	float density;

	bool is_trigger;

	RigidBodyComponent* rigid;
};

#endif