#include "Physics/Collision\ContactFilter.h"

#include "SceneGraph/Objects/GameObjects/PhysicsObject.h"

ContactFilter::ContactFilter()
{}
ContactFilter::~ContactFilter()
{}

bool ContactFilter::ShouldCollide(b2Fixture* fixtureA, b2Fixture* fixtureB)
{
	//Don't collide with yourself!
	if (fixtureA == fixtureB)
		return false;

	if (fixtureA->GetUserData() != nullptr && fixtureB->GetUserData() != nullptr)
	{
		if (fixtureA->GetBody()->GetUserData() != nullptr && fixtureB->GetBody()->GetUserData() != nullptr)
		{
			PhysicsObject* object_a = reinterpret_cast<PhysicsObject*>(fixtureA->GetBody()->GetUserData());
			PhysicsObject* object_b = reinterpret_cast<PhysicsObject*>(fixtureB->GetBody()->GetUserData());

			return object_a->shouldCollide(object_b);
		}
	}

	return false;
}