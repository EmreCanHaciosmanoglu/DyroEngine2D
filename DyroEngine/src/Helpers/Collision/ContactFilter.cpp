#include "Helpers\Collision\ContactFilter.h"

ContactFilter::ContactFilter()
{}
ContactFilter::~ContactFilter()
{}

bool ContactFilter::ShouldCollide(b2Fixture* fixtureA, b2Fixture* fixtureB)
{
	return true;
}