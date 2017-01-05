#ifndef _CAMERA_H
#define _CAMERA_H

#include "SceneGraph\Objects\GameObjects\GameObject.h"

class CameraComponent;
class TransformComponent;

class Camera : public GameObject
{
	/**
	\note Must be present in every subclass definition.
	*/
	OBJECT_STATICS("Camera")

public:
	Camera(const std::tstring& name = _T(""), bool setActive = true);
	virtual ~Camera();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	CameraComponent* getCamera() const;
	TransformComponent* getTransform() const;

private:
	CameraComponent* camera;
	TransformComponent* transform;
};

#endif
