#include "SceneGraph/Object/GameObjects/Obstacle.h"

#include "SceneGraph/Component/Collision/CollisionComponent.h"
#include "SceneGraph/Component/Collision/BoxCollisionComponent.h"

#include "SceneGraph/Component/ShapeComponent.h"
#include "SceneGraph/Component/ImageComponent.h"

Obstacle::Obstacle(BodyType bodyType, const std::tstring& name)
	:PhysicsObject(bodyType, name)
	,collider(nullptr)
{
	Rect2D bounding_rect = getBoundingBox();

	this->collider = new BoxCollisionComponent(getRigidBody(), bounding_rect.right - bounding_rect.left, bounding_rect.bottom = bounding_rect.top);
}
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
void Obstacle::draw()
{
	PhysicsObject::draw();
}
bool Obstacle::shutdown()
{
	return PhysicsObject::shutdown();
}

void Obstacle::setVisible(bool visible)
{
	setCanDraw(visible);
}
bool Obstacle::getVisible() const
{
	return getCanDraw();
}

void Obstacle::setCollision(CollisionComponent* collider)
{
	if (this->collider != nullptr)
		removeComponent(this->collider);

	this->collider = collider;
}
CollisionComponent* Obstacle::getCollider() const
{
	return this->collider;
}