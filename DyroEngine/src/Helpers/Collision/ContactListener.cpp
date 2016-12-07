#include "Helpers\Collision\ContactListener.h"

#include "SceneGraph/Object/GameObjects/PhysicsObject.h"

#include "SceneGraph/Component/RigidBodyComponent.h"
#include "SceneGraph/Component/Collision/CollisionComponent.h"

//#include "Helpers/Singleton.h"
//#include "Diagnostics/Logger.h"

ContactListener::ContactListener()
{}
ContactListener::~ContactListener()
{}

void ContactListener::update()
{
	for (ContactData& data : this->vec_triggers)
	{
		data.object_a->onTriggerStay(data.object_b);
		data.object_b->onTriggerStay(data.object_a);
	}
	for (ContactData& data : this->vec_colliders)
	{
		data.object_a->onCollisionStay(data.object_b);
		data.object_b->onCollisionStay(data.object_a);
	}
}

void ContactListener::BeginContact(b2Contact* contact)
{
	b2Fixture* fixture_a = contact->GetFixtureA();
	b2Fixture* fixture_b = contact->GetFixtureB();

	if (fixture_a->GetUserData() != nullptr && fixture_b->GetUserData() != nullptr)
	{
		if (fixture_a->GetBody()->GetUserData() != nullptr && fixture_b->GetBody()->GetUserData() != nullptr)
		{
			PhysicsObject* object_a = reinterpret_cast<PhysicsObject*>(fixture_a->GetBody()->GetUserData());
			PhysicsObject* object_b = reinterpret_cast<PhysicsObject*>(fixture_b->GetBody()->GetUserData());

			CollisionComponent* collider_a = reinterpret_cast<CollisionComponent*>(fixture_a->GetUserData());
			CollisionComponent* collider_b = reinterpret_cast<CollisionComponent*>(fixture_b->GetUserData());

			computeBeginContact(collider_a, collider_b, fixture_a, fixture_b, object_a, object_b);
			computeBeginContact(collider_b, collider_a, fixture_b, fixture_a, object_b, object_a);
		}
	}
}
void ContactListener::EndContact(b2Contact* contact)
{
	b2Fixture* fixture_a = contact->GetFixtureA();
	b2Fixture* fixture_b = contact->GetFixtureB();

	if (fixture_a->GetUserData() != nullptr && fixture_b->GetUserData() != nullptr)
	{
		if (fixture_a->GetBody()->GetUserData() != nullptr && fixture_b->GetBody()->GetUserData() != nullptr)
		{
			PhysicsObject* object_a = reinterpret_cast<PhysicsObject*>(fixture_a->GetBody()->GetUserData());
			PhysicsObject* object_b = reinterpret_cast<PhysicsObject*>(fixture_b->GetBody()->GetUserData());

			CollisionComponent* collider_a = reinterpret_cast<CollisionComponent*>(fixture_a->GetUserData());
			CollisionComponent* collider_b = reinterpret_cast<CollisionComponent*>(fixture_b->GetUserData());

			computeEndContact(collider_a, collider_b, fixture_a, fixture_b, object_a, object_b);
			computeEndContact(collider_b, collider_a, fixture_b, fixture_a, object_b, object_a);
		}
	}
}

void ContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
	/// This allows you to inspect a contact before it goes to the solver.
}
void ContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{
	/// This allows you to inspect a contact after the solver is finished. 
}

void ContactListener::computeBeginContact(CollisionComponent* colliderA, CollisionComponent* colliderB, b2Fixture* fixtureA, b2Fixture* fixtureB, PhysicsObject* objectA, PhysicsObject* objectB)
{
	if (colliderA->getIsTrigger())
	{
		if (this->vec_triggers.size() == 0)
			return;

		this->vec_triggers.push_back(ContactData(objectA,objectB,colliderA,colliderB));

		objectA->onTriggerEnter(objectB);
	}
	else
	{
		if (this->vec_colliders.size() == 0)
			return;

		this->vec_colliders.push_back(ContactData(objectA, objectB, colliderA, colliderB));

		objectA->onCollisionEnter(objectB);

		//Singleton<Logger>::getInstance().log(_T("Collision enter: ") + objectA->getName() + _T(" ") + objectB->getName(), LOGTYPE_INFO);
	}
}
void ContactListener::computeEndContact(CollisionComponent* colliderA, CollisionComponent* colliderB, b2Fixture* fixtureA, b2Fixture* fixtureB, PhysicsObject* objectA, PhysicsObject* objectB)
{
	if (colliderA->getIsTrigger())
	{
		if (this->vec_triggers.size() == 0)
			return;

		this->vec_triggers.erase(std::find(this->vec_triggers.begin(),this->vec_triggers.end(), ContactData(objectA, objectB, colliderA, colliderB)));

		objectA->onTriggerLeave(objectB);
	}
	else
	{
		if (this->vec_colliders.size() == 0)
			return;

		this->vec_colliders.erase(std::find(this->vec_colliders.begin(),this->vec_colliders.end(), ContactData(objectA, objectB, colliderA, colliderB)));

		objectA->onCollisionLeave(objectB);

		//Singleton<Logger>::getInstance().log(_T("Collision leave: ") + objectA->getName() + _T(" ") + objectB->getName(), LOGTYPE_INFO);
	}
}