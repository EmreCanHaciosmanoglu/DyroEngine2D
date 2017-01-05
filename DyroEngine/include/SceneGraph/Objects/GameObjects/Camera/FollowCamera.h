#ifndef _FOLLOWCAMERA_H
#define _FOLLOWCAMERA_H

#include "SceneGraph/Objects/GameObjects/Camera/Camera.h"

class SceneObject;

class FollowCamera : public Camera
{
	/**
	\note Must be present in every subclass definition.
	*/
	OBJECT_STATICS("FollowCamera")

public:
	FollowCamera(SceneObject* target, const std::tstring& name = _T(""), float damping = 0.0f);
	virtual ~FollowCamera();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	void setTarget(SceneObject* target);
	SceneObject* getTarget() const;

	void setDamping(float damping);
	float getDamping() const;

private:
	SceneObject* target;
	float damping;
};

#endif