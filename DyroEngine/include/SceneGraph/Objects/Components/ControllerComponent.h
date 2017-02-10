#ifndef _CONTROLLERCOMPONENT_H
#define _CONTROLLERCOMPONENT_H

#include "SceneGraph\Objects\Components\Component.h"

class ControllerComponent : public Component
{
public:
	ControllerComponent(const std::tstring& name = _T("ControllerComponent"));
	virtual ~ControllerComponent();

	virtual bool initialize();
	virtual void update();
	virtual bool shutdown();

	void setHorizontalForce(float force);
	void setVerticalForce(float force);
	void setRotationForce(float force);

	float getHorizontalForce() const;
	float getVerticalForce() const;
	float getRotationForce() const;

private:
	float horizontal_force;
	float vertical_force;
	float rotation_force;
};

#endif