#include "SceneGraph/GameObjects/Obstacle.h"

Obstacle::Obstacle(BodyType bodyType, const std::tstring& name)
	:PhysicsObject(bodyType, name)
{}
Obstacle::~Obstacle()
{}

bool Obstacle::initialize()
{
	return PhysicsObject::initialize();
}
void Obstacle::update()
{
	PhysicsObject::update();
}
bool Obstacle::shutdown()
{
	return PhysicsObject::shutdown();
}

void Obstacle::setVisible(bool visible)
{
}
bool Obstacle::getVisible() const
{
	return true;
}