#ifndef _BOXCOLLISIONCOMPONENT_H
#define _BOXCOLLISIONCOMPONENT_H

#include "SceneGraph\Objects\Components\Physics\Collision\CollisionComponent.h"

class RigidBodyComponent;

class RectCollisionComponent : public CollisionComponent
{
	/**
	\note Must be present in every subclass definition.
	*/
	OBJECT_STATICS("RectCollisionComponent")

public:
	RectCollisionComponent(RigidBodyComponent* rigid, float width, float height, float restitution = 0.5f, float friction = 0.5f, float density = 1.0f, const std::tstring& name = _T(""));
	virtual ~RectCollisionComponent();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

private:
	float width;
	float height;
};

#endif