#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "SceneGraph\Objects\GameObjects\Physics\PhysicsObject.h"

#ifndef _VECTOR2D_H
#include "Math/Objects/Vector2D.h"
#endif

class Projectile : public PhysicsObject
{
	OBJECT_STATICS("Projectile");
public:
	Projectile(const std::tstring& name = _T("Projectile"));
	virtual ~Projectile();

	void launch(const Vector2D& direction, float force);
};

#endif
