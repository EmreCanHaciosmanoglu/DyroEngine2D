#ifndef _DYNAMICPHYSICSOBJECT_H
#define _DYNAMICPHYSICSOBJECT_H

#include "SceneGraph/Objects/GameObjects/Physics/PhysicsObject.h"

class DynamicPhysicsObject : public PhysicsObject
{
	OBJECT_STATICS("DynamicPhysicsObject");
public:
	DynamicPhysicsObject(const std::tstring& name = _T(""))
		:PhysicsObject(BodyType::DYNAMIC)
	{
		DynamicPhysicsObject(_T("KinematicPhysicsObject"));
	}
	virtual ~DynamicPhysicsObject()
	{}

};

#endif

