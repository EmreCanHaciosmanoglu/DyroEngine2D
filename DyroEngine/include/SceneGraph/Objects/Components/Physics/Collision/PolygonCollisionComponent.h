#ifndef _POLYGONCOLLISIONCOMPONENT_H
#define _POLYGONCOLLISIONCOMPONENT_H

#include "SceneGraph\Objects\Components\Physics\Collision\CollisionComponent.h"

#ifndef _VECTOR2D_H
#include "Math/Objects/Vector2D.h"
#endif

#ifndef _VECTOR_
#include <vector>
#endif

class RigidBodyComponent;

class PolygonCollisionComponent : public CollisionComponent
{
	/**
	\note Must be present in every subclass definition.
	*/
	OBJECT_STATICS("PolygonCollisionComponent")

public:
	PolygonCollisionComponent(RigidBodyComponent* rigid, std::vector<Vector2D> vertices, float restitution = 0.5f, float friction = 0.5f, float density = 1.0f, const std::tstring& name = _T(""));
	virtual ~PolygonCollisionComponent();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

private:
	std::vector<Vector2D> vertices;
};

#endif