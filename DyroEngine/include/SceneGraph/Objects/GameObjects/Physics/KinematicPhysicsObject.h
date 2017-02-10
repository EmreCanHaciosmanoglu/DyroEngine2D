#ifndef _KINEMATICPHYSICSOBJECT_H
#define _KINEMATICPHYSICSOBJECT_H

#include "SceneGraph/Objects/GameObjects/Physics/PhysicsObject.h"

class KinematicPhysicsObject : public PhysicsObject
{
	OBJECT_STATICS("KinematicPhysicsObject");
public:
	KinematicPhysicsObject(const std::tstring& name = _T(""))
		:PhysicsObject(BodyType::KINEMATIC)
	{
		OBJECT_INIT(_T("KinematicPhysicsObject"));
	}
	virtual ~KinematicPhysicsObject()
	{}
};

#endif
