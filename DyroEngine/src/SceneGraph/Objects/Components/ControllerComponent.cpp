#include "SceneGraph\Objects\Components\ControllerComponent.h"

ControllerComponent::ControllerComponent(const std::tstring& name)
	:Component(name)
	, speed(50.0f)
{}
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

void ControllerComponent::setSpeed(float speed)
{
	this->speed = speed;
}

float ControllerComponent::getSpeed()
{
	return this->speed;
}

