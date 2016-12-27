#ifndef _FREECAMERA_H
#define _FREECAMERA_H

#include "SceneGraph\GameObjects\Camera\Camera.h"

class Input;

class FreeCamera : public Camera
{
public:
	FreeCamera(const std::tstring& name = _T(""), float speed = 50.0f);
	virtual ~FreeCamera();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	virtual void setupInput(Input* input);

	void setSpeed(float speed);
	float getSpeed() const;

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

private:
	float speed;
};

#endif
