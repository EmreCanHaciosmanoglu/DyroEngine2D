#ifndef _CONTACTFILTER_H
#define _CONTACTFILTER_H

#include <Box2D\Box2D.h>

class ContactFilter : public b2ContactFilter
{
public:
	ContactFilter();
	virtual ~ContactFilter();

	ContactFilter(const ContactFilter&) = delete;
	ContactFilter& operator=(const ContactFilter&) = delete;

	/// Return true if contact calculations should be performed between these two shapes.
	/// @warning for performance reasons this is only called when the AABBs begin to overlap.
	virtual bool ShouldCollide(b2Fixture* fixtureA, b2Fixture* fixtureB);
};

#endif