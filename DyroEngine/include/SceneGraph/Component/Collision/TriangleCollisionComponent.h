#ifndef _TRIANGLECOLLISIONCOMPONENT_H
#define _TRIANGLECOLLISIONCOMPONENT_H

#include "SceneGraph\Component\Collision\PolygonCollisionComponent.h"

class TriangleCollisionComponent : public PolygonCollisionComponent
{
	/**
	\note Must be present in every subclass definition.
	*/
	OBJECT_STATICS("TriangleCollisionComponent")

public:
	TriangleCollisionComponent(RigidBodyComponent* rigid, float xScale, float yScale, float restitution = 0.5f, float friction = 0.5f, float density = 1.0f, const std::tstring& name = _T(""));
	virtual ~TriangleCollisionComponent();
};

#endif