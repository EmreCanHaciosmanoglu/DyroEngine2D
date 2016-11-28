#ifndef _CIRCLECOLLISIONCOMPONENT_H
#define _CIRCLECOLLISIONCOMPONENT_H

#include "SceneGraph\Component\Collision\CollisionComponent.h"

class RigidBodyComponent;

class CircleCollisionComponent : public CollisionComponent
{
public:
	CircleCollisionComponent(RigidBodyComponent* rigid, float radius, float restitution = 0.5f, float friction = 0.5f, float density = 1.0f, const std::tstring& name = _T(""));
	virtual ~CircleCollisionComponent();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

private:
	float radius;
};

#endif