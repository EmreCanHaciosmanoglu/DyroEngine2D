#ifndef _CAMERACOMPONENT_H
#define _CAMERACOMPONENT_H

#include "SceneGraph\Component\Component.h"

#include "Helpers\Math\Matrix2D.h"

class TransformComponent;

class CameraComponent : public Component
{
public:
	CameraComponent(const std::tstring& name = _T(""));
	virtual ~CameraComponent();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	const Matrix2D getViewMatrix() const;

private:
	TransformComponent* transform;
};

#endif