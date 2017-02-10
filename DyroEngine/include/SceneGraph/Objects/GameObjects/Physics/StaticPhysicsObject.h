#ifndef _STATICPHYSICSOBJECT_H
#define _STATICPHYSICSOBJECT_H

#include "SceneGraph/Objects/GameObjects/Physics/PhysicsObject.h"

class StaticPhysicsObject : public PhysicsObject
{
	OBJECT_STATICS("StaticPhysicsObject");
public:
	StaticPhysicsObject(const std::tstring& name = _T(""))
		:PhysicsObject(BodyType::STATIC)
	{
		OBJECT_INIT(_T("StaticPhysicsObject"));
	}
	virtual ~StaticPhysicsObject()
	{}

};

#endif

