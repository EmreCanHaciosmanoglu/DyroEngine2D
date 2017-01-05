#ifndef _BOXCOLLISIONCOMPONENT_H
#define _BOXCOLLISIONCOMPONENT_H

#include "SceneGraph\Objects\Components\Collision\CollisionComponent.h"

class RigidBodyComponent;

class BoxCollisionComponent : public CollisionComponent
{
	/**
	\note Must be present in every subclass definition.
	*/
	OBJECT_STATICS("BoxCollisionComponent")

public:
	BoxCollisionComponent(RigidBodyComponent* rigid, float width, float height, float restitution = 0.5f, float friction = 0.5f, float density = 1.0f, const std::tstring& name = _T(""));
	virtual ~BoxCollisionComponent();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

private:
	float width;
	float height;
};

#endif