#include "SceneGraph\Objects\Components\ControllerComponent.h"

ControllerComponent::ControllerComponent(const std::tstring& name)
	:Component(name)
	, horizontal_force(50.0f)
	, vertical_force(50.0f)
	, rotation_force(10.0f)
{
	OBJECT_INIT(_T("ControllerComponent"));
	setExecutionOrder(400);
}
ControllerComponent::~ControllerComponent()
{}

bool ControllerComponent::initialize()
{
	return true;
}
void ControllerComponent::update()
{}
bool ControllerComponent::shutdown()
{
	return true;
}

void ControllerComponent::setHorizontalForce(float force)
{
	this->horizontal_force = force;
}
void ControllerComponent::setVerticalForce(float force)
{
	this->vertical_force = force;
}
void ControllerComponent::setRotationForce(float force)
{
	this->rotation_force = force;
}

float ControllerComponent::getHorizontalForce() const
{
	return this->horizontal_force;
}
float ControllerComponent::getVerticalForce() const
{
	return this->vertical_force;
}
float ControllerComponent::getRotationForce() const
{
	return this->rotation_force;
}

